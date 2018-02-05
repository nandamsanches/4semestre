/*  Fernanda Sanches
    Myrna Shuman
    Ciências da Computação*/

#include "arvoreBinaria.h"
#include <stdio.h>

int main()
{
    arvbin t;
    /* o n do trabalho */
    int op;
    scanf("%d", &op);

    int eo[op], po[op];
    int i;
    /*insere no vetor os elementos em ordem */

    for(i=0; i<op; i++)
    {
        scanf("%d", &eo[i]);

    }

    /*insere no vetor os elementos pos ordem */

    for(i=0; i<op; i++)
    {
        scanf("%d", &po[i]);

    }
    /*inicializa a arvore */
    tree_init(&t);

    /*função recursiva para reconstruir a árvore binária a partir dos percursos em-ordem e pós-ordem*/
    make_tree(&t, op, 0, eo, 0, po);

    /* insere a funcao pre ordem  */
    pre_ordem(t);
	printf("\n");
    return 0;
}

