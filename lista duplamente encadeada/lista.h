/*
 * lista.h
 * Definição das TADs Nodo e Sentinela - lista duplamente encadeada.
 */
#ifndef _LISTA_H_
#define _LISTA_H_

#include <stdbool.h>
#include "ponto.h"

/* define o tipo Nodo, derivado da 'struct nodo' */
typedef struct nodo Nodo;

/* define o tipo Sentinela, derivado da 'struct sentinela' */
typedef struct sentinela Sentinela;

/* cria nodo vazia */
Sentinela* lista_cria(void);

/* retorna se a lista esta vazia (true), ou false caso contrario */
bool lista_vazia( Sentinela* l );

/* insere no comeco da lista, retornando a lista atualizada */
Sentinela* lista_insere( Sentinela* l, Ponto* ponto );

/* busca um elemento na lista e retorna-o caso ele seja encontrado
   Para encontrar o ponto, utilize a função compara_ponto().
 */
Nodo* lista_busca( Sentinela* l, Ponto* p );

/* imprime todos os elementos da lista em ordem - começa da cabeça da Sentinela */
void lista_imprime_ordem( Sentinela* l );

/* imprime todos os elementos da lista em ordem inversa - começa da cauda da Sentinela */
void lista_imprime_ordem_inv( Sentinela* l );

/* remove da lista o elemento que contem o Ponto.
   Se não encontrou, retorna 'l'.
   Senao, o elemento removido deve ser liberrado com free.
   ATENÇÃO: não libera memória do ponto.
*/
Sentinela* lista_remove( Sentinela* l, Ponto* p );

/* Remove todos os elementos, liberando-os. Liberar também a sentinela.
   ATENÇÃO: não libera memória do ponto. */
void lista_destroi( Sentinela* l );


#endif
