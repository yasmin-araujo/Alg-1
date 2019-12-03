#ifndef AVL_H
#define AVL_H
#define max(a,b) ((a > b)? a : b)

typedef struct _no No;
typedef struct _c Colecao;

No* avl_insere(No **raiz, No *n);

int avl_busca(No *raiz, int valor);

int avl_vazia(Colecao *c);

void avl_esvaziar(No *n);

void avl_deleta(Colecao **c);

No *avl_r_direita(No *a);

No *avl_r_esquerda(No *a);

No *avl_r_esquerda_direita(No *a);

No *avl_r_direita_esquerda(No *a);

int avl_altura_no(No* no);

#endif