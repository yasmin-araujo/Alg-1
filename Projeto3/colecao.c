#include <stdio.h>
#include <stdlib.h>
#include "colecao.h"
#include "lista.h"
#include "abb.h"
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

Colecao *cria_colecao(int estrutura_id)
{
    Colecao *col = (Colecao *)malloc(sizeof(Colecao));
    col->estrutura_id = estrutura_id;
    col->inicio = NULL; //tem que começar com o tal de nó inicial? se sim o que vai ter de valor nele? //acho q o certo é null mesmo n sei
                        
    return col;
}

No *cria_no(int valor)
{
    No *no = (No *)malloc(sizeof(No));
    no->valor = valor;
    no->altura = 0; //0 ou -1?  // o rudinei colocou 0 nos slides dele pois acho q -1 é quando o nó nem existe
    no->dir = NULL;
    no->esq = NULL;
    return no;
}

void adiciona(Colecao *c, int valor)
{
    No *n = cria_no(valor);
    switch (c->estrutura_id)
    {
    case LISTA_ORDENADO:
        lista_insere_ordenado(c, n);
        break;
    case LISTA_ULTIMO:
        lista_insere_fim(c, n);
        break;
    case LISTA_PRIMEIRO:
        lista_insere_inicio(c, n);
        break;
    case ARVORE_BINARIA:
        abb_insere(&(c->inicio), n);
        break;
    case ARVORE_AVL:
        avl_insere(&(c->inicio), n);
        break;
    }
}

int existe(Colecao *c, int valor)
{
    int res = 0;
    switch (c->estrutura_id)
    {
    case LISTA_ORDENADO:
        res = lista_busca_ordenada(c, valor);
        break;
    case LISTA_ULTIMO:
    case LISTA_PRIMEIRO:
        res = lista_busca(c, valor);
        break;
    case ARVORE_BINARIA:
        res = abb_busca(c->inicio, valor);
        break;
    case ARVORE_AVL:
        res = avl_busca(c->inicio, valor);
        break;
    }
    return res;
}
void destroi(Colecao *c)
{
    switch (c->estrutura_id)
    {
    case LISTA_ORDENADO:
    case LISTA_ULTIMO:
    case LISTA_PRIMEIRO:
        lista_deleta(&c);
        break;
    case ARVORE_BINARIA:
        abb_deleta(&c);
        break;
    case ARVORE_AVL:
        avl_deleta(&c);
        break;
    }
}