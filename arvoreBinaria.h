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

/* Realiza o percurso em�ordem da �rvore bin�ria */
void em_ordem(arvbin);

/* Realiza o percurso pr�ordem da �rvore bin�ria */
void pre_ordem(arvbin);

/* Realiza o percurso p�s�ordem da �rvore bin�ria */
void pos_ordem(arvbin);
/* fun��o recursiva para reconstruir a �rvore bin�ria a
partir dos percursos em-ordem e p�s-ordem*/
void make_tree(arvbin * , int, int , int[] , int , int[] );

#endif

