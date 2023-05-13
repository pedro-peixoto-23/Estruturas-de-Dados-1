/*
    Função: Recebe 10 números do usuário e mostra eles na tela
    Autor: Pedro Peixoto Viana de Oliveira
    Turma: Ciência da Computação - 2º período - Noturno
    Data: 11/04/2023
    Observações: sem observações
*/

#include <stdio.h>

#define TAMARRAY 10

int main() {
    
    int numeros[TAMARRAY];

    printf("===== Inserindo %d numeros =====\n\n", TAMARRAY);
    for (int i = 0; i < TAMARRAY; i++) {
        printf("- Insira o %dº numero: ", i + 1);
        scanf(" %d", &numeros[i]);
    }

    printf("\n===== Imprimindo os numeros =====\n");
    for (int i = 0; i < TAMARRAY; i++) {
        printf("\n- %dº numero = %.2d", i + 1, numeros[i]);
    }

    return 0;
}
