#include <stdio.h>
#include <stdlib.h>
#include "list.h"

// Inclusão de novas guias
void incluir(List * l, char* url, char* titulo)
{
    insert_registration(l, titulo, url);
}

// Alteração de ordem de guias
void alterar(List* l, int pos_final, char* titulo)
{
    int pos_inicial = busca_titulo(l, titulo); // onde a guia já está posicionada
    if(pos_inicial > 0) // se guia existir
    {
        if(pos_final > size_list(l)) // se posição final está fora do indice da lista - move para o final
        {
            pos_final = size_list(l);
        }
        alterar_registro(l, pos_inicial, pos_final);
    }
}

// Impressão dos registros
void imprimir(List* l)
{
    print_registrations(l);
}

// Menu de opções
void menu(List* l)
{
    int opc;
    char t[40], u[512];
    int pos;
    scanf(" %d", &opc);
    switch (opc)
    {
        case 1:
            scanf(" %s", t);
            scanf(" %s", u);
            incluir(l, u, t);
            break;
        case 2:
            scanf(" %s", t);
            scanf(" %d", &pos);
            alterar(l, pos, t);
            break;
        case 3:
            imprimir(l);
            break;
        case 4:
            delete_list(&l);
            exit(0);
            break;
    }
    menu(l);
}

int main()
{
    List *l = create_list();
    menu(l);
    return 0;
}