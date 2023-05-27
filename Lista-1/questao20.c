/*
    Função: Dado o peso em quilos e a altura em metros passados pelo usuário, informa o IMC e a situação atual da pessoa (Abaixo do peso, normal, acima do peso, obeso).
    Autor: Pedro Peixoto Viana de Oliveira
    Turma: Ciência da Computação - 2º período - Noturno
    Data: 29/03/2023
    Observações: sem observações.
*/

#include <stdio.h>

int main() {

    float peso_em_quilos, altura_em_metros;

    printf("| Insira o seu peso em quilos: ");
    scanf(" %f", &peso_em_quilos);
    printf("| Insira a sua altura em metros: ");
    scanf(" %f", &altura_em_metros);

    float imc = peso_em_quilos / (altura_em_metros * altura_em_metros);

    printf("\n- Seu IMC e igual a: %.2f", imc);

    if (imc >= 30) {
        printf("\n- Estado: Obeso.");
    } else if (imc >= 25) {
        printf("\n- Estado: Acima do peso.");
    } else if (imc >= 18.5) {
        printf("\n- Estado: Normal.");
    } else {
        printf("\n- Estado: Abaixo do peso.");
    }

    return 0;
}
