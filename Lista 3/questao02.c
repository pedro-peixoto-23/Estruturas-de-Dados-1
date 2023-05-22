/*
    * Função: 
    * Autor: Pedro Peixoto Viana de Oliveira
    * Data: 22/maio/2023
    * Observações: 
*/

// Defina um registro (estrutura - struct) empregado para armazenar os dados (nome, data de
// nascimento, RG, data de admissão e salário) de um empregado de uma empresa. Criar um
// novo tipo de dados chamado Empregado usando a estrutura empregado. Defina um vetor
// de empregados (usando alocação dinâmica) para armazenar todos os empregados de sua
// empresa. Implementar rotinas para ler, escrever e excluir registros deste tipo.


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct data {
    int dia;
    int mes;
    int ano;
} Data;

typedef struct empregado {
    char nome[50];
    Data data_nascimento;
    char rg[7];
    Data data_admissao;
    float salario;

} Empregado;

void imprimir_quadro_opcoes();
void ler_empregado(Empregado* empregado, int qtd_empregados);
void imprimir_empregados(Empregado* empregados, int qtd_empregados);

int main() {
    
    Empregado* vetor_empregados;
    int qtd_empregados = 0;
    while (1) {
        imprimir_quadro_opcoes();

        int escolha_usuario;
        printf("Insira sua resposta: ");
        scanf(" %d", &escolha_usuario);

        if (escolha_usuario == 4) {
            break;
        }

        switch (escolha_usuario) {
            case 1:
                if (qtd_empregados == 0) {
                    vetor_empregados = malloc(sizeof(Empregado));
                } else {
                    vetor_empregados = (Empregado*) realloc(vetor_empregados, (qtd_empregados + 1) * sizeof(Empregado));
                }
                if (vetor_empregados == NULL) {
                    printf("Houve um problema com a alocacao!");
                } else {
                    qtd_empregados += 1;
                    ler_empregado(vetor_empregados, qtd_empregados);
                }
                break;

            case 2:
                if (qtd_empregados == 0) {
                    printf("\nAinda nao foram inseridos empregados!\n");
                } else {
                    imprimir_empregados(vetor_empregados, qtd_empregados);
                }
            break;
            default:
                break;
        }
    }
    
    free(vetor_empregados);


    return 0;
}

void imprimir_quadro_opcoes() {
    printf(" -----------------------------------------------\n");
    printf("| INSIRA O QUE VOCE DESEJA REALIZAR\t\t|\n");
    printf(" -----------------------------------------------\n");
    printf("| 1. Inserir um novo empregado\t\t\t|\n");
    printf(" -----------------------------------------------\n");
    printf("| 2. Ver os dados de todos os empregados\t|\n");
    printf(" -----------------------------------------------\n");
    printf("| 3. Remover algum empregado\t\t\t|\n");
    printf(" -----------------------------------------------\n");
    printf("| 4. Sair da execucao\t\t\t\t|\n");
    printf(" -----------------------------------------------\n");
}

void ler_empregado(Empregado* empregado, int qtd_empregados) {
    int indice = qtd_empregados - 1;

    printf("\n-- Inserindo um novo empregado --\n");

    getchar();

    printf("- Insira o nome do empregado: ");
    fgets(empregado[indice].nome, 50, stdin);
    // apenas retirando o \n da string (usando o strcspn para ver o índice do \n e modificando por \0 para a string finalizar onde antes era o \n)
    empregado[indice].nome[strcspn(empregado[indice].nome, "\n")] = '\0'; 

    printf("- Insira a data de nascimento (separado por espaco, dia mes ano) do empregado: ");
    scanf(" %d %d %d", &empregado[indice].data_nascimento.dia, &empregado[indice].data_nascimento.mes, &empregado[indice].data_nascimento.ano);

    getchar();
    
    printf("- Insira o rg do empregado: ");
    fgets(empregado[indice].rg, 7, stdin);

    getchar();

    printf("- Insira a data de admissao (separado por espaco, dia mes ano) do empregado: ");
    scanf(" %d %d %d", &empregado[indice].data_admissao.dia, &empregado[indice].data_admissao.mes, &empregado[indice].data_admissao.ano);
    
    printf("- Insira o salario do empregado: ");
    scanf(" %f", &empregado[indice].salario);
}

void imprimir_empregados(Empregado* empregados, int qtd_empregados) {
    for (int i = 0; i < qtd_empregados; i++) {
        printf("\n----- Empregado indice %d -----\n", i);
        printf("- Nome: %s\n", empregados[i].nome);
        printf("- Data de nascimento: %d/%d/%d\n", empregados[i].data_nascimento.dia, empregados[i].data_nascimento.mes, empregados[i].data_nascimento.ano);
        printf("- Registro Geral: %s\n", empregados[i].rg);
        printf("- Data de admissao: %d/%d/%d\n", empregados[i].data_admissao.dia, empregados[i].data_admissao.mes, empregados[i].data_admissao.ano);
        printf("- Salario: %.2f\n", empregados[i].salario);
        printf("----------------------\n");
    }
}