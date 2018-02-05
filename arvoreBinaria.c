#include "arvoreBinaria.h"
#include <stdio.h>
#include <stdlib.h>

/* Inicializa a ABB */
void tree_init(arvbin * t)
{
    *t = NULL;
}

/* Insere um novo elemento x na ABB t */
void tree_ins(arvbin * t, tree_info x)
{
    if (*t == NULL)
    {
        if ((*t = (arvbin) malloc(sizeof(struct no_arvbin))) == NULL)
        {
            fprintf(stderr,"Erro de alocação de memória!\n");
            exit(1);
        }
        (*t)->dado = x;
        (*t)->esq = (*t)->dir = NULL;
    }




}

/* Realiza o percurso em­ordem da árvore binária t */
void em_ordem(arvbin t)
{
    if (t != NULL)
    {
        em_ordem(t->esq);  /* visita a subárvore esquerda*/
        printf("%d ", t->dado); /* processa a raiz*/
        em_ordem(t->dir);  /* visita a subárvore direita*/
    }
}

/* Realiza o percurso pré­-ordem da árvore binária t */
void pre_ordem(arvbin t)
{
    if (t != NULL)
    {
        printf("%d ", t->dado); /* processa a raiz*/
        pre_ordem(t->esq); /* visita a subárvore esquerda*/
        pre_ordem(t->dir); /* visita a subárvore direita*/
    }
}

/* Realiza o percurso pós-ordem da árvore binária t */
void pos_ordem(arvbin t)
{
    if (t != NULL)
    {
        pos_ordem(t->esq); /* visita a subárvore esquerda*/
        pos_ordem(t->dir); /* visita a subárvore direita*/
        printf("%d ", t->dado); /* processa a raiz*/
    }
}

/* função recursiva para reconstruir a árvore binária a
partir dos percursos em-ordem e pós-ordem*/

void make_tree(arvbin * t, int op, int eo_i, int eo[], int po_i, int po[])
{

    /*acha raiz pos ordem*/
    int raiz_po;
    raiz_po = po[op +po_i -1];

    /*procura a raiz na em ordem e armazena a posicao da raiz*/
    int pos_eo;
    int i;
    for(i = 0; i < op; i++)
    {
        if(eo[i+eo_i] == raiz_po)
        {
            //raiz_eo = eo[i];
            pos_eo = i;
        }
    }
    /*inserir na pre ordem*/
    tree_ins(&(*t), raiz_po);
    if(pos_eo > 0)
    {
        make_tree(&(*t)->esq, pos_eo, eo_i + 0, eo, po_i + 0, po);
    }

    if(pos_eo < op-1)
    {

        /* =( */
        /*int vet[op], po2[op];
        int j = 1;
        for(i = pos_eo + 1; i <= op; i++){
            vet[j] = eo[i];
            j++;
        }

        for(i = pos_eo; i < op; i++){
            po2[i] = po[i];
        }*/
        make_tree(&(*t)->dir, op-pos_eo-1, eo_i+pos_eo+1, eo, pos_eo+po_i, po);

    }

    /*se for no folha*/
    if(pos_eo == op)
        tree_ins(&(*t), raiz_po);
}

