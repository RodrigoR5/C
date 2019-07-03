/*
  O programa consegue inserir pontos x e y em uma lista, imprimi-los na ordem correta ou na inversa. Remover um ponto escolhido da lista e verificar se ela está vazia.
  Além de liberar os espaços na memória
  idealizado por Rodrigo Rech Moraes         rodrigorech@hotmail.com
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#include "lista.h"
#include "ponto.h"

int main(int argc, char **argv)
{
    Sentinela *sentinela;
    Ponto *p1, *p2, *p3, *p4;

    /* cria a lista */
    sentinela = lista_cria();

    /* cria pontos e os insere na lista */
    printf("Criando e inserindo os elementos (P1 a P4)...\n");
    p4 = ponto_cria(4.0, 4.0);
    sentinela = lista_insere(sentinela, p4);

    p3 = ponto_cria(3.0, 3.0);
    sentinela = lista_insere(sentinela, p3);

    p2 = ponto_cria(2.0, 2.0);
    sentinela = lista_insere(sentinela, p2);

    p1 = ponto_cria(1.0, 1.0);
    sentinela = lista_insere(sentinela, p1);

    /* imprime todos */
    printf("\nLista inicial (deve imprimir os pontos 1, 2, 3 e 4)...\n");
    lista_imprime_ordem( sentinela );
    lista_imprime_ordem_inv( sentinela );

    /* remove primeiro elemento */
    printf("\nRemovendo P1 (primeiro elemento)...\n");
    sentinela = lista_remove(sentinela, p1);
    if(! lista_busca(sentinela, p1))
        printf("SUCESSO! P1 foi removido.\n");
    else
        printf("ERRO! P1 continua na lista.\n");

    /* remove elemento do meio */
    printf("Removendo P3 (elemento do meio)...\n");
    sentinela = lista_remove(sentinela, p3);
    if(! lista_busca(sentinela, p3))
        printf("SUCESSO! P3 foi removido.\n");
    else
        printf("ERRO! P3 continua na lista.\n");

    /* remove último elemento */
    printf("Removendo P4 (último elemento)...\n");
    sentinela = lista_remove(sentinela, p4);
    if(! lista_busca(sentinela, p4))
        printf("SUCESSO! P4 foi removido.\n");
    else
        printf("ERRO! P4 continua na lista.\n");

    /* remove último elemento */
    printf("Removendo P2...\n");
    sentinela = lista_remove(sentinela, p2);
    if(! lista_busca(sentinela, p2))
        printf("SUCESSO! P2 foi removido.\n");
    else
        printf("ERRO! P2 continua na lista.\n");

    /* imprime todos */
    printf("\nLista após remoção (deve imprimir a lista vazia)...\n");
    lista_imprime_ordem( sentinela );
    lista_imprime_ordem_inv( sentinela );

    printf("\nInserindo P1...\n");
    sentinela = lista_insere(sentinela, p1);
    if(lista_busca(sentinela, p1))
        printf("SUCESSO! P1 foi inserido.\n");
    else
        printf("ERRO! P1 não econtrado.\n");

    printf("Inserindo P3...\n");
    sentinela = lista_insere(sentinela, p3);
    if(lista_busca(sentinela, p3))
        printf("SUCESSO! P3 foi inserido.\n");
    else
        printf("ERRO! P3 não econtrado.\n");

    /* imprime todos */
    printf("\nLista final (deve imprimir os pontos P1 e P3)...\n");
    lista_imprime_ordem( sentinela );
    lista_imprime_ordem_inv( sentinela );

    /* libera a memória */
    printf("\nLiberando a memória...\n");
    lista_destroi(sentinela);


    ponto_destroi(p1);
    ponto_destroi(p2);
    ponto_destroi(p3);
    ponto_destroi(p4);



    return 0;
}
