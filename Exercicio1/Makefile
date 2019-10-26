all: ponto.o circulo.o
	gcc -g ponto.o circulo.o main.c -o main -lm

ponto.o:
	gcc -g -c ponto.c

circulo.o:
	gcc -g -c circulo.c

clean:
	rm *.o main

run:
	./main

zip:
	zip exc main main.c ponto.o circulo.o ponto.h circulo.h ponto.c circulo.c Makefile