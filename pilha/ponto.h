/*
 * ponto.h
 * Definição da TAD Ponto.
 */
#ifndef _PONTO_H_
#define _PONTO_H_

#include <stdbool.h>

/* define a struct TAD ponto */
struct ponto {
	float x;
	float y;
};

/* define o tipo Ponto, derivado da 'struct ponto' */
typedef struct ponto Ponto;

/* cria um ponto */
Ponto* ponto_cria(float x, float y);

/* imprime um ponto */
void imprime_ponto(Ponto *p);

/* imprime um ponto, recebendo um ponteiro genérico */
void imprime_ponto_gen(void *p);

/* compara dois pontos */
bool compara_ponto(Ponto *a, Ponto *b);

/* compara dois pontos recebidos como ponteiros genéricos */
bool compara_ponto_gen(void *a, void *b);

/* libera um ponto */
void ponto_destroi(Ponto *p);

#endif
