/*
 * pilha.h
 * Definição da TAD Pilha - pilha com lista.
 */
#ifndef _PILHA_H_
#define _PILHA_H_

#include <stdbool.h>

/* define o tipo Pilha, derivado da 'struct _pilha' */
typedef struct _pilha Pilha;

Pilha* pilha_cria (void);

bool pilha_vazia( Pilha* p );

void pilha_empilha( Pilha* p, void* dado );

void* pilha_desempilha( Pilha* p );

void pilha_destroi( Pilha* p );

void pilha_imprime( Pilha* p, void (*imprime)(void*) );

#endif
