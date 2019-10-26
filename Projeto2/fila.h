#ifndef FILA_H
    #define FILA_H

    #define MAXFILA 10 //tamanho máximo de veículos no pátio 2
    #define boolean int
    #define TRUE 1
    #define FALSE 0

    typedef struct fila_ FILA;
    typedef struct no_ NO;    
    
    FILA* fila_criar();
    boolean fila_entra(FILA* f, ITEM* item);
    ITEM* fila_sai(FILA* f);
    ITEM* fila_frente(FILA* f);
    ITEM* fila_fim(FILA* f);
    int fila_tamanho(FILA* f);
    boolean fila_vazia(FILA* f);
    boolean fila_cheia(FILA* f);
    void fila_imprime(FILA* f);
    void fila_apagar(FILA** f);
    boolean fila_buscar(FILA* f, int placa);

#endif