#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

struct _no
{
	int valor;
	struct _no *esq;
	struct _no *dir;
	int altura;
};

struct _c
{
	No *inicio;
	int estrutura_id;
};

void lista_insere_ordenado(Colecao *c, No *n)
{
	No *aux = c->inicio;

	if (aux == NULL) // caso lista ainda esteja vazia
		c->inicio = n;
	else
	{
		while (aux->valor < n->valor) // acha nó maior
			aux = aux->dir;
		n->esq = aux->esq;
		n->dir = aux;
		aux->esq->dir = n;
		aux->esq = n;
	}
}

void lista_insere_fim(Colecao *c, No *n)
{
	No *aux = c->inicio;

	if (aux == NULL) // caso lista ainda esteja vazia
		c->inicio = n;
	else
	{
		while (aux->dir != NULL) // acha último nó
			aux = aux->dir;
		aux->dir = n;
		n->esq = aux;
	}
}

void lista_insere_inicio(Colecao *c, No *n)
{
	n->dir = c->inicio;
	if(c->inicio != NULL)
		c->inicio->esq = n;
	c->inicio = n;
}

int lista_busca_ordenada(Colecao *c, int valor)
{
	return 0;
}

int lista_busca(Colecao *c, int valor)
{
	return 0;
}

int lista_vazia(Colecao *c)
{
	if (c->inicio == NULL) // caso não exista nenhum nó
	{
		printf("\tNão há nenhum registro.");
		return 1;
	}
	return 0;
}

void lista_esvaziar(No *n)
{
	if (n != NULL)
	{
		if (n->dir != NULL)
			lista_esvaziar(n->dir);

		n->dir = NULL;
		n->esq = NULL;
		free(n);
		n = NULL;
	}
}

void lista_deleta(Colecao **c)
{
	if (*c == NULL)
		return;
	lista_esvaziar((*c)->inicio);
	free(*c);
	*c = NULL;
}
