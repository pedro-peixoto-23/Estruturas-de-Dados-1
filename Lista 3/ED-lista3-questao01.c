/*
    * Função: Ordenar os elementos de um array usando o método de "Classificação por seleção"
    * Autor: Pedro Peixoto Viana de Oliveira
    * Data: 22/maio/2023
    * Observações: 
*/


#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void preencherArrayComValoresAleatorios(int* vetor, int qtd_elementos_vetor);
void classificarElementosMetodoSelecao(int* vetor, int qtd_elementos_vetor);
void imprimirVetor(char* mensagem, int* vetor, int qtd_elementos_vetor);

int main() {
    int tamanho_vetor = 5;
    int vetor[tamanho_vetor];
    srand(time(NULL));
    preencherArrayComValoresAleatorios(vetor, tamanho_vetor);
    imprimirVetor("Dados antes da ordenacao: ", vetor, tamanho_vetor);
    classificarElementosMetodoSelecao(vetor, tamanho_vetor);
    printf("\n");
    imprimirVetor("Dados depois da ordenacao: ", vetor, tamanho_vetor);

    return 0;
}

void preencherArrayComValoresAleatorios(int* vetor, int qtd_elementos_vetor) {
    for (int i = 0; i < qtd_elementos_vetor; i++) {
        int valor = rand() % 50;
        vetor[i] = valor;
    }
}

void classificarElementosMetodoSelecao(int* vetor, int qtd_elementos_vetor) {
    // for usado para indicar onde começa o subvetor, delimitando o seu espaço
    for (int indice_inicio_subvetor = 0; indice_inicio_subvetor < qtd_elementos_vetor; indice_inicio_subvetor++) { 
        int menor_elemento_subvetor = vetor[indice_inicio_subvetor];
        int indice_menor_elemento_subvetor = indice_inicio_subvetor;
        // percorrendo os elementos do subvetor e procurando o menor elemento dentro dele
        for (int i = indice_inicio_subvetor; i < qtd_elementos_vetor; i++) { 
            if (vetor[i] < menor_elemento_subvetor) {
                menor_elemento_subvetor = vetor[i];
                indice_menor_elemento_subvetor = i;
            }
        }
        // permutando o menor elemento do subvetor com o primeiro elemento do subvetor
        int temporario = vetor[indice_inicio_subvetor];
        vetor[indice_inicio_subvetor] = menor_elemento_subvetor;
        vetor[indice_menor_elemento_subvetor] = temporario;
    }
}

void imprimirVetor(char* mensagem, int* vetor, int qtd_elementos_vetor) {
    printf("%s\t", mensagem);
    printf("[");
    for (int i = 0; i < qtd_elementos_vetor; i++) {
        printf(" %d", vetor[i]);
    }
    printf(" ]");
}
