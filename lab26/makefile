PROGNAME = merge_sort
CFLAGS = -Wall -Werror -Wextra -pedantic -std=c99
CC = gcc

all: $(PROGNAME) clean

$(PROGNAME): list.o list_den.o
	$(CC) $(CFLAGS) merge.c -o $(PROGNAME) list.o list_den.o

list.o: list.c list.h
	$(CC) $(CFLAGS) -c list.c

list_den.o: list_den.c list_den.h
	$(CC) $(CFLAGS) -c list_den.c

clean:
	rm -f *.o