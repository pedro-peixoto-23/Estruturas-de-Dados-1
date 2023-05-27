/*
    * Função: 
    * Autor: Pedro Peixoto Viana de Oliveira
    * Data: 22/maio/2023
    * Observações: 
*/

// 7. Implemente uma função que classifica os elementos de um vetor em ordem crescente
// usando o algoritmo “quicksort”, que pode ser estabelecido da forma a seguir:
// 1. Seja m o elemento do vetor que ocupa a posição “central” no vetor;
// 2. Seja i o índice do primeiro e j o índice do último elemento do vetor;
// 3. Enquanto i for menor ou igual a j , faça com que:
// O valor de i aumente até encontrar um elemento maior do que m ;
// O valor de j diminua até encontrar um elemento menor que m ;
// Haja troca entre os elementos que ocupam as posições i e j ;
// 4. Ao final desses passos a situação do vetor será a seguinte: à esquerda da posição
// central, existem somente elementos menores que m e à direita da posição central,
// existem somente elementos maiores que m .


#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void preencherArrayComValoresAleatorios(int* vetor, int qtd_elementos_vetor);
int particionarVetorQuickSort(int* vetor, int inicio, int fim);
void ordenarVetorQuickSort(int* vetor, int inicio, int fim);


int main() {
    srand(time(NULL));

    int vetor[8];
    int tamanho_vetor = sizeof(vetor) / sizeof(vetor[0]);
    preencherArrayComValoresAleatorios(vetor, tamanho_vetor);

    printf("Array antes da funcao: ");
    for (int i = 0; i < tamanho_vetor; i++) {
        printf("%d ", vetor[i]);
    }

    printf("\n");

    ordenarVetorQuickSort(vetor, 0, tamanho_vetor - 1);

    printf("Array Depois da funcao: ");
    for (int i = 0; i < tamanho_vetor; i++) {
        printf("%d ", vetor[i]);
    }

    return 0;
}

void preencherArrayComValoresAleatorios(int* vetor, int qtd_elementos_vetor) {
    for (int i = 0; i < qtd_elementos_vetor; i++) {
        int valor = rand() % 50;
        vetor[i] = valor;
    }
}

int particionarVetorQuickSort(int* vetor, int inicio, int fim) {
    // Definindo o elemento base.
    int indice_elemento_base = (inicio + fim) / 2; // Retorna o índice central, caso seja par, arredonda para baixo.
    int elemento_base = vetor[indice_elemento_base];

    // Defindo os ponteiros que apontarão para os elementos a esquerda e direita do elemento base.
    int ponteiro_esquerdo = inicio;
    int ponteiro_direito = fim;

    // O loop só vai parar quando o ponteiro esquerdo for maior que o ponteiro direito, ou seja, 
    while (ponteiro_esquerdo <= ponteiro_direito) {
        // Enquanto o ponteiro esquerdo não encontrar um elemento maior ou igual ao elemento base, ele vai continuar percorrendo o array.
        // Isso é necessário, porque os elementos do lado esquerdo do elemento base não podem ser maior que ele.
        while (vetor[ponteiro_esquerdo] < elemento_base) {
            ponteiro_esquerdo += 1;
        }

        // O lado direito do elemento base deve estar ocupado com elementos maiores que ele, então, quando encontrar um elemento menor que ele,
        // significa que o elemento está no local errado. Dessa forma, enquanto não encontrar um elemento menor, ele vai decrescendo e percor-
        // rendo o array de trás para frente.
        while (vetor[ponteiro_direito] > elemento_base) {
            ponteiro_direito -= 1;
        }

        // Se o ponteiro esquerdo for menor que o ponteiro direito, significa que foi encontrado dois valores que estão nos lugares incorretos.
        // Dessa forma, eles irão permutar entre si.
        if (ponteiro_esquerdo <= ponteiro_direito) {
            int temporario = vetor[ponteiro_esquerdo];
            vetor[ponteiro_esquerdo] = vetor[ponteiro_direito];
            vetor[ponteiro_direito] = temporario;

            // Avançando os ponteiros. Isso porque eu já fiz a atribuição, então os índices anteriores já não
            // são mais necessários.
            ponteiro_esquerdo += 1;
            ponteiro_direito -= 1;
        }
    }

    // Retornando o índice novo do elemento base.
    return ponteiro_esquerdo;
}

void ordenarVetorQuickSort(int* vetor, int inicio, int fim) {
    int indice_elemento_base;
    if (fim > inicio) {
        indice_elemento_base = particionarVetorQuickSort(vetor, inicio, fim);
        ordenarVetorQuickSort(vetor, inicio, indice_elemento_base - 1);
        ordenarVetorQuickSort(vetor, indice_elemento_base, fim);
    }    
}
