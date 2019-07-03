/*
 * ponto.c
 * Implementação da TAD Ponto.
*/
#include <stdio.h>
#include <stdlib.h>

#include "ponto.h"

/* cria um ponto */
Ponto* ponto_cria(float x, float y)
{
    Ponto *ponto = (Ponto*) malloc(sizeof(Ponto));
    ponto->x = x;
    ponto->y = y;
    return ponto;
}

/* imprime um ponto */
void imprime_ponto(Ponto *p)
{
    printf(" (%.2f,%.2f) ", p->x, p->y);
}

/* compara dois pontos */
bool compara_ponto(Ponto *a, Ponto *b)
{
    /* primeiro faz typecast dos ponteiros para Ponto */
    Ponto        *p1 = (Ponto *) a;
    Ponto        *p2 = (Ponto *) b;

    /* compara os pontos aqui */
    if ((p1->x == p2->x) && (p1->y == p2->y))
        return true;

    return false;
}

/* libera um ponto */
void ponto_destroi(Ponto *p)
{
    free(p);
}
