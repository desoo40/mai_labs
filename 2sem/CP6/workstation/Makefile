PROGNAME_1 = gen
PROGNAME_2 = exe
PROGNAME_3 = test
CFLAGS = -Wall  -Wextra -std=c99
CC = gcc

all: $(PROGNAME_1) $(PROGNAME_2) $(PROGNAME_3) clean

$(PROGNAME_1): io.o
	$(CC) $(CFLAGS) generate.c -o $(PROGNAME_1) io.o

$(PROGNAME_2): class.o io.o trees.o
	$(CC) $(CFLAGS) main.c -o $(PROGNAME_2) class.o io.o trees.o

$(PROGNAME_3):
	g++ -Wall -Wextra -std=c++11 test_gen.cpp -o $(PROGNAME_3)

class.o: class.c class.h
	$(CC) $(CFLAGS) -c class.c

io.o: io.c io.h graduate.h
	$(CC) $(CFLAGS) -c io.c

trees.o: trees.c trees.h
	$(CC) $(CFLAGS) -c trees.c



clean:
	rm -f *.o