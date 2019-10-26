#include "ponto.h"
#include "circulo.h"
#include <stdio.h>

int main()
{
    float px, py, cx, cy, cr;

    scanf("%f %f %f %f %f", &px, &py, &cx, &cy, &cr);

    PONTO* p = ponto_criar(px, py);
    CIRCULO* c = circulo_criar(cx, cy, cr);

    distancia(p, c);    

    return 0;
}