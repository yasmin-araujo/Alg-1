all: lista.o
	gcc -g -o exc main.c lista.o

lista.o: lista.c
	gcc -g -c lista.c

run: exc
	./exc

zip:
	zip exc main main.c lista.o lista.h lista.c Makefile