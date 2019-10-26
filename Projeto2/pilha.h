#ifndef PILHA_H
    #define PILHA_H
    #define MAXPILHA 5 // tamanho máximo de veículos no pátio 1
    #define boolean int
    #define TRUE 1 
    #define FALSE 0
    #include "item.h"

    typedef struct no_ NO;
    typedef struct pilha_ PILHA;

    PILHA* pilha_criar(void);
    boolean pilha_empilhar(PILHA* p,ITEM* item);
    ITEM* pilha_desempilhar(PILHA* p);
    ITEM* pilha_topo(PILHA* p);
    int pilha_tamanho(PILHA* p);
    boolean pilha_vazia(PILHA* p);
    boolean pilha_cheia(PILHA* p);
    void pilha_imprime(PILHA* p);
    void pilha_apagar(PILHA** p);
    boolean pilha_buscar(PILHA* p,int placa);

#endif
