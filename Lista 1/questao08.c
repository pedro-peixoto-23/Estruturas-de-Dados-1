/*
    Função: Calcular a area de uma esfera sabendo o raio através de uma função.
    Autor: Pedro Peixoto Viana de Oliveira
    Turma: Ciência da Computação - 2º período - Noturno
    Data: 27/03/2023
    Observações: sem observações.
*/

#include <stdio.h>

#define PI 3.14159265 // definindo a constante pi

float quadrado(float numero);
double calcularAreaEsfera(float raio);


int main() {

    float raio = 5.0;

    printf("- A area da esfera (com raio igual a %.2f) e igual a: %lf", raio, calcularAreaEsfera(raio));
    
    return 0;
}


float quadrado(float numero) {
    return (numero * numero);
}


double calcularAreaEsfera(float raio) {
    return (4 * PI * quadrado(raio));
}
