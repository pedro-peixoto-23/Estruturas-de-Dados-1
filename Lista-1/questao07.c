/*
    Função: Calcular a distância entre dois pontos (a e b), cada um com suas respectivas coordenadas x e y, através da fórmula (raiz((x2 - x1)² + (y2 - y1)²)).
    Autor: Pedro Peixoto Viana de Oliveira
    Turma: Ciência da Computação - 2º período - Noturno
    Data: 27/03/2023
    Observações: sem observações.
*/

#include <stdio.h>
#include <math.h>

int quadrado(int numero);

int main() {

    int a[] = {2, 3};
    int b[] = {4, 5};

    float distancia_AB = sqrt(quadrado(b[0] - a[0]) + quadrado(b[1] - a[1]));

    printf("- A distancia entre os dois pontos e: %f", distancia_AB);
    
    return 0;
}


int quadrado(int numero) {
    return (numero * numero);
}