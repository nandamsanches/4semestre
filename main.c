/*  Fernanda Sanches
    Myrna Shuman
    Ci�ncias da Computa��o*/

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

    /*fun��o recursiva para reconstruir a �rvore bin�ria a partir dos percursos em-ordem e p�s-ordem*/
    make_tree(&t, op, 0, eo, 0, po);

    /* insere a funcao pre ordem  */
    pre_ordem(t);
	printf("\n");
    return 0;
}

