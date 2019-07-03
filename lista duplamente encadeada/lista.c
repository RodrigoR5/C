/*
 * lista.c
 * Implementa��o das TADs Nodo e Sentinela - lista duplamente encadeada.
*/
#include <stdio.h>
#include <stdlib.h>

#include "lista.h"

/* define a struct TAD nodo */
struct nodo
{
    Ponto* dado;        /* ponteiro para o dado da lista Ponto */
    struct nodo *prox; /* ponteiro para o proximo elemento */
    struct nodo *ant;  /* ponteiro para o elemento anterior */
};

/* define a struct TAD sentinela */
struct sentinela
{
    int nItens;          /* n�mero de elementos na lista. Atualizar ao inserir e remover da lista */
    struct nodo *cabeca; /* ponteiro para o primeiro elemento da lista */
    struct nodo *cauda;  /* ponteiro para o �ltimo elemento da lista */
};

/* cria lista vazia */
Sentinela* lista_cria(void)
{
    //M�todo pronto - cria a lista vazia a partir da sentinela
    Sentinela *sentinela = (Sentinela*) malloc(sizeof(Sentinela));
    sentinela->nItens = 0;
    sentinela->cabeca = NULL;
    sentinela->cauda  = NULL;
    return sentinela;
}

/* retorna se a lista esta vazia (true), ou false caso contrario */
bool lista_vazia( Sentinela* l )
{
    if( l->cabeca==NULL )
        return true;
    return false;
}

/* insere no comeco da lista, retornando a lista atualizada */
Sentinela* lista_insere( Sentinela* l, Ponto* ponto )
{
    Nodo* novo = (Nodo*) malloc (sizeof(Nodo));//cria o elemento
    novo->dado = ponto;
    novo->ant = NULL;
    novo->prox = l->cabeca;
    if(l->nItens != 0)//caso existam outros elementos na lista
        l->cabeca->ant = novo;//o ANTIGO primeiro elemento recebe o novo elemento como seu anterior
    l->cabeca = novo;   //altera a cabe�a
    l->nItens++;
    if(l->cauda == NULL)//S� entra no if caso seja o unico elemento da lista
        l->cauda = novo;//Como est� sozinho ele ser� tanto o primeiro quanto ultimo

    return l;
}

/* busca um elemento na lista e retorna-o caso ele seja encontrado
   Para encontrar o ponto, utilize a fun��o compara_ponto().
 */

Nodo* lista_busca( Sentinela* l, Ponto* p )
{
    Nodo* elem = l->cabeca;
    while(elem != NULL)//caso tenha chegado ao fim da lista
    {
        if(compara_ponto(elem->dado, p))//ser� 1 somente se ambos forem iguais
            return elem;
        elem = elem->prox;//responsavel por varrer as listas
    }

    return NULL;//caso n�o tenha achado
}

/* imprime todos os elementos da lista em ordem - come�a da cabe�a da Sentinela */
void lista_imprime_ordem( Sentinela* l )
{
    Nodo* p;//apontara para os elementos que devem ser imprimidos
    int i;
    p = l->cabeca;//aponta para o primeiro elemento que deve ser imprimido
    printf("Come�o da impres�o na ordem \n");
    for(i=0; i < l->nItens ; i++)
    {
        printf("(%0.2f, ", p->dado->x);
        printf("%0.2f)\n", p->dado->y);
        p = p->prox;//responsavel por varrer a lista
    }
    if(l->nItens == 0)
    printf("N�o existem elementos na lista!\n");
    printf("Fim da impres�o na ordem \n");


}

/* imprime todos os elementos da lista em ordem inversa - come�a da cauda da Sentinela */
void lista_imprime_ordem_inv( Sentinela* l )
{
    Nodo* p;//apontara para os elementos que devem ser imprimidos
    int i;
    p = l->cauda;//igual a imprime_ordem, por�m na ordem p= l->cabeca
    printf("Come�o da impres�o na ordem inversa \n");
    for(i=0; i < l->nItens ; i++)
    {
        printf("(%0.2f, ", p->dado->x);
        printf("%0.2f)\n", p->dado->y);
        p = p->ant;//ao contrario da imprime_ordem
    }
    if(l->nItens == 0)
        printf("N�o existem elementos na lista!\n");
    printf("Fim da impres�o na ordem inversa\n");

}

/* remove da lista o elemento que contem o Ponto.
   Se n�o encontrou, retorna 'l'.
   Senao, o elemento removido deve ser liberrado com free.
   ATEN��O: n�o libera mem�ria do ponto.
*/

Sentinela* lista_remove( Sentinela* l, Ponto* p )
{
    Nodo* remover = lista_busca(l,p);
    if(remover == NULL)//caso nao tenha achado
        return l;
    if(remover -> ant == NULL)//caso seja o primeiro elemento
    {
        l->cabeca = remover->prox;
        if(l->cabeca != NULL)//caso nao seja o unico elemento, pois caso fosse o unico a linha de cima teria deixado cabeca == NULL e nao existiria l->cabeca->ant
            l->cabeca->ant = NULL;
        else //caso remover esse elemento tenha deixado a lista vazia
        {
            l->nItens = 1;//pois virar� 0 no final desta fun��o
            l->cabeca = NULL;
            l->cauda  = NULL;
        }

    }
    else if(remover -> prox == NULL) //caso seja o ulimo elemento
    {
        Nodo* ultimo;

        ultimo = remover->ant;
        ultimo->prox = NULL;
        l->cauda = ultimo;//a cauda deve ser alterada pois o ultimo elemento mudou
    }
    else if(remover -> ant != NULL && remover->prox != NULL) //caso o elemento a ser removido esteja no meio
    {//a sentinela nem � mencionada nesse caso
        Nodo* ant, *prox;
        ant = remover->ant;
        prox = remover->prox;
        ant->prox = prox;
        prox->ant = ant;
    }

    l->nItens--;//pois um elemento foi removido, entao o numero de itens diminuiu
    free(remover);
    return l;

}

/* Remove todos os elementos, liberando-os. Liberar tamb�m a sentinela.
   ATEN��O: n�o libera mem�ria do ponto. */
void lista_destroi( Sentinela* l )
{

    Nodo* elem = l->cabeca;
    int i;
    for(i=0; i<l->nItens; i++)//s� sai do while quando a lista estiver vazia
    {
        Nodo* c = elem->prox;//o ponteiro C aponta para o segundo elemento da lista
        free(elem);//o primeiro elemento � deletado
        elem = c;//o segundo elemento passa a ser o primeiro, substituindo o deletado*/
    }
    free(l);
    /*
    l->cabeca = NULL;
    l->cauda = NULL;
    l->nItens = 0;
    */
}
