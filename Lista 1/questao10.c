/*
    Função: Dado uma distancia em kilometros e um tempo em horas, determina quanto percorreu em apenas uma hora.
    Autor: Pedro Peixoto Viana de Oliveira
    Turma: Ciência da Computação - 2º período - Noturno
    Data: 27/03/2023
    Observações: sem observações.
*/

#include <stdio.h>

float calculaVM(float espaco, float tempo);


int main() {
    
    float distancia_Km = 400.5; // distancia dado em kilometros
    float tempo_horas = 4.5; // tempo dado em horas

    printf("A distancia percorrida em apenas uma hora e de: %.2fKm/h", calculaVM(400.5, 4.5));

    return 0;
}


float calculaVM(float espaco, float tempo) {
    return (espaco/tempo);
}