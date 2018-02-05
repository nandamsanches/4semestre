#ifndef _ARVOREBINARIA_H
#define _ARVOREBINARIA_H
#include <stdbool.h>

typedef int tree_info;
typedef struct no_arvbin * arvbin;
struct no_arvbin {
    arvbin esq;
    tree_info dado;
    arvbin dir;
};

/* Inicializa a ABB */
void tree_init(arvbin *);

/* Insere um novo elemento na ABB */
void tree_ins(arvbin *, tree_info);

/* Realiza o percurso em­ordem da árvore binária */
void em_ordem(arvbin);

/* Realiza o percurso pré­ordem da árvore binária */
void pre_ordem(arvbin);

/* Realiza o percurso pós­ordem da árvore binária */
void pos_ordem(arvbin);
/* função recursiva para reconstruir a árvore binária a
partir dos percursos em-ordem e pós-ordem*/
void make_tree(arvbin * , int, int , int[] , int , int[] );

#endif

