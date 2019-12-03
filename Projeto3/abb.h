#ifndef ABB_H
#define ABB_H

typedef struct _no No;
typedef struct _c Colecao;

void abb_insere(No **raiz, No *n);

int abb_busca(No *raiz, int valor);

int abb_vazia(Colecao *c);

void abb_esvaziar(No *n);

void abb_deleta(Colecao **c);

#endif