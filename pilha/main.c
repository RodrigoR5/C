/*
    Código tem como objetivo administrar pilhas por meio de listas e uma struct pilha.
    rodrigorech@hotmail.com
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "pilha.h"
#include "ponto.h"

int main(int argc, char **argv)
{
	Pilha *pilha;
	Ponto *p1;
	Ponto *p2;
	Ponto *p3;
	Ponto *p4;
	Ponto *p5;

	/* cria os pontos */
	printf("Criando os pontos...\n");
	p1 = ponto_cria(1.2, 1.0);
	p2 = ponto_cria(2.7, 2.9);
	p3 = ponto_cria(3.1, 3.6);
	p4 = ponto_cria(4.1, 4.3);
	p5 = ponto_cria(5.2, 5.4);

	/* cria a pilha */
	pilha = pilha_cria();

	/* insere os pontos na pilha */
	printf("Inserindo os pontos na pilha (P1, P2, P3)...\n");
	pilha_empilha(pilha, p1);
	pilha_empilha(pilha, p2);
	pilha_empilha(pilha, p3);

	/* imprime a pilha com os elementos */
	printf("\nPilha atual (deve imprimir P3, P2 e P1, nesta ordem):\n");
	pilha_imprime( pilha, imprime_ponto_gen );

	/* remove P3 e P2 */
	printf("\nRemovendo topo da pilha (P3)...\n");
	if(compara_ponto_gen(pilha_desempilha(pilha), p3))
		printf("SUCESSO! Topo da pilha (P3) foi removido.\n");
	else
		printf("ERRO! O topo da pilha (P3) não foi removido corretamente.\n");

	printf("\nRemovendo topo da pilha (P2)...\n");
	if(compara_ponto_gen(pilha_desempilha(pilha), p2))
		printf("SUCESSO! Topo da pilha (P2) foi removido.\n");
	else
		printf("ERRO! O topo da pilha (P2) não foi removido corretamente.\n");

	/* imprime a pilha com os elementos */
	printf("\nPilha atual (deve impmir apenas o P1):\n");
	pilha_imprime( pilha, imprime_ponto_gen );

	/* insere novos pontos */
	printf("\nInserindo os pontos na pilha (P2, P3, P4, P5)...\n");
	pilha_empilha(pilha, p2);
	pilha_empilha(pilha, p3);
	pilha_empilha(pilha, p4);
	pilha_empilha(pilha, p5);

	/* imprime a pilha com os elementos */
	printf("\nPilha atual (deve imprimir P5, P4, P3, P2 e P1, nesta ordem):\n");
	pilha_imprime( pilha, imprime_ponto_gen );

	/* remove P5 e P4 */
	printf("\nRemovendo topo da pilha (P5)...\n");
	if(compara_ponto_gen(pilha_desempilha(pilha), p5))
		printf("SUCESSO! Topo da pilha (P5) foi removido.\n");
	else
		printf("ERRO! O topo da pilha (P5) não foi removido corretamente.\n");

	printf("\nRemovendo topo da pilha (P4)...\n");
	if(compara_ponto_gen(pilha_desempilha(pilha), p4))
		printf("SUCESSO! Topo da pilha (P4) foi removido.\n");
	else
		printf("ERRO! O topo da pilha (P4) não foi removido corretamente.\n");

	/* imprime a pilha com os elementos */
	printf("\nPilha atual (deve imprimir P3, P2 e P1, nesta ordem):\n");
	pilha_imprime( pilha, imprime_ponto_gen );

	/* libera a memória */
	printf("\nLiberando a memória...\n");
	pilha_destroi(pilha);

	free(p1);
	free(p2);
	free(p3);
	free(p4);
	free(p5);

	return 0;
}
