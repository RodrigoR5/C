#include <stdio.h>
#include <stdlib.h>
/*
Código feito por Rodrigo Rech Moraes. rodrigorech@hotmail.com
O código recebe uma matriz e retorna se ela é triangular superior ou não
*/
int matriz_triangular_superior(int* mat, int n)
{
    int i,i2;
for(i=0; i<n; i++) //apenas matrizes triangulares superiores sairão deste FOR
    {
        for(i2=0; i2<n; i2++)
        {
            if(i>i2) //apenas elementos abaixo da diagonal principal serão analisados
            {
                if(mat[i*n+i2] != 0)//se algum dos elementos abaixo da diagonal principal forem !=0, o retorno será 0
                    return 0;
            }
        }
    }
    return 1;
}
int main()
{
    int i, i2, linhas, colunas, resultado;
    printf("Escreva o numero de linhas da matriz:\n");
    scanf("%d", &linhas);
    colunas = linhas; //para deixar o código mais legível
    int *matriz = (int*) calloc (linhas * colunas, sizeof(int));
    if(! matriz) //verifica se a memoria nao foi alocada
    {
        ("A memória não conseguiu ser alocada\n");
        return 0;
    }
    printf("Escreva os elementos da matriz\n");
    for(i=0; i<linhas; i++)
    {
        for(i2=0; i2<colunas; i2++)
            scanf("%d", &matriz[i*linhas+i2]);
        printf("linha %d completa\n", (i+1));
    }
    resultado = matriz_triangular_superior(matriz, linhas);
    if(resultado == 0)
        printf("A matriz não é triangular superior\n");
    else
        printf("A matriz é triangular e superior\n");
free(matriz);
    return 0;
}
