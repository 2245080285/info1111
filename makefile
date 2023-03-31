CC = gcc
CFLAGS = -Wall -Wextra -std=c99

all: database

database: database.o
	$(CC) $(CFLAGS) -o database database.o

database.o: database.c
	$(CC) $(CFLAGS) -c database.c

clean:
	rm -f *.o database
