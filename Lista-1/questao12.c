/*
    Função: Calcula o somatório de um determinado número, ou seja, a soma de todos os números de 1 até o valor escolhido.
    Autor: Pedro Peixoto Viana de Oliveira
    Turma: Ciência da Computação - 2º período - Noturno
    Data: 27/03/2023
    Observações: sem observações.
*/

#include <stdio.h>

int calcularSomatorio(int numero);


int main() {
    
    int numeroUsuario = 10;

    printf("O somatorio do numero %d e igual a: %d", numeroUsuario, calcularSomatorio(numeroUsuario));

    return 0;
}


int calcularSomatorio(int numero) {

    int somatorio = 0;

    for (int i = 1; i <= numero; i++) {
        somatorio += i;
    }

    return somatorio;
}
