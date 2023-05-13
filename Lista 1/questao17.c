/*
    Função: Programa simples, usado para calcular um arranjo.
    Autor: Pedro Peixoto Viana de Oliveira
    Turma: Ciência da Computação - 2º período - Noturno
    Data: 27/03/2023
    Observações: sem observações.
*/

#include <stdio.h>

int calcularFatorial(int numero);
double calcularNumeroArranjos(int n, int r);


int main() {

    int n = 10, r = 5; // n objetos diferentes, r objetos escolhidos de cada vez

    printf("O numero de arranjos e igual a: %f", calcularNumeroArranjos(n, r));

    return 0;
}


int calcularFatorial(int numero) {
    int resultado = 1;
    for (int i = 1; i <= numero; i++) {
        resultado *= i;
    }
    return resultado;
}


double calcularNumeroArranjos(int n, int r) {
    return (calcularFatorial(n) / calcularFatorial(n-r));
}