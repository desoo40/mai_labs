PROGNAME = exe
CFLAGS = -Wall  -Wextra -std=c99
CC = gcc

all: $(PROGNAME) clean

$(PROGNAME): list_arr.o
	$(CC) $(CFLAGS) main.c -o $(PROGNAME) list_arr.o

list_arr.o: list_arr.c list_arr.h
	$(CC) $(CFLAGS) -c list_arr.c

clean:
	rm -f *.o