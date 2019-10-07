//Ana Luisa Teixeira Costa #11218963
//Yasmin Osajima de Araujo #11219004
#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include "list.h"

void insert_reg(List* lst)
{
	int id;
	float hrs, g1, g2;
	printf("\n\n\t\t\tINSERÇÃO DE REGISTRO\n\n");
	printf("\tPreencha as informações abaixo: \n");
	
	printf("\n\tId Aluno: ");
	id = read_int();
	while(id < 0)
	{
		getchar();
		printf("\n\tId Aluno: ");
		id = read_int();
	}
	
	printf("\n\tHoras de estudo: ");
	hrs = read_float();
	while(hrs < 0)
	{
		getchar();
		printf("\n\tHoras de estudo: ");
		hrs = read_float();
	}
	
	printf("\n\tPrimeira nota: ");
	g1 = read_float();
	while(g1 < 0)
	{
		getchar();
		printf("\n\tPrimeira nota: ");
		g1 = read_float();
	}

	printf("\n\tSegunda nota: ");
	g2 = read_float();
	while (g2 < 0)
	{
		getchar();
		printf("\n\tSegunda nota: ");
		g2 = read_float();
	}
	
	insert_registration(id, hrs, g1, g2, lst);
}

void remove_reg(List* lst)
{
	int id;
	printf("\n\n\t\t\tREMOÇÃO DE REGISTRO\n\n");
	
	if (empty(lst))
		return;

	printf("\tDigite o ID a ser removido: ");
	id = read_int();
	while(id < 0)
	{
		getchar();
		printf("\n\tDigite o ID a ser removido: ");
		id = read_int();
	}
	remove_registration(id, lst);
}

void print_reg(List* lst)
{
	printf("\n\n\t\t\tIMPRESSÃO DE REGISTROS\n\n");
	print_registrations(lst);
}

void reports(List* lst)
{
	printf("\n\n\t\t\tRELATÓRIO DE APROVAÇÕES\n\n");
	approval_report(lst);
}

void time(List* lst)
{
	printf("\n\n\t\t\tTEMPO DE ESTUDO\n\n");
	study_time(lst);
}

void options(int opt, List* lst)
{
	void main_menu(List* lst);

	switch(opt) 
	{
		case(1): 
			insert_reg(lst);
			break;

		case(2): 
			remove_reg(lst);
			break;	

		case(3): 
			print_reg(lst);
			break;

		case(4): 
			reports(lst);
			break;

		case(5): 
			time(lst);
			break;

		case(6):
			delete_list(&lst);
			exit(0);
			break;
	}
	main_menu(lst);
}

void main_menu(List* lst)
{
	int option;

	printf("\n\n");
	printf("\t\t\t\tMENU\n\n");
	printf("\t1 - Inserir Registro\n");
	printf("\t2 - Remover Registro\n");
	printf("\t3 - Imprimir Registros\n");
	printf("\t4 - Relatório de Aprovação\n");
	printf("\t5 - Tempo de Estudo\n");
	printf("\t6 - Sair\n");
	printf("\n\tEscolha uma opção: ");
	
	option = read_int();
	
	while(option > 6 || option < 1)
	{
		getchar();
		printf("\n\tEscolha uma opção: ");
		option = read_int();
	}

	options(option, lst);
}

int main(void) 
{
	List* lst = create_list();
	setlocale(LC_ALL,"Portuguese");
	main_menu(lst);	
}
