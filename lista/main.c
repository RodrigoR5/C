/* O programa que manipula uma lista simplesmente encadeada que armazena comoinformação números reais (float).*/
/* Código feito por Rodrigo Rech Moraes. rodrigorech@hotmail.com */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "lista.h"


void imprime_menu()
{

    printf("----Menu lista (Digite um número para realizar uma operação)-----\n");
    printf("1- Inserir número na lista de forma ordenada (ler o número a ser inserido)\n");
    printf("2- Retirar número (ler o número a ser retirado da lista)\n");
    printf("3- Buscar número (ler o número, verificando e informando se ele existe na lista)\n");
    printf("4- Imprimir lista\n");
    printf("0- Sair do programa\n");

}


int main(int argc, char **argv)
{
    Lista* lista;
    Lista* busca;
    int opcao = 1;
    float numero;
    lista = lista_cria();

    while(opcao)
    {
        imprime_menu();
        scanf("%d", &opcao);
        switch(opcao){
            case 1:
                printf("Escreva o numero a ser inserido na lista:\n");
                scanf("%f", &numero);
                lista = lista_insere_ordenado( lista, numero );
                break;
            case 2:
                printf("Escreva o numero a ser retirado da lista:\n");
                scanf("%f", &numero);
                lista = lista_remove( lista, numero );
                break;
            case 3:
                printf("Escreva o numero que será buscado na lista:\n");
                scanf("%f", &numero);
                busca = lista_busca( lista, numero );
                if(busca)
                    printf("Elemento encontrado!\n");
                else
                    printf("Nenhum elemento foi encontrado!\n");
                break;
            case 4:
                lista_imprime(lista);

                break;
            case 0:
                lista_destroi(lista);
                break;
            default:
                printf("Operação inválida\n");
        }
    }


    return 0;
}
