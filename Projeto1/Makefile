all: prog

run: prog
	./prog

prog: prog.c list.o
	gcc -o prog prog.c list.o list.h -Wall

list.o: list.c
	gcc -c list.c
