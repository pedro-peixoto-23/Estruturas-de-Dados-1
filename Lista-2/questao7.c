/*
    Função: Preenche um array de 100 elementos com elementos aleatórios (inteiros), calcula e exibe a média, o maior, o menor e quantos (e quais são) os números menores que a média.
    Autor: Pedro Peixoto Viana de Oliveira
    Turma: Ciência da Computação - 2º período - Noturno
    Data: 11/04/2023
    Observações: sem observações
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int gerarValorAleatorio(int valor_maximo);

int main() {

    int tamanho_array = 100, maior, menor, soma = 0, qtd_menores_media = 0;
    float media;
    int numeros[tamanho_array];

    srand(time(NULL));

    // preenchendo o array com valores aleatórios e imprimindo os valores
    printf("- Valores do array: ");
    for (int i = 0; i < tamanho_array; i++) {
        numeros[i] = gerarValorAleatorio(500);
        printf("%d ", numeros[i]);
    }

    for (int i = 0; i < tamanho_array; i++) {
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

    media = soma / tamanho_array;

    // descobrindo a quantidade de números menores que a média
    for (int i = 0; i < tamanho_array; i++) {
        if (numeros[i] < media) {
            qtd_menores_media += 1;
        }
    }

    // inserindo os numeros menores que a média em um array
    int numeros_menores_media[qtd_menores_media];
    int posicao_vetor_nmm = 0; // percorre os índices do vetor "numeros_menores_media"

    for (int i = 0; i < tamanho_array; i++) {
        if (numeros[i] < media) {
            numeros_menores_media[posicao_vetor_nmm] = numeros[i];
            posicao_vetor_nmm += 1;
        }
    }

    printf("\n\n==== Resultados ====");
    printf("\n- Maior valor: %d", maior);
    printf("\n- Menor valor: %d", menor);
    printf("\n- Quantidade de elementos: %d", tamanho_array);
    printf("\n- Media dos valores digitados: %.2f", media);
    printf("\n- Quantidade de valores menores que a media: %d", qtd_menores_media);
    printf("\n- Numeros menores que a media: ");
    if (qtd_menores_media == 0) {
        printf("0");
    } else {
        for (int i = 0; i < qtd_menores_media; i++) {
            printf("%d ", numeros_menores_media[i]);
        }
    }
    
    return 0;
}


int gerarValorAleatorio(int valor_maximo) {
    return rand() % (valor_maximo + 1);
}
