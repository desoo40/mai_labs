PROGNAME = bintree
CFLAGS = -Wall  -Wextra -std=c99
CC = gcc

all: $(PROGNAME) clean

$(PROGNAME): tree.o
	$(CC) $(CFLAGS) main.c -o $(PROGNAME) tree.o

tree.o: tree.c tree.h
	$(CC) $(CFLAGS) -c tree.c

clean:
	rm -f *.o