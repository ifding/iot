CC?=gcc
CFLAGS?=-I. -I/usr/include
LIBS=
DEPS = 
OBJ = lightSensor-daemon.o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

lightSensor-daemon: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

clean:
	rm -f *.o
