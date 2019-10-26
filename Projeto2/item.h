#ifndef ITEM_H
    #define ITEM_H
    #define ERRO -32000
    
    typedef struct item_ ITEM;

    ITEM* item_criar(int placa, int hchegada, int hsaida ,float desconto);
    int item_placa(ITEM* i);
    int item_hchegada(ITEM* i);
    int item_hsaida(ITEM* i);
    float item_desconto(ITEM* i);
    float item_valor(ITEM* i);
    void item_setDesconto(ITEM* i);

#endif