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
    Empregado* vetor_empregados = NULL;
    int qtd_empregados = 0;

    imprimir_quadro_opcoes();

    int escolha_usuario;
    printf("Insira sua resposta: ");
    scanf("%d", &escolha_usuario);

    switch (escolha_usuario) {
        case 1:
            qtd_empregados++;
            if (qtd_empregados == 1) {
                vetor_empregados = malloc(qtd_empregados * sizeof(Empregado));
            } else {
                vetor_empregados = realloc(vetor_empregados, qtd_empregados * sizeof(Empregado));
            }
            if (vetor_empregados == NULL) {
                printf("Houve um problema com a alocacao!");
            } else {
                ler_empregado(&vetor_empregados[qtd_empregados - 1], qtd_empregados);
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
    fgets(empregado->nome, 50, stdin);
    empregado->nome[strcspn(empregado->nome, "\n")] = '\0';

    printf("- Insira a data de nascimento (separado por espaco, dia mes ano) do empregado: ");
    scanf("%d %d %d", &empregado->data_nascimento.dia, &empregado->data_nascimento.mes, &empregado->data_nascimento.ano);

    getchar();

    printf("- Insira o rg do empregado: ");
    fgets(empregado->rg, 7, stdin);

    printf("- Insira a data de admissao (separado por espaco, dia mes ano) do empregado: ");
    scanf("%d %d %d", &empregado->data_admissao.dia, &empregado->data_admissao.mes, &empregado->data_admissao.ano);

    
    printf("- Insira o salario do empregado: ");
    scanf("%f", &empregado->salario);

    getchar();
}

void imprimir_empregados(Empregado* empregados, int qtd_empregados) {
    for (int i = 0; i < qtd_empregados; i++) {
        printf("----- Empregado indice %d -----\n", i);
        printf("- Nome: %s\n", empregados[i].nome);
        printf("- Data de nascimento: %d/%d/%d\n", empregados[i].data_nascimento.dia, empregados[i].data_nascimento.mes, empregados[i].data_nascimento.ano);
        printf("- Registro Geral: %s\n", empregados[i].rg);
        printf("- Data de admissao: %d/%d/%d\n", empregados[i].data_admissao.dia, empregados[i].data_admissao.mes, empregados[i].data_admissao.ano);
        printf("- Salario: %.2f\n", empregados[i].salario);
    }
}
