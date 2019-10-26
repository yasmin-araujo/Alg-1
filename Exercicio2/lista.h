#ifndef _LISTA_H
	#define _LISTA_H
	#include <stdio.h>
	#include <stdlib.h>
	#include <locale.h>
	
	typedef struct lista_ LISTA;
	LISTA* lst_criar();
	int lst_inserir_item(LISTA* lst, int item);
	void lst_imprimir(LISTA* lst);
	void lst_apagar(LISTA* lst);
#endif

