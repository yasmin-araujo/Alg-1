#include <stdio.h>
#include <stdlib.h>
#include "abb.h"

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

void abb_insere(No** raiz, No *n)
{
    if (*raiz == NULL) // caso base
        *raiz = n;
    else
    {
        if (n->valor > (*raiz)->valor)
            abb_insere(&(*raiz)->dir, n);
        else if (n->valor < (*raiz)->valor)
            abb_insere(&(*raiz)->esq,n);
    }
}

int abb_busca(No* raiz, int valor)
{
    if(raiz == NULL) 
        return 0;
    else{
        if(raiz->valor == valor) return 1;
        if(raiz->valor > valor) return abb_busca(raiz->esq, valor); 
        if(raiz->valor < valor) return abb_busca(raiz->dir, valor);
    }
}

int abb_vazia(Colecao *c)
{
    if(c->inicio == NULL) return 1;
    return 0;
}

void abb_esvaziar(No *n)
{
    if (n == NULL)
        return;
    abb_esvaziar(n->dir);
    abb_esvaziar(n->esq);
    n->dir = NULL;
    n->esq = NULL;
    free(n);
    n = NULL;
}

void abb_deleta(Colecao **c)
{
    if (*c == NULL)
        return;
    abb_esvaziar((*c)->inicio);
    free(*c);
    *c = NULL;
}