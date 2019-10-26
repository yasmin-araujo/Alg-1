#include "item.h"
#include <stdio.h>
#include <stdlib.h>

struct item_{
    int placa;
    int hchegada;
    int hsaida;
    float desconto;
};

//cria o item
ITEM* item_criar(int placa, int hchegada, int hsaida ,float desconto){
    ITEM* i = (ITEM*)malloc(sizeof(ITEM));
    if(i != NULL){
        i->placa = placa;
        i->hchegada = hchegada;
        i->hsaida = hsaida;
        i->desconto = desconto;
        return i;
    }
    else
        return NULL;    
}

//retorna a placa do veículo
int item_placa(ITEM* i){
    if(i != NULL){
        return i->placa;
    }
    return ERRO;
}

//retorna o horário de chegada do veículo
int item_hchegada(ITEM* i){
    if(i != NULL){
        return i->hchegada;
    }
    return ERRO;
}

//retorna o horário de saída do veículo
int item_hsaida(ITEM* i){
    if(i != NULL){
        return i->hsaida;
    }
    return ERRO;
}

//determina se um carro tem ou não desconto
float item_desconto(ITEM* i){
    if(i != NULL){
        return i->desconto;
    }
    return ERRO;
}

//retorna o valor a se pagar pelo carro com o desconto quando houver
float item_valor(ITEM* i)
{
    if(i != NULL)
    {
        float v = 3 * (i->hsaida - i->hchegada);
        v *= (1 - i->desconto);
        return v;
    }
    return ERRO;
}

//aplica desconto no carro sorteado
void item_setDesconto(ITEM* i){
    i->desconto = 0.1;
}