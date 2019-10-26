all: main

run: main
	./main

main: main.c fila.o pilha.o item.o
	gcc -o main main.c fila.o pilha.o item.o -Wall -g

fila.o: fila.c
	gcc -c fila.c

pilha.o: pilha.c
	gcc -c pilha.c

item.o: item.c
	gcc -c item.c

clean:
	rm *.o main