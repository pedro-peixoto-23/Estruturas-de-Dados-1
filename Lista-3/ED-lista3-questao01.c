/*
    * Função: Ordenar os elementos de um array usando o método chamado "Classificação por seleção" ou "Selection Sort".
    * Autor: Pedro Peixoto Viana de Oliveira.
    * Data: 22/maio/2023.
    * Observações: 
*/


#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void preencherVetorComValoresAleatorios(int* vetor, int qtd_elementos_vetor);
void ordenarVetorMetodoSelectionSort(int* vetor, int qtd_elementos_vetor);
void imprimirVetor(char* mensagem, int* vetor, int qtd_elementos_vetor);


int main() {

    int qtd_elementos_vetor = 5;
    int vetor[qtd_elementos_vetor];

    srand(time(NULL));
    preencherVetorComValoresAleatorios(vetor, qtd_elementos_vetor);
    imprimirVetor("Vetor antes da ordenacao: ", vetor, qtd_elementos_vetor);
    ordenarVetorMetodoSelectionSort(vetor, qtd_elementos_vetor);
    imprimirVetor("Vetor depois da ordenacao: ", vetor, qtd_elementos_vetor);

    return 0;
}

void preencherVetorComValoresAleatorios(int* vetor, int qtd_elementos_vetor) {
    for (int i = 0; i < qtd_elementos_vetor; i++) {
        int valor = rand() % 50;
        vetor[i] = valor;
    }
}

void ordenarVetorMetodoSelectionSort(int* vetor, int qtd_elementos_vetor) {
    // For usado para indicar onde começa o subvetor, delimitando o seu espaço.
    for (int indice_inicio_subvetor = 0; indice_inicio_subvetor < qtd_elementos_vetor; indice_inicio_subvetor++) { 
        int menor_elemento_subvetor = vetor[indice_inicio_subvetor];
        int indice_menor_elemento_subvetor = indice_inicio_subvetor;
        // Percorrendo os elementos do subvetor e procurando o menor elemento dentro dele.
        for (int i = indice_inicio_subvetor; i < qtd_elementos_vetor; i++) { 
            if (vetor[i] < menor_elemento_subvetor) {
                menor_elemento_subvetor = vetor[i];
                indice_menor_elemento_subvetor = i;
            }
        }
        // Permutando o menor elemento do subvetor com o primeiro elemento do subvetor.
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
    printf(" ]\n");
}
