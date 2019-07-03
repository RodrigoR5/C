/*
 * lista.h
 * Defini��o das TADs Nodo e Sentinela - lista duplamente encadeada.
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
   Para encontrar o ponto, utilize a fun��o compara_ponto().
 */
Nodo* lista_busca( Sentinela* l, Ponto* p );

/* imprime todos os elementos da lista em ordem - come�a da cabe�a da Sentinela */
void lista_imprime_ordem( Sentinela* l );

/* imprime todos os elementos da lista em ordem inversa - come�a da cauda da Sentinela */
void lista_imprime_ordem_inv( Sentinela* l );

/* remove da lista o elemento que contem o Ponto.
   Se n�o encontrou, retorna 'l'.
   Senao, o elemento removido deve ser liberrado com free.
   ATEN��O: n�o libera mem�ria do ponto.
*/
Sentinela* lista_remove( Sentinela* l, Ponto* p );

/* Remove todos os elementos, liberando-os. Liberar tamb�m a sentinela.
   ATEN��O: n�o libera mem�ria do ponto. */
void lista_destroi( Sentinela* l );


#endif
