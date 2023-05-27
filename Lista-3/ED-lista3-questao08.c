/*
    * Função: Criar um TAD (Tipo Abstrato de Dado) para os números complexos e inserir funções (criar, destruir, ler, mostrar, somar, subtrair,
              multiplicar e dividir) que permitem utilizar esse tipo.
    * Autor: Pedro Peixoto Viana de Oliveira
    * Data: 27/maio/2023
    * Observações: 
*/


#include <stdio.h>
#include <stdlib.h>

typedef struct complexo {
    double real;
    double imaginario;
} Complexo;

Complexo* complexoCriar(double real, double imaginario);
void complexoDestruir(Complexo* complexo);
void complexoLer(Complexo* complexo);
void complexoMostrar(Complexo* complexo);
Complexo* complexoSomar(Complexo* complexo1, Complexo* complexo2);
Complexo* complexoSubtrair(Complexo* complexo1, Complexo* complexo2);
Complexo* complexoMultiplicar(Complexo* complexo1, Complexo* complexo2);
Complexo* complexoDividir(Complexo* complexo1, Complexo* complexo2);


int main() {
    
    Complexo* complexo1 = complexoCriar(0, 0);
    Complexo* complexo2 = complexoCriar(0, 0);

    printf("Insira os dados do primeiro complexo\n");
    complexoLer(complexo1);
    printf("Insira os dados do segundo complexo\n");
    complexoLer(complexo2);

    Complexo* soma = complexoSomar(complexo1, complexo2);
    Complexo* direrenca = complexoSubtrair(complexo1, complexo2);
    Complexo* produto = complexoMultiplicar(complexo1, complexo2);
    Complexo* quociente = complexoDividir(complexo1, complexo2);

    printf("-- Resultados --\n");
    printf("- Soma: ");
    complexoMostrar(soma);
    printf("- Diferenca: ");
    complexoMostrar(direrenca);
    printf("- Produto: ");
    complexoMostrar(produto);
    printf("- Quociente: ");
    complexoMostrar(quociente);

    complexoDestruir(complexo1);
    complexoDestruir(complexo2);
    complexoDestruir(soma);
    complexoDestruir(direrenca);
    complexoDestruir(produto);
    complexoDestruir(quociente);

    return 0;
}

Complexo* complexoCriar(double real, double imaginario) {
    Complexo* complexo = (Complexo*) malloc(sizeof(Complexo));
    if (complexo == NULL) {
        printf("Houve um problema com a alocacao!");
        exit(1);
    }
    complexo->real = real;
    complexo->imaginario = imaginario;
    return complexo;
}

void complexoDestruir(Complexo* complexo) {
    free(complexo);
}

void complexoLer(Complexo* complexo) {
    printf("- Parte real: ");
    scanf(" %lf", &complexo->real);

    printf("- Parte imaginaria: ");
    scanf(" %lf", &complexo->imaginario);

    printf("\n");
}

void complexoMostrar(Complexo* complexo) {
    printf("(real: %lf, img: %lf)\n", complexo->real, complexo->imaginario);
}

Complexo* complexoSomar(Complexo* complexo1, Complexo* complexo2) {
    Complexo* complexo_soma = complexoCriar(0, 0);
    complexo_soma->real = complexo1->real + complexo2->real;
    complexo_soma->imaginario = complexo1->imaginario + complexo2->imaginario;
    return complexo_soma;
}

Complexo* complexoSubtrair(Complexo* complexo1, Complexo* complexo2) {
    Complexo* complexo_diferenca = complexoCriar(0, 0);
    complexo_diferenca->real = complexo1->real - complexo2->real;
    complexo_diferenca->imaginario = complexo1->imaginario - complexo2->imaginario;
    return complexo_diferenca;
}

// (a + bi) * (c + di) = (ac - bd) + (ad + bc)i -> fórmula para calcular o produto de números complexos.
Complexo* complexoMultiplicar(Complexo* complexo1, Complexo* complexo2) {
    Complexo* complexo_produto = complexoCriar(0, 0);
    // Usando a fórmula para calcular o produto dos números complexos.
    complexo_produto->real = (complexo1->real * complexo2->real) - (complexo1->imaginario * complexo2->imaginario);
    complexo_produto->imaginario = (complexo1->real * complexo2->imaginario) + (complexo1->imaginario * complexo2->real);
    return complexo_produto;
}

// Como funciona a divisão de complexos
// real_1 + (imaginario_1 * i)   (real_1 + (imaginario_1 * i)) * (real_2 - (imaginario_2 * i))
// --------------------------- = ------------------------------------------------------------- 
// real_2 + (imaginario_2 * i)   (real_2 + (imaginario_2 * i)) * (real_2 - (imaginario_2 * i))
// Multiplicar o numerador e o denominador pelo conjugado do denominador, chamando a função de multiplicação de complexos para fazer esse
// trabalho. No fim, a parte imaginária será zero e iremos dividir a parte real do numerador com a parte real do denominador e a parte 
// imaginária do numerador pela parte real do denominador.
Complexo* complexoDividir(Complexo* complexo1, Complexo* complexo2) {
    Complexo* complexo_quociente = complexoCriar(0, 0);

    // Definindo o conjugado do denominador.
    Complexo* conjugado_denominador = complexoCriar(complexo2->real, -complexo2->imaginario);
    // Multiplicando o numerador e o denominador pelo conjugado do denominador.
    Complexo* numerador = complexoMultiplicar(complexo1, conjugado_denominador);
    Complexo* denominador = complexoMultiplicar(complexo2, conjugado_denominador);

    // Quando eu tenho uma soma dividido por um valor, eu posso separar, então faz a divisão final entre o numerador real e o denominador
    // real e o numerador real com o denominador real.
    // Não usa o denominador imaginário, pois ele some ao decorrer da multiplicação e torna-se 0, então sobra apenas o valor real do
    // denominador.
    complexo_quociente->real = numerador->real / denominador->real;
    complexo_quociente->imaginario = numerador->imaginario / denominador->real;

    complexoDestruir(conjugado_denominador);
    complexoDestruir(numerador);
    complexoDestruir(denominador);

    return complexo_quociente;
}
