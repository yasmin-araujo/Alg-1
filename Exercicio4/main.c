#include "deque.h"
#include <stdio.h>
#include <stdlib.h>

char filter(char c) //Filtrar letras acentuadas
{
    if(c == 131 || c == 160)
        return 'a';
    else if(c == 130 || c == 136)
        return 'e';
    else if(c == 141 || c == 161)
        return 'i';
    else if(c == 147 || c == 162)
        return 'o';
    else
        return 'u';
}

void is_palindrome(DEQUE *d)
{
    NODE *A, *B;
    while (!is_empty(d))
    {
        A = remove_beginning(d);
        ITEM a = get_item(A);
        if(is_empty(d))
            continue;
        B = remove_end(d);
        ITEM b = get_item(B);
        if (a != b)
        {
            printf("Não é palíndromo.");
            free(A);
            free(B);
            return;
        }
        free(A);
        free(B);
    }
    //free(A);
    printf("É palíndromo.");
}

int main()
{
    DEQUE *deque = create_deque(); //criação de deque para facilitar o acesso das letras tanto pelo começo quanto pelo final
    char ch;
    ch = getchar();
    while (ch != '.')
    {
        if(ch < 65) //caracteres especiais
        {
            ch = getchar();
            continue;
        }
        else if(ch < 97) //maiúsculas
            ch += 32;
        else if(ch > 129) //letras acentuadas
            ch = filter(ch);
        insert_end(deque, ch);
        ch = getchar();
    }
    is_palindrome(deque);
    delete_deque(&deque);
}