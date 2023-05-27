/*
    Função: Calcular o cubo da soma de dois números digitados pelo usuário através de uma função específica para realizar isso.
    Autor: Pedro Peixoto Viana de Oliveira
    Turma: Ciência da Computação - 2º período - Noturno
    Data: 27/03/2023
    Observações: sem observação
*/

#include <stdio.h>

int quadrado(int numero);
int cubo (int numero);
int calcularCuboDaSoma(int x, int y);

int main() {

    int primeiro_termo, segundo_termo;

    printf("CALCULAR O PRODUTO NOTAVEL (CUBO DA SOMA DE DOIS TERMOS)\n\n");
    printf("- Insira o primeiro termo: ");
    scanf(" %d", &primeiro_termo);
    printf("- Insira o segundo termo: ");
    scanf(" %d", &segundo_termo);

    printf("\n- Resultado do produto notavel inserido: %d", calcularCuboDaSoma(primeiro_termo, segundo_termo));
    

    return 0;
}


int quadrado(int numero) {
    return (numero * numero);
}


int cubo(int numero) {
    return (numero * numero * numero);
}


int calcularCuboDaSoma(int x, int y) {
    int resultado = cubo(x) + (3 * quadrado(x) * y) + (3 * x * quadrado(y)) + cubo(y);
    return resultado;
}
