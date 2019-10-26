#include <stdio.h>
#include <stdlib.h>
#include "item.h"
#include "fila.h"

struct fila_
{
    NO* inicio;
    NO* fim;
    int tam;
};

struct no_
{
    ITEM* item;
    NO* prox; 
};

FILA* fila_criar()
{
    FILA* fila = (FILA*) malloc(sizeof(FILA));
    if (fila == NULL)
        printf("\tNão foi possível alocar fila !");

    else
    {
        fila->inicio = NULL;
        fila->fim = NULL;
        fila->tam = 0;
    }
    
    return fila;
}

boolean fila_entra(FILA* f, ITEM* item)
{
    if(f != NULL && !fila_cheia(f))
    {
        NO* novo = (NO*) malloc (sizeof(NO));
        novo->item = item;
        novo->prox = NULL;
        if(f->tam == 0) //primeiro da fila
        {
            f->inicio = novo;
            f->fim = novo;
        }
        else
        {
            f->fim->prox = novo;
            f->fim = novo;
        }

        f->tam++;
        return TRUE;
    }
    return FALSE;
}

ITEM* fila_sai(FILA* f)
{
    if(f != NULL && !fila_vazia(f))
    {
        f->tam--;
        
        NO* aux = (NO*) malloc (sizeof(NO));
        aux = f->inicio; //aux é o que vai sair
        f->inicio = aux->prox; //inicio da fila alterado
        if(f->fim == aux) //se for o ultimo item da lista
            f->fim = NULL;

        ITEM* item = aux->item;

        aux->prox = NULL;
        aux->item = NULL;
        free(aux);
        aux = NULL;
        
        return item;
    }
    return NULL;
}

ITEM* fila_frente(FILA* f)
{
    if(f != NULL && !fila_vazia(f))
    {
        return f->inicio->item;
    }
    return NULL;
}

ITEM* fila_fim(FILA* f)
{
    if(f != NULL && !fila_vazia(f))
    {
        return f->fim->item;
    }
    return NULL;
}

int fila_tamanho(FILA* f)
{
    if(f != NULL)
        return f->tam;
    else
        return 0;
}

boolean fila_vazia(FILA* f)
{
    if (f == NULL)
        return ERRO;
    if(f->tam == 0)
        return TRUE;
    else
        return FALSE;
}

boolean fila_cheia(FILA* f)
{
    if (f == NULL)
        return ERRO;
    if(f->tam == MAXFILA)
        return TRUE;
    else
        return FALSE;
}

//imprime os itens da fila do inicio ao fim mostrando a placa e o preço a se pagar para cada veículo
void fila_imprime(FILA* f)
{
    if(f == NULL || fila_vazia(f))
        return;
    NO* n = f->inicio;
    while(n != NULL)
    {
        printf("\t%d    |   2   |   R$ %.2f\n", item_placa(n->item), item_valor(n->item));
        n = n->prox;
    }
    printf("\n");
}

void fila_apagar(FILA** f)
{
    while(!fila_vazia(*f))
    {
        if(*f != NULL)
        {
            (*f)->tam--;
            
            NO* aux = (NO*) malloc (sizeof(NO));
            aux = (*f)->inicio; //aux é o que vai sair
            (*f)->inicio = aux->prox; //inicio da fila alterado
            if((*f)->fim == aux) //se for o ultimo item da lista
                (*f)->fim = NULL;

            aux->prox = NULL;
            free(aux->item);
            aux->item = NULL;
            free(aux);
            aux = NULL;
        }
    }
    free(*f);
    f = NULL;
}

//busca um item da fila pela placa do veículo
boolean fila_buscar(FILA* f, int placa){
    if(f != NULL && !fila_vazia(f)){
        NO* atual = f->inicio;;
        while(atual != NULL){
            if(item_placa(atual->item) == placa) return 1;
            atual = atual->prox;
        }
        return 0;
    }
    return 0;
}