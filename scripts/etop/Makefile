CC = gcc
CFLAGS = -Wall -O2
LIBS = -lncurses

etop: epiphany-mon.c
	$(CC) $(CFLAGS) -o etop epiphany-mon.c $(LIBS)

clean:
	rm -f etop