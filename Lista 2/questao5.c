/*
    Função: Calcula a variância e o desvio-padrão de 20 temperaturas guardadas 
            em um array (que foram digitadas pelo usuário).
    Autor: Pedro Peixoto Viana de Oliveira
    Turma: Ciência da Computação - 2º período - Noturno
    Data: 11/04/2023
    Observações: sem observações
*/

// Média = soma de todos os termos dividido pela quantidade de termos
// Desvio = módulo da diferença entre a média e cada elemento
// Variância = soma dos quadrados dos desvios dividido pela quantidade de elementos
// Desvio padrão = raiz quadrada da variância

#include <stdio.h>
#include <math.h>

int main() {

    int qtd_temperaturas = 20;
    float temperaturas[qtd_temperaturas];
    float soma = 0, media, desvios[qtd_temperaturas], soma_variancia = 0, variancia, desvio_padrao;

    // pedindo ao usuário as temperaturas
    printf("==== Inserindo 20 temperaturas ====\n");
    for (int i = 0; i < qtd_temperaturas; i++) {
        printf("- Insira a temperatura %.2d: ", i + 1);
        scanf(" %f", &temperaturas[i]);
    }

    // calculando a média
    for (int i = 0; i < qtd_temperaturas; i++) {
        soma += temperaturas[i];
    }
    media = soma / qtd_temperaturas;

    // calculando a variância
    for (int i = 0; i < qtd_temperaturas; i++) {
        // módulo da media - temperatura
        if (media > temperaturas[i]) {
            desvios[i] = media - temperaturas[i];
        } else {
            desvios[i] = temperaturas[i] - media;
        }
        
        soma_variancia += (desvios[i] * desvios[i]);
    }
    variancia = soma_variancia / qtd_temperaturas;

    desvio_padrao = sqrt(variancia);

    printf("\n==== Resultados ====");
    printf("\n- Variancia das temperaturas: %f", variancia);
    printf("\n- Desvio padrao das temperaturas: raiz(%f) =~ %f", variancia, desvio_padrao);

    return 0;
}
