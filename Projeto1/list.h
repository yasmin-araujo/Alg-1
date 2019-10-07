#ifndef STUDENT_H
    #define STUDENT_H

    typedef struct student_ Student;
    typedef struct node_ Node;
    typedef struct list_ List;
    
    int read_int();
    
    float read_float();
    
    /* Função que determina se lista está vazia */
    int empty(List* l);

    /* Função que calcula a média aritmética de dois valores */
    float average (float a, float b);

    /* Função para determinação da aprovação de um aluno */
    int approved (Node* p);

    /* Função para inicialização de uma lista */
    List* create_list (void);
    
    /* Função para inserção de registro */
    void insert_registration (int id, float hour, float g1, float g2, List* l);

    /* Função para remoção de registro a partir de ID */
    void remove_registration (int id, List* l);
    
    /* Função para impressão de todos os registros */
    void print_registrations (List* l);
    
    /* Função para exibir a situação de aprovação de todos os alunos */
    void approval_report (List* l);
    
    /* Função que calcula a média das horas de estudo da turma */
    void study_time(List* l);
    
    /* Função que libera nós da lista recursivamente */
    void empty_list(Node *p);

    /* Função que apaga toda a lista */
    void delete_list(List** l);

#endif
