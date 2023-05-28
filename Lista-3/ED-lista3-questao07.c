/*
    * Função: Ordenar os elementos de um array usando o método chamado "QuickSort".
    * Autor: Pedro Peixoto Viana de Oliveira.
    * Data: 27/maio/2023.
    * Observações: 
*/


#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void preencherVetorComValoresAleatorios(int* vetor, int qtd_elementos_vetor);
int particionarVetorMetodoQuickSort(int* vetor, int inicio, int fim);
void ordenarVetorMetodoQuickSort(int* vetor, int inicio, int fim);
void imprimirVetor(char* mensagem, int* vetor, int qtd_elementos_vetor);


int main() {

    int qtd_elementos_vetor = 5;
    int vetor[qtd_elementos_vetor];

    srand(time(NULL));
    preencherVetorComValoresAleatorios(vetor, qtd_elementos_vetor);
    imprimirVetor("Vetor antes da ordenacao: ", vetor, qtd_elementos_vetor);
    ordenarVetorMetodoQuickSort(vetor, 0, qtd_elementos_vetor - 1);
    imprimirVetor("Vetor depois da ordenacao: ", vetor, qtd_elementos_vetor);

    return 0;
}

void preencherVetorComValoresAleatorios(int* vetor, int qtd_elementos_vetor) {
    for (int i = 0; i < qtd_elementos_vetor; i++) {
        int valor = rand() % 50;
        vetor[i] = valor;
    }
}

int particionarVetorMetodoQuickSort(int* vetor, int inicio, int fim) {
    // Definindo o elemento base.
    int indice_elemento_base = (inicio + fim) / 2; // Retorna o índice central, caso seja par, arredonda para baixo.
    int elemento_base = vetor[indice_elemento_base];

    // Defindo os ponteiros que apontarão para os elementos a esquerda e direita do elemento base.
    int ponteiro_esquerdo = inicio;
    int ponteiro_direito = fim;

    // O loop só vai parar quando o ponteiro esquerdo for maior que o ponteiro direito.
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

    // Mudando o novo índice do elemento base, que agora será o ponteiro (esquerdo - 1), pois o ponteiro está um índice na frente do elem. base.
    indice_elemento_base = ponteiro_esquerdo - 1;

    // Retornando o índice novo do elemento base.
    return indice_elemento_base;
}

void ordenarVetorMetodoQuickSort(int* vetor, int inicio, int fim) {
    int indice_elemento_base;
    if (fim > inicio) {
        indice_elemento_base = particionarVetorMetodoQuickSort(vetor, inicio, fim);
        // Ordenando as duas metades
        ordenarVetorMetodoQuickSort(vetor, inicio, indice_elemento_base);
        ordenarVetorMetodoQuickSort(vetor, indice_elemento_base + 1, fim);
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
