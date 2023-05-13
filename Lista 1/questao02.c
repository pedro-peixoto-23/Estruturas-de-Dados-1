/*
    Função: Calcular o salário de um professor através dos dados (hora-aula, quantidade de aulas dadas em um mês e percentual de desconto do INSS) passados pelo usuário.
    Autor: Pedro Peixoto Viana de Oliveira
    Turma: Ciência da Computação - 2º período - Noturno
    Data: 27/03/2023
    Observações: sem observação
*/

#include <stdio.h>
#include <math.h>

int main() {

    double valor_hora_aula, per_desconto_inss;
    int qtd_aulas_dadas;

    printf("CALCULAR SALARIO PROFESSOR\n\n");
    printf("- Valor da hora-aula: ");
    scanf(" %lf", &valor_hora_aula);
    printf("- Quantidades de aulas ministradas: ");
    scanf(" %d", &qtd_aulas_dadas);
    printf("-Percentual do desconto do INSS: ");
    scanf(" %lf", &per_desconto_inss);

    double salario_sem_desconto_inss = valor_hora_aula * qtd_aulas_dadas;
    double salario_professor = (valor_hora_aula * qtd_aulas_dadas) * ((100 - per_desconto_inss)/100);

    printf("\n- Salario do professor sem desconto do INSS: R$%.2lf", salario_sem_desconto_inss);
    printf("\n- Salario do professor: R$%.2lf", salario_professor);

    return 0;
}