#include "circulo.h"
#include<stdlib.h>
#include<stdio.h>
#include <math.h>
#define PI 3.14159
struct circulo_
{
    PONTO *ponto_c;
    float raio;
};

CIRCULO* circulo_criar (float x, float y, float raio)
{
    CIRCULO* c = (CIRCULO*) malloc (sizeof(CIRCULO));
    c->ponto_c = ponto_criar(x,y);
    c->raio = raio;
    return c;
}

void circulo_apagar (CIRCULO *circulo)
{
    ponto_apagar(circulo->ponto_c);
    free(circulo);
}

float circulo_area (CIRCULO *circulo)
{
    return PI*circulo->raio*circulo->raio;
}

//Função distancia implementada aqui pois já possui acesso aos tipos pertencentes à estrutura circulo_, sendo necessária somente a importação dos pontos
void distancia(PONTO* p, CIRCULO* c)
{
    float dist = 0;
    
    float px = ponto_get_x(p), py = ponto_get_y(p), cx = ponto_get_x(c->ponto_c), cy = ponto_get_y(c->ponto_c);

    dist = sqrt( (px - cx)*(px - cx) + (py - cy)*(py - cy) );
    
    if( dist < c->raio)
    {
        printf("O ponto é interior à circunferência.\nDistância: %.2f\n", dist);
    }
    else if (dist > c->raio)
    {
        printf("O ponto é exterior à circunferência.\nDistância: %.2f\n", dist);
    }
    else
    {
        printf("O ponto pertence à circunferência.\nDistância: %.2f\n", dist);
    }
}