PROGNAME = exe
CFLAGS = -Wall  -Wextra -std=c99
CC = gcc

all: $(PROGNAME) clean

$(PROGNAME): dijkstra.o queue.o stack.o tree.o matem.o
	$(CC) $(CFLAGS) main.c -o $(PROGNAME) dijkstra.o queue.o stack.o tree.o matem.o

dijkstra.o: dijkstra.c dijkstra.h
	$(CC) $(CFLAGS) -c dijkstra.c

queue.o: queue.c queue.h
	$(CC) $(CFLAGS) -c queue.c

stack.o: stack.c stack.h
	$(CC) $(CFLAGS) -c stack.c

tree.o: tree.c tree.h
	$(CC) $(CFLAGS) -c tree.c

matem.o: matem.c matem.h
	$(CC) $(CFLAGS) -c matem.c

clean:
	rm -f *.o