#ifndef DEQUE_H
#define DEQUE_H

#define boolean int
#define TRUE 1
#define FALSE 0
#define ERROR -32000
#define ITEM char

typedef struct deque_ DEQUE;
typedef struct node_ NODE;

DEQUE *create_deque();
boolean insert_beginning(DEQUE *d, ITEM i);
boolean insert_end(DEQUE *d, ITEM);
NODE *remove_beginning(DEQUE *d);
NODE *remove_end(DEQUE *d);
NODE *get_first(DEQUE *d);
NODE *get_last(DEQUE *d);
int get_size(DEQUE *d);
ITEM get_item(NODE *n);
boolean is_empty(DEQUE *d);
boolean is_full(DEQUE *d);
void print_deque(DEQUE *d);
boolean delete_deque(DEQUE **d);

#endif