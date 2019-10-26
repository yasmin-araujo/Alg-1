#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"

struct guia_ 
{
	char titulo[40];
	char url[512];
};

struct node_ 
{
	Guia* item;
	Node* next;
};

// Lista simplesmente encadeada, uma vez que economiza a memória dos ponteiros adicionais 
// e o processamento das operações de manipulação dos mesmos, já que é desnecessário percorrer a lista no sentido de volta (final para começo). 
// Como o índice é calculado na contagem ao percorrer a lista, o acesso nunca será feito a partir do final.

struct list_ 
{
	Node* start;
	Node* end;
	int size;
};

int empty(List* l)
{
	if (l->size == 0) // confere se lista não está vazia
		return 1;
	return 0;
}

List* create_list (void) 
{
	List* l = (List*) malloc(sizeof(List));

	l->start = NULL;
	l->end = NULL;
	l->size = 0;

	return l;
}

void insert_registration (List* l, char* titulo, char* url) 
{
	Node* new = (Node*) malloc(sizeof(Node));
	Guia* new_item = (Guia*) malloc(sizeof(Guia));

	if (l->start == NULL) // caso lista ainda esteja vazia
		l->start = new;
	else
		l->end->next = new;
	
	strcpy(new_item->titulo, titulo);
	strcpy(new_item->url, url);

	l->end = new;
	new->item = new_item;
	new->next = NULL;

	l->size++;
}

int busca_titulo(List* l, char* t)
{
	Node* n = l->start;
	int pos = 1;
	while(n != NULL)
	{
		if(strcmp(n->item->titulo, t) == 0) // se achou o titulo retorna sua posição
			return pos;
		n = n->next;
		pos++;
	}
	return 0;
}

void alterar_registro(List* l, int pos_inicial, int pos_final)
{
	pos_inicial--;
	pos_final--;
	Node* n = l->start;
	Node* aux = n;


	// retirar nó da posição atual
	
	for(int i = 0; i < pos_inicial; i++)
	{
		aux = n;
		n = n->next;
	}
	aux->next = n->next;

	if(pos_inicial == 0)
		l->start = n->next;
	if(pos_inicial + 1 == l->size)
		l->end = aux;


	// inserir nó na posição desejada

	if(pos_final + 1 == l->size)
		l->end = n;
	if(pos_final == 0)
	{
		n->next = l->start;
		l->start = n;
		return;
	}
	
	aux = l->start;
	for(int i = 0; i < pos_final - 1; i++)
	{
		aux = aux->next;
	}

	n->next = aux->next;
	aux->next = n;
}

void print_registrations (List* l) 
{	
	if (empty(l))
		return;

	Node* p = l->start;
	
	while (p != NULL) 
	{
		printf("%s", p->item->titulo);			
		printf(" %s\n", p->item->url);			
		p = p->next;
	}
}

void empty_list (Node* p) {
	if (p != NULL) {
		if (p->next != NULL)
			empty_list(p->next);

		free(p->item);
		free(p);
		p = NULL;
	}
}

int size_list (List* l)
{
	return l->size;
}

void delete_list (List** l) {
	if(*l == NULL) return;
	empty_list((*l)->start);
	free(*l);
	*l = NULL;
}
