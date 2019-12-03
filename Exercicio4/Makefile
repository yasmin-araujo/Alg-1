all: main

run: main
	./main

main: main.c deque.o
	gcc -o main main.c deque.o -Wall -g

deque.o: deque.c
	gcc -c deque.c

clean:
	rm *.o main

zip:
	zip exc4 main.c deque.c deque.h Makefile