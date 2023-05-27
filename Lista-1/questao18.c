/*
    Função: Informa o desconto final de um determinado carro com base no tipo de combustível (álcool, gasolina ou diesel) utilizado. No final, é mostrado ao usuário o valor do desconto, e o valor a ser pago com desconto.
    Autor: Pedro Peixoto Viana de Oliveira
    Turma: Ciência da Computação - 2º período - Noturno
    Data: 29/03/2023
    Observações: sem observações.
*/

#include <stdio.h>

int main() {

    float valor_carro, desconto;
    int tipo_combustivel = -1; // está negativo porque irá pedir ao usuário várias vezes até ele inserir corretamente os dados (entre 0 e 2)

    printf("CALCULAR VALOR FINAL DO CARRO\n\n");
    
    printf("- Digite valor do seu carro: ");
    scanf(" %f", &valor_carro);

    if (!(valor_carro <= 0.0)) {

        do {
            printf("\n| 0 - Alcool (desconto - 28\\%%%) | 1 - Gasolina (desconto - 22%%) | 2 - Diesel (desconto - 12%%) |");
            printf("\n- Digite o tipo de combustivel do seu carro: ");
            scanf(" %d", &tipo_combustivel);
        } while (tipo_combustivel < 0 || tipo_combustivel > 2);

        if (tipo_combustivel == 0) desconto = valor_carro * 0.28;
        else if (tipo_combustivel == 1) desconto = valor_carro * 0.22;
        else if (tipo_combustivel == 2) desconto = valor_carro * 0.12;

        printf("\n- Valor inicial do carro: R$%.2f", valor_carro);
        printf("\n- Valor do desconto: R$%.2f", desconto);
        printf("\n- Valor final a ser pago: R$%.2f", (valor_carro - desconto));
    }

    printf("\n\n| Obrigado por usar nosso programa! |");

    return 0;
}
