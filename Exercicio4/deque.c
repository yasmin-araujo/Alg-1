#include "deque.h"
#include <stdio.h>
#include <stdlib.h>

struct deque_
{
    NODE *first;
    NODE *last;
    int size;
};

struct node_
{
    NODE *next;
    NODE *previous;
    ITEM item;
};

DEQUE *create_deque()
{
    DEQUE *deque = (DEQUE *)malloc(sizeof(DEQUE));

    if (deque == NULL)
        return NULL;

    deque->first = NULL;
    deque->last = NULL;
    deque->size = 0;

    return deque;
}

boolean insert_beginning(DEQUE *d, ITEM i)
{
    NODE *node = (NODE *)malloc(sizeof(NODE));

    if (node == NULL)
        return FALSE;

    node->item = i;
    node->previous = NULL;
    if (get_size(d) == 0) // Primeiro da Deque
    {
        node->next = NULL;
        d->last = node;
    }
    else
        node->next = d->first;

    d->first = node;
    d->size++;
    return TRUE;
}

boolean insert_end(DEQUE *d, ITEM i)
{
    NODE *node = (NODE *)malloc(sizeof(NODE));

    if (node == NULL)
        return FALSE;

    node->item = i;
    node->next = NULL;

    if (get_size(d) == 0) // Primeiro da Deque
    {
        node->previous = NULL;
        d->first = node;
    }
    else
    {
        node->previous = d->last;
        d->last->next = node;
    }

    d->last = node;
    d->size++;
    return TRUE;
}

NODE *remove_beginning(DEQUE *d)
{
    if (d == NULL)
        return NULL;

    NODE *node = d->first;
    d->first = node->next;
    if (d->last == node) // Se único item da deque
    {
        d->last = NULL;
    }
    else
    {
        d->first->previous = NULL;
    }

    node->next = NULL;
    node->previous = NULL;
    //free(node->item);
    //node->item = NULL;
    //free(node);
    d->size--;

    return node;
}

NODE *remove_end(DEQUE *d)
{
    if (d == NULL)
        return NULL;

    NODE *node = d->last;
    d->last = node->previous;
    if (d->first == node) // Se único item da deque
    {
        d->first = NULL;
    }
    else
    {
        d->last->next = NULL;
    }

    node->next = NULL;
    node->previous = NULL;
    //free(node->item);
    //node->item = NULL;
    //free(node);
    d->size--;
    return node;
}

NODE *get_first(DEQUE *d)
{
    if (d == NULL)
        return NULL;
    return d->first;
}

NODE *get_last(DEQUE *d)
{
    if (d == NULL)
        return NULL;
    return d->last;
}

int get_size(DEQUE *d)
{
    if (d == NULL)
        return ERROR;
    else
        return d->size;
}

ITEM get_item(NODE *n)
{
    if (n == NULL)
        return 0;
    else
        return n->item;
}

boolean is_empty(DEQUE *d)
{
    if (d == NULL)
        return ERROR;
    else if (d->size == 0)
        return TRUE;
    else
        return FALSE;
}

boolean is_full(DEQUE *d);

void print_deque(DEQUE *d)
{
    NODE* no = d->first;
    while(no != NULL)
    {
        printf("%c", no->item);
        no = no->next;
    }
}

boolean delete_deque(DEQUE **d)
{
    if ((*d) == NULL)
        return ERROR;
    while (!is_empty(*d))
    {
        NODE *node = (*d)->first;
        (*d)->first = node->next;
        if ((*d)->last == node) // Se único item da deque
        {
            (*d)->last = NULL;
        }
        else
        {
            (*d)->first->previous = NULL;
        }

        node->next = NULL;
        node->previous = NULL;
        //free(node->item);
        //node->item = NULL;
        free(node);
        (*d)->size--;
    }
    free(*d);
    *d = NULL;
}