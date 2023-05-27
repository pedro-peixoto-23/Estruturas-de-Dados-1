/*
    Função: Pedir um número ao usuário e informar o mês associado a esse numero, caso esse número seja invalido, apresentar uma mensagem de erro.
    Autor: Pedro Peixoto Viana de Oliveira
    Turma: Ciência da Computação - 2º período - Noturno
    Data: 27/03/2023
    Observações: sem observações.
*/

#include <stdio.h>

int main() {

    int numero_mes;

    printf("Insira um numero de um determinado mes: ");
    scanf(" %d", &numero_mes);

    switch (numero_mes) {
        case 1:
            printf("Mes digitado: Janeiro.");
            break;
        case 2:
            printf("Mes digitado: Fevereiro.");
            break;
        case 3:
            printf("Mes digitado: Marco.");
            break;
        case 4:
            printf("Mes digitado: Abril.");
            break;
        case 5:
            printf("Mes digitado: Maio.");
            break;
        case 6:
            printf("Mes digitado: Junho.");
            break;
        case 7:
            printf("Mes digitado: Julho.");
            break;
        case 8:
            printf("Mes digitado: Agosto.");
            break;
        case 9:
            printf("Mes digitado: Setembro.");
            break;
        case 10:
            printf("Mes digitado: Outubro.");
            break;
        case 11:
            printf("Mes digitado: Novembro.");
            break;
        case 12:
            printf("Mes digitado: Dezembro.");
            break;     
        default:
            printf("Mes invalido. Digite apenas numeros entre 1 e 12.");
            break;
    }

    return 0;
}
