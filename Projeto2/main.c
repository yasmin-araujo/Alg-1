/*
	Algoritmos e Estruturas de Dados I - Projeto 2
	11218809 - Flávio Salles
	11219004 - Yasmin Osajima de Araujo
*/
#include<stdio.h>
#include<stdlib.h>
#include "item.h"
#include "fila.h"
#include "pilha.h"

// Funções para consistencia de dados na leitura de valores do tipo int e float
int read_int()
{
	int opt, status;

	status = scanf(" \n%d", &opt);

	if(status)
		return opt;
	else
	{
		printf("\n\tNúmero inválido\n");
		return -1;
	}
}

float read_float()
{
	float opt;
	int status;

	status = scanf(" \n%f", &opt);

	if(status)
		return opt;
	else
	{
		printf("\n\tNúmero inválido\n");
		return -1;
	}
}

// Função para conferir se placa já está cadastrada
boolean confere_placa(PILHA* p,FILA* f,int placa){
	int existe = 0;
	existe = pilha_buscar(p,placa);
	if(!existe) existe = fila_buscar(f,placa); //caso não exista na pilha, busca na fila
	if(existe){
		printf("\n\tEste carro já está estacionado no pátio");
		return FALSE;
	}
	return TRUE;
}

// Função para a realização do Checkin
ITEM* checkin(PILHA* p, FILA* f)
{
	//Leitura dos Dados

	int placa, hc, hs;
	printf("\n\tDigite a placa do carro: ");
	placa = read_int();
	
	while(placa < 1 || placa > 9999 || placa < 1000) // Leitura de placas com estritamente 4 digitos, onde zeros a esquerda não contam
	{
		getchar();
		printf("\n\tDigite a placa do carro: ");
		placa = read_int();
	}

	printf("\n\tDigite o horário de chegada: ");
	hc = read_int();
	
	while(hc < 8 || hc > 21 || hc <= item_hchegada(fila_fim(f)) || hc <= item_hchegada(pilha_topo(p)))
	{
		getchar();
		printf("\n\tDigite o horário de chegada: ");
		hc = read_int();
	}

	printf("\n\tTotal de horas que o carro ficará estacionado: ");

	hs = read_int();
	
	while(hs < 1 || (hs+hc) > 22)
	{
		getchar();
		printf("\n\tTotal de horas que o carro ficará estacionado: ");
		hs = read_int();
	}

	// Checagem se carro já está estacionado
	if(!confere_placa(p,f,placa))
		return NULL;

	// Criação do item
	ITEM* i = item_criar(placa, hc, (hc+hs), 0);
	return i;
}

// Função para realização do Checkout
void checkout(PILHA* p,FILA* f,ITEM* i){
	ITEM* atual;
	int flag = 0; 
	
	// Retira itens que horário de saída já passou e retira das estruturas, imprimindo-os
	while(pilha_topo(p) != NULL && item_hsaida(pilha_topo(p)) <= item_hchegada(i)){
		atual = pilha_desempilhar(p);
		if(flag == 0)
		{
			printf("\n\tCHECKOUT:");
			printf("\n\tPlaca   | Pátio |   Valor a ser pago\n");
			flag = 1;
		}
		printf("\t%d    |   1   |   R$ %.2f\n", item_placa(atual), item_valor(atual));
		free(atual);
	}
	while(fila_frente(f) != NULL && item_hsaida(fila_frente(f)) <= item_hchegada(i)){
		if(flag == 0)
		{
			printf("\n\tCHECKOUT:");
			printf("\n\tPlaca   | Pátio |   Valor a ser pago\n");
			flag = 1;
		}
		atual = fila_sai(f);
		printf("\t%d    |   2   |   R$ %.2f\n", item_placa(atual), item_valor(atual));
		free(atual);
	}
}

// Função para realização do sorteio
void sorteio(PILHA* p, FILA* f, ITEM* i)
{
	int tam = pilha_tamanho(p) + fila_tamanho(f);
	if(tam < 4) // Pelo menos 25% da capacidade total ocupada
		return;

	switch (item_hchegada(i)) //9h, 12h, 15h, e 18h - horários dos sorteios
	{
		case 9:
		case 12:
		case 15:
		case 18:
			srand(item_hchegada(i)); // Seed é o horário do sorteio
			int cursor = rand() % tam; // Índice do item sorteado, o "%tam" simula uma roleta que limita os números entre a quantidade de carros nos pátios

			// Não foi criado um array - objetivo de poupar memória e processamento
			// É sorteado um valor referente a posição do item (presente na impressão da lista, por exemplo)
			// sendo que a ordem dos itens é: carros da pilha, carros da fila
			// Pelo número sorteado e tamanhos das estruturas criadas, é localizado o pátio correto e por cosnequência o carro em questão

			if(cursor >= pilha_tamanho(p)) // Caso índice seja maior que o tamanho da pilha -> carro sorteado está na fila
			{
				cursor -= pilha_tamanho(p); // Correção do cursor
				for(int i = 0; i < fila_tamanho(f); i++) //Percorre toda a fila, retirando o primeiro item e colocando-o de volta no final para ordem ser preservada
				{
					if(i == cursor) // Caso primeiro item da fila seja o sorteado, desconto é aplicado
					{
						item_setDesconto(fila_frente(f));
					}
					fila_entra(f, fila_sai(f));
				}
			}
			else // Carro sorteado está na pilha
			{
				PILHA* aux = pilha_criar();
				for(int i = 0; i < pilha_tamanho(p); i++) // Passa todo o conteudo da pilha para uma auxiliar
				{
					if(i == cursor) // Caso item a ser passado seja o sorteado, desconto é adicionado
					{
						item_setDesconto(pilha_topo(p));
					}
					pilha_empilhar(aux, pilha_desempilhar(p));
				}
				while(!pilha_vazia(aux)) //Retorna itens para pilha principal
					pilha_empilhar(p, pilha_desempilhar(aux));
				pilha_apagar(&aux);
			}
			break;

		default:
			return;
	}
}

// Função para definir pátio para onde carro será alocado
int disponibilidade(PILHA* p, FILA* f, ITEM* i)
{
	int patio = 0;
	int hs = item_hsaida(i);

	if(pilha_vazia(p))
		patio = 1;
	else if(fila_vazia(f))
		patio = 2;
	else if(hs <= item_hsaida(pilha_topo(p)))
		patio = 1;
	else if(hs >= item_hsaida(fila_fim(f)))
		patio = 2;
	return patio;
}

// Função para inserção de novo carro
void insere_carro(PILHA* p, FILA* f)
{
	ITEM* i = checkin(p,f);
	if(i == NULL)
		return;

	checkout(p,f,i);

	sorteio(p, f, i);

	// Alocação do carro
	int patio = disponibilidade(p, f, i);
	switch (patio)
	{
		case 1:
			pilha_empilhar(p, i);
			break;
		case 2:
			fila_entra(f, i);
			break;
		default:
			printf("\n\tNão existem vagas disponíveis!");
			break;
	}
}

// Função para imprimir lista com todos os carros estacionados
void imprime_carro(PILHA* p, FILA* f)
{
    printf("\n\tPlaca   | Pátio |   Valor a ser pago\n");
	pilha_imprime(p);
	fila_imprime(f);
}

// Menu de Opções
void main_menu(PILHA* p, FILA* f)
{
	int option;
	printf("\n\n");
	printf("\t\t\t\tMENU\n\n");
	printf("\t1 - Registrar Carro\n");
	printf("\t2 - Imprimir Carros\n");
	printf("\t3 - Sair\n");
	printf("\n\tEscolha uma opção: ");
	
	option = read_int();
	
	while(option > 3 || option < 1)
	{
		getchar();
		printf("\n\tEscolha uma opção: ");
		option = read_int();
	}

	switch(option) 
	{
		case(1): 
			insere_carro(p, f);
			break;

		case(2): 
			imprime_carro(p, f);
			break;	

		case(3):
			fila_apagar(&f);
			pilha_apagar(&p);
			exit(0);
			break;
	}

	main_menu(p, f);
}

int main()
{
	//Pátio 1 - Pilha
	//Pátio 2 - Fila
	PILHA* pilha = pilha_criar();
	FILA* fila = fila_criar();
    main_menu(pilha, fila);
    return 0;
}