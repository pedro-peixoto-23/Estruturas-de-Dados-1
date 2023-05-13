/*
    Função: Verificar se um determinado número é primo ou não usando uma função.
    Autor: Pedro Peixoto Viana de Oliveira
    Turma: Ciência da Computação - 2º período - Noturno
    Data: 27/03/2023
    Observações: sem observações.
*/

#include <stdio.h>

int verificarPrimo(int numero);


int main() {
    
    int numeroUsuario = 10;

    if (verificarPrimo(numeroUsuario) == 1) printf("O numero %d e primo!", numeroUsuario);
    else printf("O numero %d nao e primo!", numeroUsuario);

    return 0;
}


int verificarPrimo(int numero) {
    
    int contadorDivisivel = 0;

    for (int i = 1; i <= numero; i++) {
        if (numero % i == 0) {
            contadorDivisivel++;
        }
    }

    if (contadorDivisivel == 2) return 1; // se for 2, significa que só foi divisível por 1 e por ele mesmo
    else return 0;
}
