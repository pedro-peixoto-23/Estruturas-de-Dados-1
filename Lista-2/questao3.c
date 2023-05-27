/*
    Função: Lê n números inteiros e exibe o maior, o menor, a média e quantos são maiores que a média.
    Autor: Pedro Peixoto Viana de Oliveira
    Turma: Ciência da Computação - 2º período - Noturno
    Data: 11/04/2023
    Observações: sem observações
*/

#include <stdio.h>

int main() {

    int qtd_numeros, maior, menor, soma = 0, qtd_maiores_media = 0;
    float media;

    printf("- Insira a quantidade de numeros que serao inseridos: ");
    scanf(" %d", &qtd_numeros);

    int numeros[qtd_numeros];

    for (int i = 0; i < qtd_numeros; i++) {
        printf("- Insira o %dº numero: ", i + 1);
        scanf(" %d", &numeros[i]);

        if (i == 0) {
            maior = numeros[i];
            menor = numeros[i];
        }
        if (numeros[i] > maior) {
            maior = numeros[i];
        }
        if (numeros[i] < menor) {
            menor = numeros[i];
        }

        soma += numeros[i];
    }

    media = soma / qtd_numeros;

    for (int i = 0; i < qtd_numeros; i++) {
        if (numeros[i] > media) {
            qtd_maiores_media += 1;
        }
    }

    printf("\n==== Resultados ====\n");
    printf("\n- Maior valor: %d", maior);
    printf("\n- Menor valor: %d", menor);
    printf("\n- Quantidade de elementos: %d", qtd_numeros);
    printf("\n- Media dos valores digitados: %.2f", media);
    printf("\n- Quantidade de valores maiores que a media: %d", qtd_maiores_media);

    return 0;
}
