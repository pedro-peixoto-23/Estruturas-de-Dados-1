/*
    Função: Lê n notas do usuário e calcula a média dessas notas. O valor n é passado pelo usuário.
    Autor: Pedro Peixoto Viana de Oliveira
    Turma: Ciência da Computação - 2º período - Noturno
    Data: 11/04/2023
    Observações: sem observações
*/

#include <stdio.h>

int main() {

    int qtd_notas;

    printf("- Insira a quantidade de notas voce vai inserir: ");
    scanf(" %d", &qtd_notas);

    float notas[qtd_notas], soma_notas, media_notas;

    for (int i = 0; i < qtd_notas; i++) {
        printf("- Insira a nota %d: ", i + 1);
        scanf(" %f", &notas[i]);

        soma_notas += notas[i];
    }

    media_notas = soma_notas / qtd_notas;

    printf("\n| A media das notas e igual a: %.1f", media_notas);

    return 0;
}
