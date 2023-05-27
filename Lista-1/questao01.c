/*
    Função: Retornar o valor da hipotenusa de um triâangulo retângulo dado os valores dos catetos.
    Autor: Pedro Peixoto Viana de Oliveira
    Turma: Ciência da Computação - 2º período - Noturno
    Data: 27/03/2023
    Observações: sem observação
*/

#include <stdio.h>
#include <math.h>

int main() {

    int cateto_a, cateto_b;

    printf("CALCULAR O VALOR DA HIPOTENUSA\n\n");
    printf("- Cateto a: ");
    scanf(" %d", &cateto_a);
    printf("- Cateto b: ");
    scanf(" %d", &cateto_b);

    double hipotenusa = sqrt((cateto_a * cateto_a) + (cateto_b * cateto_b));

    printf("\n- Hipotenusa: %lf", hipotenusa);

    return 0;
}