#include <stdio.h>
#include <stdlib.h>

#include "lista.h"

/* define a struct TAD lista */
struct lista {
	float info;         /* dado */
	struct lista *prox; /* ponteiro para o proximo elemento */
};

/* cria lista vazia */
Lista* lista_cria(void)
{
	return NULL;
}

/* retorna se a lista esta vazia (true), ou false caso contrario */
bool lista_vazia( Lista* l )
{
	return (l == NULL);
}

/* insere ordenado, retorna a lista atualizada */
Lista* lista_insere_ordenado( Lista* l, float info )
{
	Lista* novo;
    Lista* ant;
    Lista* prox;
	int i=0;

    if(l == NULL)//caso seja o primeiro elemento a ser criado da lista
    {
        novo = (Lista*)malloc(sizeof(Lista));
        novo->info = info;
        novo->prox = l;
        return novo;
    }
    else{
        prox = l;
        while(prox != NULL){
                if(info < prox->info){
                                    novo = (Lista*)malloc(sizeof(Lista));
                                    novo->info = info;
                                    novo->prox = prox;
                                    if(i==0) //caso este seja o menor elemento da lista mas nao seja o primeiro
                                        return novo;
                                    else{
                                        ant->prox = novo;
                                        return l;
                                        }
                }

            ant = prox;
            prox = prox->prox;
            i++;
            }
        }
 /* só vira até aqui caso seja o maior numero da lista e não seja o primeiro elemento */
        novo = (Lista*)malloc(sizeof(Lista));
        novo -> info = info;
        novo -> prox = NULL;
        ant->prox = novo;
        return l;
    }


/* busca um elemento na lista e retorna-o caso ele seja encontrado */
Lista* lista_busca( Lista* l, float info )
{
	Lista* p = l;
	while(p != NULL) {
		if(p->info == info)
			return p;
		p = p->prox;
	}

	return NULL;
}

/* percorre os elementos, imprimindo-os */
void lista_imprime( Lista* l )
{
	Lista* p = l;
	while(p != NULL) {
		printf("%.2f\t", p->info);
		p = p->prox;
	}

	printf("\n");
}

/* percorre os elementos recursivamente, imprimindo-os */
void lista_imprime_rec( Lista* l )
{
	if(l != NULL) {
		printf("%.2f\t", l->info);
		lista_imprime_rec(l->prox);
	} else
		printf("\n");
}

/* remove da lista o elemento que contem 'info'. Se lista ficar vazia, retorna NULL.
   Se nao encontrou, retorna a lista 'l'.
   Senao, o elemento removido deve ser liberrado com free.
*/
Lista* lista_remove( Lista* l, float info )
{
	Lista* ant = NULL;
	Lista* p = l;
    int i=0;
	//Procura o elemento
	while(p != NULL && p->info != info) {
		ant = p;
		p = p->prox;
	}

	if(p != NULL) { //Caso encontrado
		if(ant == NULL) //remoção do primeiro elemento
			l = p->prox;
		else //
			ant->prox = p->prox;
        i++;
		free(p);
	}
    if(i)
        printf("Elemento removido\n");
    else
        printf("Elemento não encontrado\n");
	return l;
}

/* libera a memória de cada nó da lista. */
void lista_destroi( Lista* l )
{
	Lista* elem = l;
	while( lista_vazia(elem) == false ){
		Lista* t = elem->prox;
		free(elem);
		elem = t;
	}
}
