/*
    * Função: Programa que mostre todos os valores da Conjectura de Goldbach entre 700 e 1100
    * Autor: Pedro Peixoto Viana de Oliveira
    * Data: 24/maio/2023
    * Observações: 
*/


#include <stdio.h>
#include <stdlib.h>

int verificarPrimo(int numero);
void gerarOsValoresDaConjecturaDeGoldbach(int* vetor_dois_valores_soma, int numero);
void imprimirSequenciaOsValoresDaConjecturaDeGoldbach(int* vetor_dois_valores_soma, int valor_minimo, int valor_maximo);


int main() {
    
    // Vetor que armazena os dois valores primos que somados dão o valor par informado
    int* dois_valores_conjectura = malloc(2 * sizeof(int));
    int valor_minimo = 700;
    int valor_maximo = 1100;
    
    imprimirSequenciaOsValoresDaConjecturaDeGoldbach(dois_valores_conjectura, valor_minimo, valor_maximo);

    free(dois_valores_conjectura);

    return 0;
}

int verificarPrimo(int numero) {
    int qtd_divisores = 0;

    for (int i = 1; i <= numero; i++) {
        if (numero % i == 0) {
            qtd_divisores += 1;
        }
    }

    if (qtd_divisores == 2) {
        return 1;
    } else {
        return 0;
    }
}

void gerarOsValoresDaConjecturaDeGoldbach(int* vetor_dois_valores_soma, int numero) {
    int dois_valores_encontrados = 0;
    for (int i = 2; i < numero; i++) {
        if (verificarPrimo(i) == 0) continue;
        for (int j = i; j < numero; j++) {
            if (verificarPrimo(j) == 0) continue;
            if ((i + j) == numero) {
                vetor_dois_valores_soma[0] = i;
                vetor_dois_valores_soma[1] = j;
                dois_valores_encontrados = 1;
            }
            if (dois_valores_encontrados == 1) break;
        }
        if (dois_valores_encontrados == 1) break;
    }
}

void imprimirSequenciaOsValoresDaConjecturaDeGoldbach(int* vetor_dois_valores_soma, int valor_minimo, int valor_maximo) {
    if (valor_minimo <= 2 || valor_maximo <= 2) {
        printf("- Insira apenas valores pares maiores que 2!\n");
    } else if (valor_minimo % 2 != 0 || valor_maximo % 2 != 0) {
        printf("- Insira apenas valores pares!\n");
    } else if (valor_minimo > valor_maximo) {
        printf("- O valor maximo precisa ser maior ou igual ao valor minimo!\n");
    } else {
        for (int i = valor_minimo; i <= valor_maximo; i+=2) {
            gerarOsValoresDaConjecturaDeGoldbach(vetor_dois_valores_soma, i);
            printf("-------------------------------------\n");
            printf("| %d:\t\t%d\t+\t%d |\n", i, vetor_dois_valores_soma[0], vetor_dois_valores_soma[1]);
            printf("-------------------------------------\n");
        }
    }
}
