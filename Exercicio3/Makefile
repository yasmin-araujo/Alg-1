all: exc3

run: exc3
	./exc3

exc3: Exercicio3.c list.o
	gcc -o exc3 Exercicio3.c list.o list.h -g -Wall

list.o: list.c
	gcc -c list.c

zip:
	zip Exercicio3 Exercicio3.c list.h list.c Makefile