/*
    Função: Dado dois horários passados pelo usuário, mostra o intervalo de tempo entre um e outro.
    Autor: Pedro Peixoto Viana de Oliveira
    Turma: Ciência da Computação - 2º período - Noturno
    Data: 27/03/2023
    Observações: sem observações.
*/

#include <stdio.h>
#include <math.h>

int main() {

    int hora1[2], hora2[2];

    printf("Insira o primeiro horário: ");
    printf("\n- Horas: ");
    scanf(" %d", &hora1[0]);
    printf("- Minutos: ");
    scanf(" %d", &hora1[1]);
    printf("Insira o segundo horário: ");
    printf("\n- Horas: ");
    scanf(" %d", &hora2[0]);
    printf("- Minutos: ");
    scanf(" %d", &hora2[1]);

    int intervalo_tempo[2];

    intervalo_tempo[0] = abs(hora1[0] - hora2[0]);
    intervalo_tempo[1] = abs(hora1[1] - hora2[1]);

    printf("O intervalo de tempo entre %d:%d e %d:%d e igual a %d:%d.", hora1[0],hora1[1],hora2[0],hora2[1],intervalo_tempo[0],intervalo_tempo[1]);

    return 0;
}
