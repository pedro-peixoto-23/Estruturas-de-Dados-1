/*
    Função: Calcular o capital acumulado de um valor inicial x e uma taxa de juros anual y em um determinado tempo em anos (juros compostos) através de uma função.
    Autor: Pedro Peixoto Viana de Oliveira
    Turma: Ciência da Computação - 2º período - Noturno
    Data: 27/03/2023
    Observações: sem observações.
*/

#include <stdio.h>

float jurosCompostos(float x, float j, int tempo);

int main() {

    float x = 1500.00, j = 2.5; // x é o capital e j é o juros
    int tempo = 5; // tempo em anos

    printf("Capital total: R$%.2f", jurosCompostos(x, j, tempo));

    return 0;
}


float jurosCompostos(float x, float j, int tempo) {
    float acumulador_capital = x;

    for (int i = 1; i <= tempo; i++) {
        acumulador_capital = acumulador_capital * (1 + (j/100));
    }

    return acumulador_capital;
}