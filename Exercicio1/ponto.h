#ifndef PONTO_H
    #define PONTO_H
    typedef struct ponto_ PONTO;
    PONTO *ponto_criar (float x, float y);
    void ponto_apagar (PONTO *p);
    //boolean ponto_set(PONTO *p, float x, float y);
    //funções adicionadas para que a circulo.c possa pegar os valores x, y dos pontos para fazer o calculo das distancias
    float ponto_get_x (PONTO *p);
    float ponto_get_y (PONTO *p);
#endif
    