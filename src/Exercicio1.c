/*
Considere A uma matriz 10 × 10 de números inteiros gerados aleatoriamente de 1 até 10. Faça um
algoritmo para gerar a matriz A e verificar se ela é ou não Diagonalmente Dominante.
Crie e utilize um procedimento para gerar a matriz A.
Crie e utilize uma função que retorna 1, se A for Diagonalmente Dominante, ou retorna 0 caso contrário.
A impressão da informação (se A é ou não Diagonalmente Dominante) tem que ser na função main.
A matriz utilizada tem que ser declarada na função main.
*/

//Aluno: Felipe Celestino Muros

#include <stdio.h>
#include <stdlib.h>

#define TAM 10

void gerarMatriz(int matriz[TAM][TAM]);
int verificarMatriz(int matriz[TAM][TAM]);

int main()
{
    int matriz[TAM][TAM];
    int i, j;

    gerarMatriz(matriz);

    printf("\nMatriz gerada:\n");
    for (i = 0; i < TAM; i++)
    {
        for (j = 0; j < TAM; j++)
        {
            printf("%d\t", matriz[i][j]);
        }
        printf("\n");
    }

    if (verificarMatriz(matriz) == 1)
    {
        printf("\nA matriz eh diagonalmente dominante.\n");
    }
    else
    {
        printf("\nA matriz nao eh diagonalmente dominante.\n");
    }

    return 0;
}

void gerarMatriz(int matriz[TAM][TAM])
{
    int i, j;

    for (i = 0; i < TAM; i++)
    {
        for (j = 0; j < TAM; j++)
        {
            matriz[i][j] = rand() % 10 + 1;
        }
    }
}

int verificarMatriz(int matriz[TAM][TAM])
{
     int i, j, soma;

    for (i = 0; i < TAM; i++) {
        soma = 0;
        for (j = 0; j < TAM; j++) {
            if (i != j) {
                soma += abs(matriz[i][j]); 
            }
        }
        
        if (abs(matriz[i][i]) <= soma) {
            return 0; 
        }
    }
    
    return 1; 
}