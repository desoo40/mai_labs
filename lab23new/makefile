PROGNAME = bintree
CFLAGS = -Wall  -Wextra -std=c99
CC = gcc

all: $(PROGNAME) clean

$(PROGNAME): tree.o interface.o
	$(CC) $(CFLAGS) main.c -o $(PROGNAME) tree.o interface.o

tree.o: tree.c tree.h
	$(CC) $(CFLAGS) -c tree.c

interface.o: interface.c interface.h
	$(CC) $(CFLAGS) -c interface.c

clean:
	rm -f *.o