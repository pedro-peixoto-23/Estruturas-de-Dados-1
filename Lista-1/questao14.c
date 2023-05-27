/*
    Função: Mostrar os divisores de cada número que o usuário inserir até o mesmo inserir um número negativo.
    Autor: Pedro Peixoto Viana de Oliveira
    Turma: Ciência da Computação - 2º período - Noturno
    Data: 27/03/2023
    Observações: sem observações.
*/

#include <stdio.h>

int main() {

    int numero_usuario;

    printf("Digite um numero positivo para mostrar os divisores ou digite um numero negativo para sair.");

    do {
        printf("\n\n- Digite um numero: ");
        scanf(" %d", &numero_usuario);

        if (numero_usuario < 0) {
            break;
        } else if (numero_usuario == 0) {
            printf("-- O numero \"0\" nao possui divisores!");
        } else {
            printf("-- Divisores do %d: ", numero_usuario);
            for (int i = 1; i <= numero_usuario; i++) {
                if (numero_usuario % i == 0) {
                    printf("%d ", i);
                }
            } 
        }  
    } while (1);

    return 0;
}
