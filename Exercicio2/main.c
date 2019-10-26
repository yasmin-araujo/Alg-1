#include "lista.h"

int main()
{
	int num, item;
	scanf("%d", &num);	//quantidade de itens na lista
	LISTA *lst = lst_criar();	 //alocação e inicizlização da lista
	
    for(int i = 0; i < num; i++) //inserção dos elementos na lista
    {
		scanf("%d", &item);
		if(lst_inserir_item(lst, item)) //tenta inserir o item, caso não consiga encerra o programa
			return 0;
	}

    //impressão e liberação da lista da memoria
	lst_imprimir(lst);
	lst_apagar(lst);
	return 0;
}
