all: main.o auxiliar.o colecao.o lista.o abb.o avl.o
	gcc main.o auxiliar.o colecao.o lista.o abb.o avl.o -o programa

main.o: main.c
	gcc main.c -c

auxiliar.o: auxiliar.c
	gcc auxiliar.c -c

colecao.o: colecao.c
	gcc colecao.c -c

lista.o: lista.c
	gcc lista.c -c

abb.o: abb.c
	gcc abb.c -c

avl.o: avl.c
	gcc avl.c -c

run:
	./programa

clean:
	rm -rf programa *.o