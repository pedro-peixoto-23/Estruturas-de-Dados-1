/*
    Função: Mostra os n primeiros números de Fibonacci usando Arrays.
    Autor: Pedro Peixoto Viana de Oliveira
    Turma: Ciência da Computação - 2º período - Noturno
    Data: 11/04/2023
    Observações: sem observações
*/

#include <stdio.h>

int main() {

    int qtd_numeros_fibonacci;

    printf("- Insira a quantidade de numeros que serao mostrados: ");
    scanf(" %d", &qtd_numeros_fibonacci);

    if (qtd_numeros_fibonacci > 0) {
        int numeros_fibonacci[qtd_numeros_fibonacci];

        numeros_fibonacci[0] = 0;
        numeros_fibonacci[1] = 1;
        
        for (int i = 2; i < qtd_numeros_fibonacci; i++) {
            numeros_fibonacci[i] = numeros_fibonacci[i-1] + numeros_fibonacci[i-2];
        }

        printf("\n- Os %d primeiros numeros de fibonacci: ");
        for (int i = 0; i < qtd_numeros_fibonacci; i++) {
            printf("%d ", numeros_fibonacci[i]);
        }
    } else {
        printf("- Insira numeros maiores do que 0!");
    }

    return 0;
}
