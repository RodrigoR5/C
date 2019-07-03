/*
    C�digo tem como objetivo administrar pilhas por meio de listas e uma struct pilha.
    rodrigorech@hotmail.com
 */
#include <stdio.h>
#include <stdlib.h>

#include "pilha.h"

/* estrutura TAD Lista */
struct _lista {
	void* dado;
	struct _lista* prox;
};

typedef struct _lista Lista;

/* define a struct TAD pilha */
struct _pilha {
	Lista* primeiro;
};

/* cria uma pilha vazia, sendo:
 * - alocar mem�ria para a pilha (chamar malloc)
 * - inicializar o topo (primeiro) da lista com NULL (vazia)
 * - retornar a pilha criada
 */
Pilha* pilha_cria (void)
{
	Pilha *pilha = (Pilha*) malloc(sizeof(Pilha));
	pilha->primeiro = NULL;
	return pilha;
}

/* retorna se a pilha esta vazia (true), ou false caso contrario. Verificar o valor do primeiro elemento */
bool pilha_vazia( Pilha* p )
{
	if(p->primeiro == NULL)//se n�o existe topo ent�o a pilha est� vazia
        return true;
    else
        return false;
}

/* insere um elemento (dado) na pilha, sendo:
 - aloca mem�ria para um novo elemento da lista
 - insere o elemento na primeira posi��o da lista
 */
void pilha_empilha( Pilha* p, void* dado )
{
    Lista* novo = (Lista*) malloc(sizeof(Lista));
    novo->dado = dado;
    novo->prox = p->primeiro; //o novo elemento aponta para o antigo topo
    p->primeiro = novo; //o topo � atualizado


}

/* retira o elemento do topo da pilha, sendo:
 * - verificar se a pilha est� vazia (chamar fun��o pilha_vazia)
 * - armazenar o dado removido para ser retornado
 * - retirar o primeiro elemento da lista e liberar a mem�ria.
 * - retornar o valor removido
 */
void* pilha_desempilha( Pilha* p )
{
	if(!pilha_vazia(p)) {
        Lista* remove;
        void* dadoremovido;
        remove = p->primeiro;//remove = topo
        p->primeiro = p->primeiro->prox; //o topo foi alterado
        dadoremovido = remove->dado;//dado que foi removido e deve ser retornado
        free(remove);
        return(dadoremovido);
	}

	return NULL;
}

/* libera a mem�ria de todos os elementos e da pr�pria pilha */
void pilha_destroi( Pilha* p )
{
    Lista* remover;

	while(!pilha_vazia(p)){
        remover = p->primeiro;//remover = topo
        p->primeiro = p->primeiro->prox;// topo = novo topo
        free(remover);// antigo topo removido
	}

    free(p);
}

/* imprime os elementos da pilha */
void pilha_imprime( Pilha* p, void (*imprime)(void*) )
{
	if(! pilha_vazia(p)) {
        Lista* seleciona;
        seleciona = p->primeiro;
        while(seleciona != NULL){//varre a lista
            imprime(seleciona->dado);
            seleciona = seleciona->prox;
        }
	} else {
		printf("ERRO! N�o � poss�vel imprimir. Pilha vazia.\n");
	}
}
