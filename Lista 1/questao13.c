/*
    Função: Converte um determinado angulo em graus para radiano.
    Autor: Pedro Peixoto Viana de Oliveira
    Turma: Ciência da Computação - 2º período - Noturno
    Data: 27/03/2023
    Observações: sem observações.
*/

#include <stdio.h>

#define PI 3.14159265

float converterGrauRadiano(float angulo);


int main() {
    
    float angulo = 15.0;

    printf("O angulo %f em radianos e igual a: %f", angulo, converterGrauRadiano(angulo));

    return 0;
}


float converterGrauRadiano(float angulo) {
    return (angulo * PI / 180);
}
