/*
    * Função: Criar um programa iterativo para calcular a raiz quadrada de um número n usando o método de Newton-Raphson. Com a seguinte 
              fórmula: Xk+1 = f(Xk) - f'(Xk), onde f(Xk) = Xk² - n (número que deseja encontrar a raiz) e f'(Xk) = derivada de f(Xk) = 2 * Xk.
    * Autor: Pedro Peixoto Viana de Oliveira
    * Data: 26/maio/2023
    * Observações: 
*/


#include <stdio.h>
#include <math.h>

double funcao(double x, double n);
double derivadaFuncao(double x);
double calcularXMaisProximoDeN(double x_inicial, double n);
double metodoNewtonRaphson(double x_inicial, double n, double aproximacao);


int main() {
    double n = 49; // n é o valor que eu preciso descobrir a raiz
    double x_inicial = 1; // valor inicial de x na função, para depois encontrar o outro x com a reta tangente
    double aproximacao = 0.0001;

    double resultado_raiz = metodoNewtonRaphson(x_inicial, n, aproximacao);

    printf("Raiz de %lf: %lf", n, resultado_raiz);

    return 0;
}

double funcao(double x, double n) { // implementação da função (x² - n)
    return (x * x) - n;
}

double derivadaFuncao(double x) { // derivada da função quadrática (x² - n)
    return 2 * x;
}

double calcularXMaisProximoDeN(double x_inicial, double n) {
    return x_inicial - (funcao(x_inicial, n) / derivadaFuncao(x_inicial));
}

double metodoNewtonRaphson(double x_inicial, double n, double aproximacao) {
    double raiz_aproximada;
    while (fabs((x_inicial * x_inicial) - n) > aproximacao) { // verificando se chegou perto da margem desejada
        raiz_aproximada = calcularXMaisProximoDeN(x_inicial, n);
        x_inicial = raiz_aproximada; // x_inicial agora vai receber o novo valor de x
    }
    return raiz_aproximada;
}
