#include <stdio.h>
#include <stdlib.h>
#include "avl.h"

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

No* avl_insere(No** raiz, No *n)
{
	if (*raiz == NULL) 
    {
		*raiz = n;
        return *raiz;
    }
	else
	{        
        if(n->valor > (*raiz)->valor){
            (*raiz)->dir = avl_insere(&(*raiz)->dir, n);
            if(avl_altura_no((*raiz)->esq)-avl_altura_no((*raiz)->dir) == -2){
                if(n->valor > (*raiz)->dir->valor)
                    *raiz = avl_r_esquerda(*raiz);
                else
                    *raiz = avl_r_direita_esquerda(*raiz);
            }
        }
        else if(n->valor < (*raiz)->valor){
            (*raiz)->esq = avl_insere(&(*raiz)->esq, n);
            if(avl_altura_no((*raiz)->esq)-avl_altura_no((*raiz)->dir) == 2){
                if(n->valor < (*raiz)->esq->valor)
                    *raiz = avl_r_direita(*raiz);
                else
                    *raiz = avl_r_esquerda_direita(*raiz);
            }  
        }
    }
    (*raiz)->altura = max(avl_altura_no((*raiz)->esq),avl_altura_no((*raiz)->dir)) + 1;
    return *raiz;
}

int avl_busca(No *raiz, int valor){
    if(raiz == NULL) 
        return 0;
    else{
        if(raiz->valor == valor) return 1;
        if(raiz->valor > valor) return avl_busca(raiz->esq, valor); 
        if(raiz->valor < valor) return avl_busca(raiz->dir, valor);
    }
}

int avl_altura_no(No* no){
    if(no == NULL) return -1;
    return no->altura;
}

int avl_vazia(Colecao *c)
{
    if(c->inicio == NULL) return 1;
    return 0;
}

void avl_esvaziar(No *n)
{
    if(n == NULL)
        return;
    avl_esvaziar(n->dir);
    avl_esvaziar(n->esq);
    n->dir = NULL;
    n->esq = NULL;
    free(n);
    n = NULL;
}

void avl_deleta(Colecao **c)
{
    if (*c == NULL)
		return;
	avl_esvaziar((*c)->inicio);
	free(*c);
	*c = NULL;
}

No *avl_r_direita(No *a){
    No *b = a->esq;
    a->esq = b->dir;
    b->dir = a;

    a->altura = max(avl_altura_no(a->esq), avl_altura_no(a->dir)) + 1;
    b->altura = max(avl_altura_no(b->dir),a->altura) + 1;
    return b;
}

No *avl_r_esquerda(No *a){
    No *b = a->dir;
    a->dir = b->esq;
    b->esq = a;

    a->altura = max(avl_altura_no(a->esq), avl_altura_no(a->dir)) + 1;
    b->altura = max(avl_altura_no(b->dir),a->altura) + 1;
    return b;
}

No *avl_r_esquerda_direita(No *a){
    a->esq = avl_r_esquerda(a->esq);
    return avl_r_direita(a);

}

No *avl_r_direita_esquerda(No *a){
    a->dir = avl_r_direita(a->dir);
    return avl_r_esquerda(a);
}
