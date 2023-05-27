/*
    Função: Pedir um número ao usuário e mostrar o cubo desse número através de uma função.
    Autor: Pedro Peixoto Viana de Oliveira
    Turma: Ciência da Computação - 2º período - Noturno
    Data: 27/03/2023
    Observações: sem observação
*/

#include <stdio.h>

int cubo(int numero);

int main() {
    int numero_usuario;
    
    printf("-  Insira um numero: ");
    scanf(" %d", &numero_usuario);

    int cubo_usuario = cubo(numero_usuario);

    printf("\n- Cubo do numero digitado: %d", cubo_usuario);

    return 0;
}


int cubo(int numero) {
    return (numero * numero * numero);
}