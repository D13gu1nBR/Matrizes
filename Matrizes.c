#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define qtdlinhas 100
#define qtdcolunas 100

void lerMatriz(int mat[][qtdcolunas], int lin, int col);
void preencherMatrizAleatoria(int mat[][qtdcolunas], int lin, int col);
void imprimirMatriz(int mat[][qtdcolunas], int lin, int col);
int lerNumeroDentroIntervalo(int min, int max);
void contarNumerosImpares(int mat[][qtdcolunas], int lin, int col);
void buscarNumeroNaMatriz(int mat[][qtdcolunas], int lin, int col);
void calcularSomaTotal(int mat[][qtdcolunas], int lin, int col);
void calcularMediaTotal(int mat[][qtdcolunas], int lin, int col);
void calcularMediaPorLinha(int mat[][qtdcolunas], int lin, int col);

int main() {
    int qtdLinhas, qtdColunas;
    int matriz[qtdlinhas][qtdcolunas];
    printf("Digite a quantidade de linhas (1-%d): ", qtdlinhas);
    qtdLinhas = lerNumeroDentroIntervalo(1, qtdlinhas);
    printf("Digite a quantidade de colunas (1-%d): ", qtdcolunas);
    qtdColunas = lerNumeroDentroIntervalo(1, qtdcolunas);
    preencherMatrizAleatoria(matriz, qtdLinhas, qtdColunas);
    imprimirMatriz(matriz, qtdLinhas, qtdColunas);
    contarNumerosImpares(matriz, qtdLinhas, qtdColunas);
    printf("\n");
    buscarNumeroNaMatriz(matriz, qtdLinhas, qtdColunas);
    printf("A soma de todos os valores da matriz é: ");
    calcularSomaTotal(matriz, qtdLinhas, qtdColunas);
    calcularMediaTotal(matriz, qtdLinhas, qtdColunas);
    printf("\n");
    calcularMediaPorLinha(matriz, qtdLinhas, qtdColunas);

    return 0;
}

void lerMatriz(int mat[][qtdcolunas], int lin, int col) {
    for (int i = 0; i < lin; ++i) {
        for (int j = 0; j < col; ++j) {
            printf("Digite mat[%d][%d]: ", i, j);
            scanf("%d", &mat[i][j]);
        }
    }
}

void preencherMatrizAleatoria(int mat[][qtdcolunas], int lin, int col) {
    for (int i = 0; i < lin; ++i) {
        for (int j = 0; j < col; ++j) {
            mat[i][j] = rand() % 100 + 1;
        }
    }    
}

void imprimirMatriz(int mat[][qtdcolunas], int lin, int col) {
    for (int i = 0; i < lin; ++i) {
        for (int j = 0; j < col; ++j) {
            printf("%d \t", mat[i][j]);
        }
        printf("\n");
    }
}

int lerNumeroDentroIntervalo(int min, int max) {
    int valor;
    scanf("%d", &valor);
    while (valor < min || valor > max) {
        printf("Valor inválido! Digite um valor entre %d e %d: ", min, max);
        scanf("%d", &valor);
    }
    return valor;
}

void contarNumerosImpares(int mat[][qtdcolunas], int lin, int col) {
    int impares = 0;
    for (int i = 0; i < lin; ++i) {
        for (int j = 0; j < col; ++j) {
            if (mat[i][j] % 2 != 0) {
                impares++;
            }
        }
    }

    printf("A quantidade de números ímpares é: %d", impares);
}

void buscarNumeroNaMatriz(int mat[][qtdcolunas], int lin, int col) {
    int numero;
    int encontrado = 0;
    printf("Digite o número que deseja procurar: ");
    scanf("%d", &numero);

    for (int i = 0; i < lin; ++i) {
        for (int j = 0; j < col; ++j) {
            if (mat[i][j] == numero) {
                printf("Número %d encontrado na linha %d, coluna %d\n", numero, i + 1, j + 1);
                encontrado = 1;
            }
        }
    }
    if (!encontrado) {
        printf("O número não foi encontrado");
    }
}

void calcularSomaTotal(int mat[][qtdcolunas], int lin, int col) {
    int soma = 0;
    for (int i = 0; i < lin; ++i) {
        for (int j = 0; j < col; ++j) {
            soma += mat[i][j];
        }
    }
    printf("%d \n", soma);
}

void calcularMediaTotal(int mat[][qtdcolunas], int lin, int col) {
    int somaTotal = 0;
    int totalElementos = lin * col;
    for (int i = 0; i < lin; ++i) {
        for (int j = 0; j < col; ++j) {
            somaTotal += mat[i][j];
        }
    }
    float mediaTotal = (float)somaTotal / totalElementos;
    printf("Média total de todos os elementos da matriz é: %.2f", mediaTotal);
}

void calcularMediaPorLinha(int mat[][qtdcolunas], int lin, int col) {
    for (int i = 0; i < lin; ++i) {
        int soma = 0;
        for (int j = 0; j < col; ++j) {
            soma += mat[i][j];
        }
        float media = (float)soma / col;
        printf("Média da linha %d: %.2f\n", i + 1, media);
    }
}
