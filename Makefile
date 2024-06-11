CC = gcc
CFLAGS = -Wall -g
EXEC = main

all: $(EXEC)

$(EXEC): main.o stack.o
	$(CC) $(CFLAGS) -o $(EXEC) main.o stack.o

main.o: main.c stack.h
	$(CC) $(CFLAGS) -c main.c

stack.o: stack.c stack.h
	$(CC) $(CFLAGS) -c stack.c

valgrind: $(EXEC)
	valgrind --leak-check=full ./$(EXEC)
	
clean:
	rm -f *.o $(EXEC)
