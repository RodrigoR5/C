#include<stdio.h>
#include<stdlib.h>
/*
Feito por Rodrigo Rech Moraes
rodrigorech@hotmail.com
*/

typedef struct ArvBin
{
    int info;
    struct ArvBin *esq;
    struct ArvBin *dir;
} NO;

// Uma função para criar um novo nó na Árvore de Busca Binária
NO *novoNo(int item)
{
    NO *temp =  (NO *)malloc(sizeof(NO));
    temp->info = item;
    temp->esq = temp->dir = NULL;
    return temp;
}

// Uma função para fazer o percurso EmOrdem na Árvore de Busca Binária
void emordem(NO *raiz)
{
    if (raiz != NULL)
    {
        emordem(raiz->esq);
        printf("%d ", raiz->info);
        emordem(raiz->dir);
    }
}

// Uma função para inserir um novo nó com uma dada chave (info) na Árvore de Busca Binária
NO *insere(NO *no, int info)
{
    // Se a árvore estiver vazia, retorne um novo nó
    if (no == NULL) return novoNo(info);

    // Caso contrário, volte pela árvore
    if (info < no->info)
        no->esq  = insere(no->esq, info);
    else if (info > no->info)
        no->dir = insere(no->dir, info);

    // retorna o ponteiro do nó (inalterado)
    return no;
}

void remove_arvore(NO* raiz, int valor){
    /* Verificando se a arvore está vazia*/
    if(raiz == NULL)
        return;
    NO *atual = raiz;
    NO *ant = NULL;

    /* Procura o elemento a ser removido*/
    while(atual->info != valor){
        ant = atual;
        if(valor < atual->info)
            atual = atual->esq;
        else
            atual = atual->dir;
    }

    if(atual->info == raiz->info){
            raiz = remove_atual(atual);
            return;
    }
    /* Troca o elemento removido */
    if(ant->esq->info == atual->info){
        ant->esq = remove_atual(atual);
    }
    if(ant->dir->info == atual->info){
        ant->dir = remove_atual(atual);
    }

    return;

}

int remove_atual(NO* atual){
    NO *no1, *no2;
    /* Remove os elementos que são folhas
    ou elementos com apenas um filho*/
    if(atual->dir == NULL || atual->esq == NULL){
            if(atual->esq == NULL){
                no2 = atual->esq;
                free(atual);
                return no2;
            }
            //Só vira até aqui caso o ultimo elemento esteja na direita
                no2 = atual->dir;
                free(atual);
                return no2;
    }

    /* Remove elementos com dois filhos:
    primeiramente procura o elemento mais a direita da subarvore a esquerda
    para troca-lo com o elemento a ser removido*/
    no1 = atual;
    no2 = atual->esq;
    while(no2->dir != NULL){
                no1 = no2;
                no2 = no2->dir;
    }

    if(no1 != atual){
        no1->dir = no2->esq;
        no2->esq = atual->esq;
    }
     no2->dir = atual->dir;
     free(atual);
     return no2;
    }
void pre_ordem(NO* raiz){
    if(raiz == NULL)
        return;
    if(raiz != NULL){
        printf("%d ", raiz->info);
        pre_ordem(raiz->esq);
        pre_ordem(raiz->dir);
    }

}

void pos_ordem(NO* raiz){
    if(raiz == NULL)
        return;
    if(raiz != NULL){
        pos_ordem(raiz->esq);
        pos_ordem(raiz->dir);
        printf("%d ", raiz->info);
    }
}
// Teste das funções
int main()
{


    NO *raiz = NULL;
    raiz = insere(raiz, 50);
    insere(raiz, 30);
    insere(raiz, 20);
    insere(raiz, 40);
    insere(raiz, 70);
    insere(raiz, 60);
    insere(raiz, 80);
    printf("raiz= %d\n", raiz->info);

    printf("\nÁrvore de Busca Binária: Inserção e Percurso;\n\n");
    printf("\nValores inseridos: 50, 30, 20, 40, 70, 60 e 80.\n\n");
    printf("Escreva um valor para remover da arvore:\n");
    int n;
    scanf("%d", &n);
    remove_arvore(raiz, n);

    printf("Percurso em pré-ordem");
    pre_ordem(raiz);
    printf("\n");
    printf("Percurso em pós-ordem");
    pos_ordem(raiz);
    printf("\n");
    printf("Percurso Em Ordem: ");
    emordem(raiz);

    return 0;

}
