/*
    * Função: Mostrar todos os valores da Conjectura de Goldbach entre 700 e 1100.
    * Autor: Pedro Peixoto Viana de Oliveira.
    * Data: 24/maio/2023.
    * Observações: 
*/


#include <stdio.h>
#include <stdlib.h>

int verificarPrimo(int numero);
void gerarOsValoresDaConjecturaDeGoldbach(int* vetor_dois_valores_soma, int numero);
void imprimirSequenciaOsValoresDaConjecturaDeGoldbach(int* vetor_dois_valores_soma, int valor_minimo, int valor_maximo);


int main() {
    
    // Vetor que armazena os dois valores primos que somados dão o valor par informado.
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
    if ((numero > 2) && (numero % 2 == 0)) {
        int dois_valores_encontrados = 0;
        // O primeiro for serve para percorrer todos os primos até o número e serve para saber qual é o primeiro
        // dos dois valores necessários. Já o segundo for serve para percorrer os primos e identificar qual o
        // segundo valor. São testados os dois valores para ver se a soma deles chegaa no número informado. O 
        // segundo for começa com o valor do for anterior, pois os dois valores podem ser iguais. Não é necessário
        // o j começar do primeiro primo existente, pois o i anterior já fez a checagem com o j anterior, então
        // haveria uma redundancia.
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
    } else { // Significa que o valor não é um par maior que 2, então retorna os dois valores zerados.
        vetor_dois_valores_soma[0] = 0;
        vetor_dois_valores_soma[1] = 0;
    }
}

void imprimirSequenciaOsValoresDaConjecturaDeGoldbach(int* vetor_dois_valores_soma, int valor_minimo, int valor_maximo) {
    if (valor_maximo < valor_minimo) {
        printf("ERRO: o valor maximo deve ser maior ou igual ao valor minimo!");
    } else {
        int contador = 0;
        printf("\nImprimindo todos os valores da Conjectura de Goldbach de %d ate %d\n");
        for (int i = valor_minimo; i <= valor_maximo; i++) {
            gerarOsValoresDaConjecturaDeGoldbach(vetor_dois_valores_soma, i);
            if (vetor_dois_valores_soma[0] != 0 && vetor_dois_valores_soma[1] != 0) {
                printf("-------------------------------------------------\n");
                printf("|\t%d:\t\t%d\t+\t%d\t|\n", i, vetor_dois_valores_soma[0], vetor_dois_valores_soma[1]);
                printf("-------------------------------------------------\n");
                contador += 1;
            }
        }

        if (contador == 0) {
            printf("\nAtencao: de %d ate %d nao existem valores da Conjectura de Goldbach!\n", valor_minimo, valor_maximo);
        }
    }
}
