/*
    Função: Dado um valor passado pelo usuário, informa todos os valores de fibonacci até o valor digitado.
    Autor: Pedro Peixoto Viana de Oliveira
    Turma: Ciência da Computação - 2º período - Noturno
    Data: 29/03/2023
    Observações: sem observações.
*/

#include <stdio.h>
#include <math.h>

float calcularNumeroFibonacciViaPosicao(int posicao);

int main() {

    int numero_maximo_fibonacci, numero_fibonacci;

    printf("Insira o numero de parada para a sequencia de fibonacci: ");
    scanf(" %d", &numero_maximo_fibonacci);

    printf("- Sequencia fibonacci ate no maximo %d: ", numero_maximo_fibonacci);
    for (int i = 1; i <= numero_maximo_fibonacci; i++) {
        numero_fibonacci = calcularNumeroFibonacciViaPosicao(i);

        if (numero_fibonacci > numero_maximo_fibonacci) {
            break;
        } else {
            printf("%.0f ", calcularNumeroFibonacciViaPosicao(i));
        }
    }

    return 0;
}


float calcularNumeroFibonacciViaPosicao(int posicao) {
    double razao_aurea = 1.6180339887498;
    float numero_fibonacci = (pow(razao_aurea, posicao) - (pow(-razao_aurea, -posicao))) / sqrt(5.0);
    return numero_fibonacci;
}
