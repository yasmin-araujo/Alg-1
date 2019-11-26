#ifndef LISTA_H
#define LISTA_H

typedef struct _no No;
typedef struct _c Colecao;

/* Função para inserção de registro de forma ordenada */
void lista_insere_ordenado(Colecao *c, No *n);

/* Função para inserção de registro na última posição */
void lista_insere_fim(Colecao *c, No *n);

/* Função para inserção de registro na primeira posição */
void lista_insere_inicio(Colecao *c, No *n);

/* Função para busca em lista ordenada */
int lista_busca_ordenada(Colecao *c, int valor);

/* Função para busca em lista desordenada */
int lista_busca(Colecao *c, int valor);

/* Função que determina se lista está vazia */
int lista_vazia(Colecao *c);

/* Função que libera nós da lista recursivamente */
void lista_esvaziar(No *n);

/* Função que apaga toda a lista */
void lista_deleta(Colecao **c);

#endif
