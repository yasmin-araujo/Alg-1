#include <stdio.h>
#include <stdlib.h>
#include "list.h"

struct student_ 
{
	int id;
	float hours;
	float first_grade;
	float second_grade;
};

struct node_ 
{
	Student* item;
	Node* next;
};

struct list_ 
{
	Node* start;
	Node* end;
	int size;
};

int read_int()
{
	int opt, status;

	status = scanf(" \n%d", &opt);

	if(status)
		return opt;
	else
		return -1;
}

float read_float()
{
	float opt;
	int status;

	status = scanf(" \n%f", &opt);

	if(status)
		return opt;
	else
		return -1;
}

int empty(List* l)
{
	if (l->size == 0) //confere se lista não está vazia
	{
		printf("\tNão há nenhum registro.");
		return 1;
	}
	return 0;
}

float average (float a, float b) 
{
	return (a + b) / 2;
}

int approved (Node* p) 
{
	float g1 = p->item->first_grade;
	float g2 = p->item->second_grade;
	return (average(g1, g2) >= 5);
}

List* create_list (void) 
{
	List* l = (List*) malloc(sizeof(List));

	l->start = NULL;
	l->end = NULL;
	l->size = 0;

	return l;
}

void insert_registration (int id, float hour, float g1, float g2, List* l) 
{
	Node* new = (Node*) malloc(sizeof(Node));
	Student* new_item = (Student*) malloc(sizeof(Student));

	if (l->start == NULL) //caso lista ainda esteja vazia
		l->start = new;
	else
		l->end->next = new;
	
	new_item->id = id;
	new_item->hours = hour;
	new_item->first_grade = g1;
	new_item->second_grade = g2;

	l->end = new;
	new->item = new_item;
	new->next = NULL;

	l->size++;
}

void remove_registration (int id, List* l)
{
	if (empty(l))
		return;

	Node *p, *q;
	p = l->start; 
	q = p;

	while (p != NULL && id != p->item->id)
	{
		q = p; 
		p = p->next;
	}

	if (p == NULL) //caso o item não exista
		return;

	if (l->start == p) //caso item seja o primeiro da lista	
		l->start = p->next;

	if(p->next == NULL) //caso item seja o ultimo da lista
		l->end = q;

	q->next = p->next;

	free(p->item);
	free(p);

	l->size--;

	if(l->size == 0) //caso lista fique vazia
	{
		l->start = NULL;
		l->end = NULL;
	}
}

void print_registrations (List* l) 
{
	if (empty(l))
		return;

	printf("\tID\t| Horas de estudo |\tNota 1\t|\tNota 2\n");
	printf("\t-----------------------------------------------------------\n");
	Node* p = l->start;
	
	while (p != NULL) 
	{
		printf("\t%d\t|\t", p->item->id);			
		printf("%.2f\t  |\t", p->item->hours);			
		printf("%.2f\t|\t" , p->item->first_grade);			
		printf("%.2f\n", p->item->second_grade);
		p = p->next;
	}
}

void approval_report (List* l) 
{
	if (empty(l))
		return;

	printf("\tID\t|\tAprovação\n");
	printf("\t--------------------------------\n");
	for (Node* p = l->start; p != NULL; p = p->next) 
	{
		printf("\t%d\t|\t", p->item->id);
		if (approved(p)) 
			printf("Aprovado\n");
		else 
			printf("Reprovado\n");
	}
}

void study_time (List* l)
{
	if (empty(l))
		return;
		
	float total = 0;
	Node* p = l->start;
	while(p != NULL)
	{
		total += p->item->hours;
		p = p->next;
	}
	total /= l->size;

	printf("\tTempo médio de estudo da turma: %.2f\n", total);
}

void empty_list (Node* p) {
	if (p != NULL) {
		if (p->next != NULL)
			empty_list(p->next);

		free(p);
		p = NULL;
	}
}

void delete_list (List** l) {
	if(*l == NULL) return;
	empty_list((*l)->start);
	free(*l);
	*l = NULL;
}
