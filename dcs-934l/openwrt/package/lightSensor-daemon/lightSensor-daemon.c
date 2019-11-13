/* lightSensor-daemon for DCS-932L by Andreas Boehler <andreas _AT_ aboehler.at>
 * Copyright (c) 2014, Andreas Boehler
 * based on GPIO example,
 * Copyright (c) 2011, RidgeRun
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 3. All advertising materials mentioning features or use of this software
 *    must display the following acknowledgement:
 *    This product includes software developed by the RidgeRun.
 * 4. Neither the name of the RidgeRun nor the
 *    names of its contributors may be used to endorse or promote products
 *    derived from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY RIDGERUN ''AS IS'' AND ANY
 * EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL RIDGERUN BE LIABLE FOR ANY
 * DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
 * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <fcntl.h>
#include <poll.h>
#include <syslog.h>
#include <signal.h>

// Declare some constants

#define SYSFS_GPIO_DIR "/sys/class/gpio"
#define POLL_TIMEOUT (3 * 1000) /* 3 seconds */
#define MAX_BUF 64
#define GPIO_LIGHT 11
#define GPIO_IR_PIN1 12
#define GPIO_IR_PIN2 14

int gpio_export(unsigned int gpio)
{
  int fd, len;
  char buf[MAX_BUF];

  fd = open(SYSFS_GPIO_DIR "/export", O_WRONLY);
  if (fd < 0) {
    syslog(LOG_ERR, "gpio/export failed: %i", gpio);
    perror("gpio/export");
    return fd;
  }

  len = snprintf(buf, sizeof(buf), "%d", gpio);
  write(fd, buf, len);
  close(fd);

  return 0;
}

int gpio_unexport(unsigned int gpio)
{
  int fd, len;
  char buf[MAX_BUF];

  fd = open(SYSFS_GPIO_DIR "/unexport", O_WRONLY);
  if (fd < 0) {
    syslog(LOG_ERR, "gpio/unexport failed: %i", gpio);
    perror("gpio/export");
    return fd;
  }

  len = snprintf(buf, sizeof(buf), "%d", gpio);
  write(fd, buf, len);
  close(fd);
  return 0;
}

int gpio_set_dir(unsigned int gpio, unsigned int out_flag)
{
  int fd, len;
  char buf[MAX_BUF];

  len = snprintf(buf, sizeof(buf), SYSFS_GPIO_DIR  "/gpio%d/direction", gpio);

  fd = open(buf, O_WRONLY);
  if (fd < 0) {
    syslog(LOG_ERR, "gpio/direction failed: %i", gpio);
    perror("gpio/direction");
    return fd;
  }

  if (out_flag)
    write(fd, "out", 4);
  else
    write(fd, "in", 3);

  close(fd);
  return 0;
}

int gpio_set_value(unsigned int gpio, unsigned int value)
{
  int fd, len;
  char buf[MAX_BUF];

  len = snprintf(buf, sizeof(buf), SYSFS_GPIO_DIR "/gpio%d/value", gpio);

  fd = open(buf, O_WRONLY);
  if (fd < 0) {
    syslog(LOG_ERR, "gpio/set-value failed: %i", gpio);
    perror("gpio/set-value");
    return fd;
  }

  if (value)
    write(fd, "1", 2);
  else
    write(fd, "0", 2);

  close(fd);
  return 0;
}

int gpio_get_value(unsigned int gpio, unsigned int *value)
{
  int fd, len;
  char buf[MAX_BUF];
  char ch;

  len = snprintf(buf, sizeof(buf), SYSFS_GPIO_DIR "/gpio%d/value", gpio);

  fd = open(buf, O_RDONLY);
  if (fd < 0) {
    syslog(LOG_ERR, "gpio/get-value failed: %i", gpio);
    perror("gpio/get-value");
    return fd;
  }

  read(fd, &ch, 1);

  if (ch != '0') {
    *value = 1;
  } else {
    *value = 0;
  }

  close(fd);
  return 0;
}

int gpio_set_edge(unsigned int gpio, char *edge)
{
  int fd, len;
  char buf[MAX_BUF];

  len = snprintf(buf, sizeof(buf), SYSFS_GPIO_DIR "/gpio%d/edge", gpio);

  fd = open(buf, O_WRONLY);
  if (fd < 0) {
    syslog(LOG_ERR, "gpio/set-edge failed: %i", gpio);
    perror("gpio/set-edge");
    return fd;
  }

  write(fd, edge, strlen(edge) + 1);
  close(fd);
  return 0;
}

int gpio_fd_open(unsigned int gpio)
{
  int fd, len;
  char buf[MAX_BUF];

  len = snprintf(buf, sizeof(buf), SYSFS_GPIO_DIR "/gpio%d/value", gpio);

  fd = open(buf, O_RDONLY | O_NONBLOCK );
  if (fd < 0) {
    syslog(LOG_ERR, "gpio/fd_open failed: %i", gpio);
    perror("gpio/fd_open");
  }
  return fd;
}

int gpio_fd_close(int fd)
{
  return close(fd);
}

static void sighandler(int sig)
{
  syslog(LOG_DEBUG, "Signal Handler called\n");
  switch(sig)
  {
  case SIGINT:
  case SIGTERM:
    gpio_set_value(GPIO_IR_PIN1, 1);
    gpio_set_value(GPIO_IR_PIN2, 0);
    exit(EXIT_SUCCESS);
    break;
  }
}

/*
 * Main
 * There are two GPIOs for the IR LED/Filter control.
 * They are coded, meaning:
 * 0 0 .. IR LEDs ON, filter OUT
 * 0 1 .. IR LEDs ON, no active filter positioning
 * 1 0 .. IR LEDs OFF, no active filter positioning
 * 1 1 .. IR LEDs OFF, filter IN
 *
 * In order to reduce heat, the ICR positioning should be
 * stopped after some time. Periodic repositioning of the filter
 * is scheduled.
 */
int main(int argc, char **argv, char **envp)
{
  struct pollfd fdset[1];
  int nfds = 1;
  int gpio_fd, timeout, rc, count, len, i;
  char ch;
  int dayMode = 0;
  unsigned int gpio;
  int releaseICR = 0;
  char buf[MAX_BUF];
  int goDaemon = 1;
  int debug = 0;
  pid_t pid;
  pid_t sid;


  // Parse command line arguments
  while((i = getopt(argc, argv, "fc:d")) != -1)
  {
    switch(i)
    {
    case 'f':
      goDaemon = 0;
      break;
    case 'd':
      debug = 1;
      goDaemon = 0;
      break;
    case '?':
      if (isprint (optopt))
        fprintf (stderr, "Unknown option `-%c'.\n", optopt);
      else
        fprintf (stderr,
                 "Unknown option character `\\x%x'.\n",
                 optopt);
      fprintf(stderr, "Usage: %s [-f] [-d]\n", argv[0]);
      fprintf(stderr, "       where\n");
      fprintf(stderr, "         -f              don't detach\n");
      fprintf(stderr, "         -d              debug (implies -f)\n");
      return EXIT_FAILURE;
    }

  }

  // Setup syslog
  if(debug)
    setlogmask(LOG_UPTO(LOG_DEBUG));
  else
    setlogmask(LOG_UPTO(LOG_INFO));

  if(goDaemon)
    openlog("lightSensor-daemon", LOG_CONS | LOG_PID | LOG_NDELAY, LOG_LOCAL1);
  else
    openlog("lightSensor-daemon", LOG_CONS | LOG_PID | LOG_NDELAY | LOG_PERROR, LOG_LOCAL1);

  if(goDaemon)
  {
    pid = fork();
    if(pid < 0)
    {
      syslog(LOG_ERR, "Forking failed.\n");
      return EXIT_FAILURE;
    }

    if(pid > 0)
    {
      return EXIT_SUCCESS;
    }
    // From here on we are the child process...
    umask(0);
    sid = setsid();
    if(sid < 0)
    {
      syslog(LOG_ERR, "Could not create process group\n");
      return EXIT_FAILURE;
    }

    if((chdir("/")) < 0)
    {
      syslog(LOG_ERR, "Could not chdir(\"/\")\n");
      return EXIT_FAILURE;
    }
    close(STDIN_FILENO);
    close(STDOUT_FILENO);
    close(STDERR_FILENO);

  }



  // Register some signal handlers
  signal(SIGTERM, sighandler);
  signal(SIGINT, sighandler);

  gpio_export(GPIO_LIGHT);
  gpio_export(GPIO_IR_PIN1);
  gpio_export(GPIO_IR_PIN2);

  gpio_set_dir(GPIO_LIGHT, 0);
  gpio_set_dir(GPIO_IR_PIN1, 1);
  gpio_set_dir(GPIO_IR_PIN2, 1);
  gpio_set_edge(GPIO_LIGHT, "both");

  gpio_fd = gpio_fd_open(GPIO_LIGHT);
  gpio_get_value(GPIO_LIGHT, &dayMode);

  timeout = POLL_TIMEOUT;
  count = 0; // Set to 0 for initial setup based on initial read of light sensor


  syslog(LOG_INFO, "lightSensor-daemon starting up...");

  while (1) {
    memset((void*)fdset, 0, sizeof(fdset));

    if(count == 0) // This is the periodic re-positioning of the filter
    {
      syslog(LOG_DEBUG, "Periodic set called");
      count = (3600 * 1000) / timeout; // 60 minutes
      if(dayMode)
      {
        gpio_set_value(GPIO_IR_PIN1, 1);
        gpio_set_value(GPIO_IR_PIN2, 1);
      }
      else
      {
        gpio_set_value(GPIO_IR_PIN1, 0);
        gpio_set_value(GPIO_IR_PIN2, 0);
      }
      releaseICR = 1;
    }

    fdset[0].fd = gpio_fd;
    fdset[0].events = POLLPRI;

    rc = poll(fdset, nfds, timeout);

    if (rc < 0) {
      syslog(LOG_ERR, "poll() failed");
      return -1;
    }

    if (rc == 0) { // timeout
      count--;
      if(releaseICR)
      {
        syslog(LOG_DEBUG, "Release ICR called");
        if(dayMode)
        {
          gpio_set_value(GPIO_IR_PIN1, 1);
          gpio_set_value(GPIO_IR_PIN2, 0);
        }
        else
        {
          gpio_set_value(GPIO_IR_PIN1, 0);
          gpio_set_value(GPIO_IR_PIN2, 1);
        }
        releaseICR = 0;
      }
    }


    // POLLPRI executed, an interrupt occured, something changed
    if (fdset[0].revents & POLLPRI) {
      lseek(fdset[0].fd, 0, SEEK_SET);
      len = read(fdset[0].fd, buf, MAX_BUF);
      if((len == 2) && (buf[0] != '0'))
      {
        syslog(LOG_DEBUG, "Light sensor reported day");
        // Light sensor went high -> day
        if(!dayMode)
        {
          gpio_set_value(GPIO_IR_PIN1, 1);
          gpio_set_value(GPIO_IR_PIN2, 1);
          dayMode = 1;
        }
      }
      else
      {
        syslog(LOG_DEBUG, "Light sensor reported night");
        // Light sensor went low -> night
        if(dayMode)
        {
          gpio_set_value(GPIO_IR_PIN1, 0);
          gpio_set_value(GPIO_IR_PIN2, 0);
          dayMode = 0;
        }
      }
      releaseICR = 1;
    }

  }

  gpio_fd_close(gpio_fd);
  return 0;
}
