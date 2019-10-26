#include "lista.h"

struct lista_
{
	int *inicio;	//ponteiro para o primeiro elemento da lista
	int count;		//num de elementos na lista
	int comp;		//num de comparações feitas na lista
};

LISTA* lst_criar() //inicializa e aloca dinamicamente a lista
{		
	LISTA *lst = (LISTA*) malloc(sizeof(LISTA));
	lst->inicio = (int *) calloc (100, sizeof(int));
	lst->count = 0;
	lst->comp = 0;
	return lst;
}

int lst_inserir_item(LISTA* lst, int item)
{
	if(lst->count == 100)	//caso lista esteja cheia
	{
		setlocale(LC_ALL, "Portuguese"); //permite usar acentuação
		printf("Lista cheia. Impossível realizar o processamento.\n");
		return 1;
	}

	for(int i = 0; i < lst->count; i++) //checagem para ver se item já está na lista
	{		
		lst->comp++;
		if(lst->inicio[i] == item)
			return 0;
	}

	lst->inicio[lst->count] = item;	//adiciona o item na lista
	lst->count++;
	return 0;
}

void lst_imprimir(LISTA* lst)
{
	setlocale(LC_ALL, "Portuguese");

	for(int i = 0; i < lst->count; i++)
	{
		printf("%d\t", lst->inicio[i]);
	}

	printf("\nTamanho da lista: %d", lst->count);
	printf("\nTotal de comparações: %d\n", lst->comp);
}

void lst_apagar(LISTA* lst)
{
	free(lst->inicio);
	free(lst);
}
