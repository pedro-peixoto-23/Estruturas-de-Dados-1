/*
    Função: Dado um material radioativo, em gramas, que perde metade da sua massa a cada 50 segundos, mostra a quantidade de horas, minutos e segundos necessários para que ele fique menor que 0.05g.
    Autor: Pedro Peixoto Viana de Oliveira
    Turma: Ciência da Computação - 2º período - Noturno
    Data: 29/03/2023
    Observações: sem observações.
*/

#include <stdio.h>

int main() {

    float massa_inicial = 0.10; // usei duas variáveis pois no final eu preciso printar a quantidade inicial, entao usei duas variáveis, uma para o cálculo e uma para imprimir
    float massa_material = massa_inicial; // massa em gramas
    int tempo_segundos = 0, tempo_minutos = 0, tempo_hora = 0;

    while (massa_material > 0.05) {
        massa_material /= 2;
        tempo_segundos += 50;
    }

    // verificação de tempo em hora, minuto e segundo (baseado nos segundos totais)
    if (tempo_segundos >= 60) { // se for maior ou igual a 60, tem pelo menos um minuto, se não tiver, siginifica que durou menos de um minuto (ou seja, não tem minuto nem hora)
        tempo_minutos = (int) tempo_segundos / 60; // sabendo quantos minutos demorou
        tempo_segundos = tempo_segundos % 60; // o resto dos minutos é a quantidade de segundos

        if (tempo_minutos >= 60) { // mesmo caso do minuto, só que com hora
            tempo_hora = (int) tempo_minutos / 60; 
            tempo_minutos = tempo_hora % 60;
        }
    } 

    printf("\n- Tempo necessario para que a massa (%.2fg) se torne menor que 0.05g: %dh:%dmin:%dseg.", massa_inicial, tempo_hora, tempo_minutos, tempo_segundos);

    return 0;
}