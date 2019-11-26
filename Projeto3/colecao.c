#include <stdlib.h>
#include "colecao.h"
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

Colecao *cria_colecao(int estrutura_id)
{
    Colecao *col = (Colecao *)malloc(sizeof col);
    col->estrutura_id = estrutura_id;
    col->inicio = NULL; //tem que começar com o tal de nó inicial? se sim o que vai ter de valor nele?
    return col;
}

No *cria_no(int valor)
{
    No *no = (No *)malloc(sizeof(No));
    no->valor = valor;
    no->altura = -1; //0 ou -1?
    no->dir = NULL;
    no->esq = NULL;
    return no;
}

void adiciona(Colecao *c, int valor)
{
    // Implementar
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
        break;
    case ARVORE_AVL:
        break;
    }
}

int existe(Colecao *c, int valor)
{
    // Implementar
    switch (c->estrutura_id)
    {
    case LISTA_ORDENADO:
        lista_busca_ordenada(c, valor);
        break;
    case LISTA_ULTIMO:
    case LISTA_PRIMEIRO:
        lista_busca(c, valor);
        break;
    case ARVORE_BINARIA:
        break;
    case ARVORE_AVL:
        break;
    }
    return 1;
}
void destroi(Colecao *c)
{
    // Implementar
    switch (c->estrutura_id)
    {
    case LISTA_ORDENADO:
    case LISTA_ULTIMO:
    case LISTA_PRIMEIRO:
        lista_deleta(&c);
        break;
    case ARVORE_BINARIA:
        break;
    case ARVORE_AVL:
        break;
    }
}