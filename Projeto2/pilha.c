#include "pilha.h"
#include <stdio.h>
#include <stdlib.h>

struct pilha_{
    NO* topo;
    int tamanho;
};

struct no_{
    ITEM* item;
    NO* anterior;
};

PILHA* pilha_criar(void){
    PILHA* p = (PILHA*)malloc(sizeof(PILHA));
    if(p != NULL){
        p->topo = NULL;
        p->tamanho = 0;
        return p;
    }
    return NULL;
}

boolean pilha_empilhar(PILHA* p, ITEM* i){
    if(p != NULL && !pilha_cheia(p));
    NO* pnovo = (NO*)malloc(sizeof(NO));
    if(pnovo != NULL){
        pnovo->item = i;
        pnovo->anterior = p->topo;
        p->topo = pnovo;
        p->tamanho++;
        return TRUE;
    }
    return FALSE;
}

//função responsável por retirar o item do topo da pilha e o retornar
ITEM* pilha_desempilhar(PILHA* p){
    if(p != NULL && (!pilha_vazia(p))){
        NO* aux = p->topo;
        ITEM* i = aux->item;
        p->topo = p->topo->anterior;
        aux->anterior = NULL;
        aux->item = NULL;
        free(aux);
        aux = NULL;
        p->tamanho--;
        return i;
    }
    return NULL;
}

ITEM* pilha_topo(PILHA* p){
    if(p != NULL && (!pilha_vazia(p))){
        return(p->topo->item);
    }
    return NULL;
}

int pilha_tamanho(PILHA* p)
{
    return p->tamanho;
}

boolean pilha_vazia(PILHA* p){
    if(p->topo != NULL) return FALSE;
    else return TRUE;
}

boolean pilha_cheia(PILHA* p){
    if(p->tamanho == MAXPILHA) return TRUE;
    else return FALSE;
}

//imprime os itens da pilha do topo ao início mostrando a placa e o preço a se pagar para cada veículo
void pilha_imprime(PILHA* p)
{
    if(p == NULL || pilha_vazia(p))
        return;
    NO* n = p->topo;
    while(n != NULL)
    {
        printf("\t%d    |   1   |   R$ %.2f\n", item_placa(n->item), item_valor(n->item));
        n = n->anterior;
    }
}

//free nos itens e nós da pilha e depois free na pilha
void pilha_apagar(PILHA** p){
    while(!pilha_vazia((*p))){
        if(*p != NULL)
        {
            NO* aux = (*p)->topo;
            (*p)->topo = (*p)->topo->anterior;
            aux->anterior = NULL;
            free(aux->item);
            aux->item = NULL;
            free(aux);
            aux = NULL;
            (*p)->tamanho--;
        }
    }
    free((*p));
    p = NULL;    
}

//busca por algum item a partir da placa do veículo 
boolean pilha_buscar(PILHA* p, int placa){
    if(p != NULL && !pilha_vazia(p)){
        NO* atual = p->topo;
        while(atual != NULL){
            if(item_placa(atual->item) == placa) return 1;
            atual = atual->anterior;
        }
        return 0;
    }
    return 0;
}