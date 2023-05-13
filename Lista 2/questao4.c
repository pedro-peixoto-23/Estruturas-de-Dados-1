/*
    Função: Exibe os 50 primeiros números ímpares guardados em um array.
    Autor: Pedro Peixoto Viana de Oliveira
    Turma: Ciência da Computação - 2º período - Noturno
    Data: 11/04/2023
    Observações: sem observações
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int gerarValorAleatorio(int valor_maximo);

int main() {

    int numeros[100], qtd_impares = 0;
    srand(time(NULL));

    // Preenchendo o array
    for (int i = 0; i < (sizeof(numeros)/sizeof(numeros[0])); i++) {
        numeros[i] = gerarValorAleatorio(100);
    }

    for (int i = 0; i < (sizeof(numeros)/sizeof(numeros[0])); i++) {
        if (qtd_impares >= 50) {
            break;
        } else if ((numeros[i] % 2) != 0) {
            qtd_impares += 1;
            printf("Impar %.2d: %d\n", qtd_impares, numeros[i]);
        }
        
    }

    return 0;
}


int gerarValorAleatorio(int valor_maximo) {
    return rand() % (valor_maximo + 1);
}
