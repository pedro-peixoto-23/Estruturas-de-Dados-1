/*
    Função: Dados 4 valores digitados pelo usuário, calcular e mostrar a média aritmética, harmônica, geométrica e quadrática
    Autor: Pedro Peixoto Viana de Oliveira
    Turma: Ciência da Computação - 2º período - Noturno
    Data: 27/03/2023
    Observações: 
        1- Para economizar linhas de código, foi utilizado um for para percorrer os quatro números que o usuário vai inserir, e foi utilizado um array para guardar esses valores.
        2- Na média geométrica, para fazer a raiz quarta da multiplicação dos valores foi utilizado a função pow e foi elevado a "1/4", pois eu queria tirar a raiz quarta e a potenciação é o inverso da radiciação, ou seja, raiz quarta é o mesmo que elevar a "1/4".
*/

#include <stdio.h>
#include <math.h>

float quadrado(float numero);

int main() {

    float numeros[4];

    printf("CALCULAR AS MEDIAS DE 4 NUMEROS REAIS\n\n");
    for (int i = 0; i < 4; i++) {
        printf("- Numero %d: ", i + 1);
        scanf(" %f", &numeros[i]);
    }

    float media_aritmetica = (numeros[0] + numeros[1] + numeros[2] + numeros[3]) / 4;
    float media_harmonica = 4 / ((1/numeros[0]) + (1/numeros[1]) + (1/numeros[2]) + (1/numeros[3]));
    float media_geometrica = pow((numeros[0] * numeros[1] * numeros[2] * numeros[3]), 1.0/4.0);
    float media_quadratica = sqrt((quadrado(numeros[0]) + quadrado(numeros[1]) + quadrado(numeros[2]) + quadrado(numeros[3])) / 4);
    
    printf("\n- Media Aritmetica: %f", media_aritmetica);
    printf("\n- Media Harmonica: %f", media_harmonica);
    printf("\n- Media Geometrica: %f", media_geometrica);
    printf("\n- Media Quadratica: %f", media_quadratica);
    
    return 0;
}


float quadrado(float numero) {
    return (numero * numero);
}