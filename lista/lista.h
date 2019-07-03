/*
 * lista.h
 * Definição da TAD Lista.
 */
#ifndef _LISTA_H_
#define _LISTA_H_

#include <stdbool.h>

/* define o tipo Lista, derivado da 'struct _lista' */
typedef struct lista Lista;

/* cria uma lista vazia, ou seja, retorna NULL */
Lista* lista_cria(void);

/* insere ordenado, retorna a lista atualizada */
Lista* lista_insere_ordenado( Lista* l, float info );

/* retorna se a lista esta vazia (true), ou false caso contrario */
bool lista_vazia( Lista* l );

/* busca um elemento na lista e retorna-o caso ele seja encontrado */
Lista* lista_busca( Lista* l, float info );

/* percorre os elementos, imprimindo-os */
void lista_imprime( Lista* l );

/* percorre os elementos recursivamente, imprimindo-os */
void lista_imprime_rec( Lista* l );

/* remove da lista o elemento que contem 'info'. Se lista ficar vazia, retorna NULL.
   Se nao encontrou, retorna a lista 'l'.
   Senao, o elemento removido deve ser liberrado com free.
*/
Lista* lista_remove( Lista* l, float info );

/* libera a memória de cada nó da lista. */
void lista_destroi( Lista* l );

#endif
