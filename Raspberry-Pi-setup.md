Raspberry Pi setup
=========
>02-05-2017

####1. Install Java8 on Raspberry Pi 3

* A repository providing the latest Oracle Java 8 revision (above “101”) is being maintained by the Webupd8 Team. Follow the provided guides for either a repository based or a PPA based installation. In short these are the commands to execute step-by-step on most systems:

```
echo "deb http://ppa.launchpad.net/webupd8team/java/ubuntu xenial main" | sudo tee /etc/apt/sources.list.d/webupd8team-java.list
echo "deb-src http://ppa.launchpad.net/webupd8team/java/ubuntu xenial main" | sudo tee -a /etc/apt/sources.list.d/webupd8team-java.list
sudo apt-key adv --keyserver hkp://keyserver.ubuntu.com:80 --recv-keys EEA14886
sudo apt-get update
sudo apt-get install oracle-java8-installer
sudo apt-get install oracle-java8-set-default
```
