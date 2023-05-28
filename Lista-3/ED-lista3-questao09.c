/*
    * Função: Ordenar os elementos de um array usando o método chamado "BubbleSort".
    * Autor: Pedro Peixoto Viana de Oliveira
    * Data: 28/maio/2023
    * Observações: 
*/


#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void preencherVetorComValoresAleatorios(int* vetor, int qtd_elementos_vetor);
int* ordenarVetorMetodoBubbleSort(int* vetor, int qtd_elementos_vetor);
void imprimirVetor(char* mensagem, int* vetor, int qtd_elementos_vetor);


int main() {

    int qtd_elementos_vetor;

    printf("Insira a quantidade de elementos do vetor: ");
    scanf(" %d", &qtd_elementos_vetor);

    int vetor[qtd_elementos_vetor];

    srand(time(NULL));
    preencherVetorComValoresAleatorios(vetor, qtd_elementos_vetor);
    imprimirVetor("Vetor antes da ordenacao: ", vetor, qtd_elementos_vetor);

    // vetor_qtd_ifs_trocas[0] -> quantidade de IFs, vetor_qtd_ifs_trocas[1] -> quantidade de trocas.
    int* vetor_qtd_ifs_trocas = ordenarVetorMetodoBubbleSort(vetor, qtd_elementos_vetor);
    imprimirVetor("Vetor depois da ordenacao: ", vetor, qtd_elementos_vetor);
    printf("Quantidade de IFs: %d\n", vetor_qtd_ifs_trocas[0]);
    printf("Quantidade de trocas: %d\n", vetor_qtd_ifs_trocas[1]);

    free(vetor_qtd_ifs_trocas);

    return 0;
}

void preencherVetorComValoresAleatorios(int* vetor, int qtd_elementos_vetor) {
    for (int i = 0; i < qtd_elementos_vetor; i++) {
        int valor = rand() % 50;
        vetor[i] = valor;
    }
}

int* ordenarVetorMetodoBubbleSort(int* vetor, int qtd_elementos_vetor) {
    // Definindo o índice do último elemento.
    int indice_ultimo_elemento = qtd_elementos_vetor - 1;
    // Primeiro elemento é a quantidade de ifs e o segundo o de trocas.
    int* vetor_qtd_ifs_trocas = calloc(2, sizeof(int)); // Usando calloc porque ele faz os elementos começarem com zero.

    // O loop vai continuar até que todos os "últimos elementos" estejam ordenados, ou seja, para quando o último elemento for o primeiro.
    while (indice_ultimo_elemento > 0) {
        for (int i = 0; i < indice_ultimo_elemento; i++) {
            vetor_qtd_ifs_trocas[0] += 1; // Aumentando a qtd. de IFs.
            if (vetor[i] > vetor[i + 1]) {
                int temporario = vetor[i];
                vetor[i] = vetor[i + 1];
                vetor[i + 1] = temporario;
                vetor_qtd_ifs_trocas[1] += 1; // Aumentando a qtd. de trocas.
            }
        }
        indice_ultimo_elemento -= 1;
    }

    return vetor_qtd_ifs_trocas;
}

void imprimirVetor(char* mensagem, int* vetor, int qtd_elementos_vetor) {
    printf("%s\t", mensagem);
    printf("[");
    for (int i = 0; i < qtd_elementos_vetor; i++) {
        printf(" %d", vetor[i]);
    }
    printf(" ]\n");
}
