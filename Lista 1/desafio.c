/*
    Função: Desafio da lista - dado duas cidades com quantidade de população distintas e taxa de variação distintas, ver em quantos anos a menor passará a população maior 
    Autor: Pedro Peixoto Viana de Oliveira
    Turma: Ciência da Computação - 2º período - Noturno
    Data: 29/03/2023
    Observações: sem observação
*/

#include <stdio.h>

int main() {

    int populacaoA, populacaoB, anos = 0;
    float taxa_crescimentoA, taxa_crescimentoB; // em porcentagem
    int quantidade_repeticao = 5;

    printf("Quantidade de casos: ");
    scanf(" %d", &quantidade_repeticao);

    for (int i = 0; i < quantidade_repeticao; i++) {
        printf("\n\nCaso %d\n", i + 1);
        printf("- Populacao a: ");
        scanf(" %d", &populacaoA);
        printf("- Populacao b: ");
        scanf(" %d", &populacaoB);
        printf("- Taxa de crescimento a: ");
        scanf(" %f", &taxa_crescimentoA);
        printf("- Taxa de crescimento b: ");
        scanf(" %f", &taxa_crescimentoB);

        while (1) {
            if (populacaoA > populacaoB) {
                printf("\n| Tempo necessario: %d anos", anos);
                break;
            }

            populacaoA *= (1 + (taxa_crescimentoA / 100));
            populacaoB *= (1 + (taxa_crescimentoB / 100));

            anos += 1;

            if (anos > 100) {
                printf("\n| Tempo necessario: mais de um seculo", anos);
                break;
            }
        }
        anos = 0, populacaoA = 0, populacaoB = 0, taxa_crescimentoA = 0.0, taxa_crescimentoB = 0.0;
    }

    return 0;
}
