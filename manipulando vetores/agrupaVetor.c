#include <stdio.h>
#include <stdlib.h>
/*
C�digo criado por Rodrigo Rech Moraes. rodrigorech@hotmail.com
O c�digo recebe dois vetores, v1 e v2, e retorna um terceiro vetor, que � a jun��o de v1 e v2
*/
int* uniao(int *v1, int n1, int *v2, int n2)
{
    int tamanhov3, i, i2=0, i3 =0;
    tamanhov3=n1+n2;//criado para deixar o c�digo mais compreens�vel
    int* v3 = (int*) calloc (tamanhov3, sizeof(int));
    if(!v3) //testa se a mem�ria foi alocada
    {
        printf("N�o foi poss�vel alocar a mem�ria\n");
        return 0;
    }
for(i=0; i<tamanhov3; i++) //passa os elementos de v1 e v2 para v3
    {
        if(i<n1)
        {
            v3[i] = v1[i2];
            i2++;
        }
        else
        {
            v3[i] = v2[i3];
            i3++;
        }
    }
    return v3;
}
int main()
{
    int i, tamanhov1, tamanhov2;
printf("Digite no tamanho do vetor 1:\n");
    scanf("%d", &tamanhov1);
    printf("Digite no tamanho do vetor 2:\n");
    scanf("%d", &tamanhov2);
int v1[tamanhov1], v2[tamanhov2]; //Estes dois n�o s�o alocados dinamicamente
    printf("Escreva os %d elementos do vetor 1: \n", tamanhov1);
    for(i=0; i<tamanhov1; i++) //L� os elementos do vetor 1
        scanf("%d", &v1[i]);
    printf("Escreva os %d elementos do vetor 2: \n", tamanhov2);
    for(i=0; i<tamanhov2; i++)
        scanf("%d", &v2[i]);//L� os elementos do vetor 2
    int* p;
    p = uniao(v1, tamanhov1, v2, tamanhov2);
    if(!p)//ser� verdadeiro se a mem�ria n�o foi alocada
        return 0;
    printf("Resultado: ");
    for(i=0; i<(tamanhov1+tamanhov2); i++) //printa o vetor criado na fun��o uniao
        printf("%i", *(p++));
    free(p);
return 0;
}
