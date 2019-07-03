/*
 * ponto.c
 * Implementação da TAD Ponto.
*/
#include <stdio.h>
#include <stdlib.h>

#include "ponto.h"

/* cria um ponto */
Ponto* ponto_cria(float x, float y) {
	Ponto *ponto = (Ponto*) malloc(sizeof(Ponto));
	ponto->x = x;
	ponto->y = y;
	return ponto;
}

/* imprime um ponto */
void imprime_ponto(Ponto *p) {
	printf(" (%.2f,%.2f) ", p->x, p->y);
}

/* imprime um ponto, recebendo um ponteiro genérico */
void imprime_ponto_gen(void *p) {
	if(p == NULL) {
		printf(" ponto NULL");
		return;
	}

	Ponto *ponto = (Ponto*) p;
	imprime_ponto(ponto);
}


/* compara dois pontos */
bool compara_ponto(Ponto *a, Ponto *b) {
	/* compara os pontos aqui */
	if ((a->x == b->x) && (a->y == b->y))
		return true;

	return false;
}

/* compara dois pontos recebidos como ponteiros genéricos */
bool compara_ponto_gen(void *a, void *b) {
	if(a == NULL || b == NULL)
		return false;

	/* primeiro faz typecast dos ponteiros para Ponto */
	Ponto        *p1 = (Ponto *) a;
	Ponto        *p2 = (Ponto *) b;
	return compara_ponto(p1, p2);
}

/* libera um ponto */
void ponto_destroi(Ponto *p) {
	free(p);
}
