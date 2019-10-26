#ifndef LISTA_H
    #define LISTA_H

    typedef struct guia_ Guia;
    typedef struct node_ Node;
    typedef struct list_ List;
    
    /* Função que determina se lista está vazia */
    int empty(List* l);

    /* Função para inicialização de uma lista */
    List* create_list (void);
    
    /* Função para inserção de registro */
    void insert_registration (List* l, char* titulo, char* url);
    
    /* Função para a alteração dos registros */
    void alterar_registro(List* l, int pos_inicial, int pos_final);

    /* Função para a busca do índice de acordo com o título */
    int busca_titulo(List* l, char* t);

    /* Função para impressão de todos os registros */
    void print_registrations (List* l);

    /* Função que retorna o tamanho atual da lista */
    int size_list (List* l);
    
    /* Função que libera nós da lista recursivamente */
    void empty_list(Node *p);

    /* Função que apaga toda a lista */
    void delete_list(List** l);

#endif
