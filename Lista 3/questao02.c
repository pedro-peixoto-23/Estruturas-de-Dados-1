/*
    * Função: Criar um vetor que armazena empregados usando alocação dinâmica e structs. Além de permitir apagar, 
              inserir e apresentar todos os empregados.
    * Autor: Pedro Peixoto Viana de Oliveira
    * Data: 22/maio/2023
    * Observações: 
        - Foi utilizado o realloc para tornar o array dinâmico, podendo aumentar e diminuir ao decorrer da aplicação,
          dependendo de quantos empregados o usuário insira ou retire.
        - Foi criado um painel no terminal para uma boa iteratividade com o usuário.
*/


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
void retirarEmpregadoPorIndice(Empregado* empregados, int qtd_empregados);
void imprimirAlarmeFormatado(char* mensagem);

int main() {
    
    Empregado* vetor_empregados;
    int qtd_empregados = 0;

    int sair_loop = 0;
    while (sair_loop == 0) {
        imprimir_quadro_opcoes();

        int escolha_usuario;
        printf("Insira sua resposta: ");
        scanf(" %d", &escolha_usuario);

        switch (escolha_usuario) {
            // Caso o usuário escolha inserir um novo empregado
            case 1:
                // Se não tiver empregados, criar apenas um espaço no array e caso não esteja vazia, realocar os dados 
                // anteriores para o novo empregado
                if (qtd_empregados == 0) {
                    vetor_empregados = malloc(sizeof(Empregado));
                } else {
                    vetor_empregados = (Empregado*) realloc(vetor_empregados, (qtd_empregados + 1) * sizeof(Empregado));
                }
                // Verificando se a alocação foi bem sucedida
                if (vetor_empregados == NULL) {
                    imprimirAlarmeFormatado("Houve um problema com a alocacao!");
                } else {
                    qtd_empregados += 1;
                    ler_empregado(vetor_empregados, qtd_empregados);
                }
                break;

            // Caso o usuário escolha mostrar todos os empregados
            case 2:
                if (qtd_empregados == 0) {
                    imprimirAlarmeFormatado("Ainda nao foram inseridos empregados!");
                } else {
                    imprimir_empregados(vetor_empregados, qtd_empregados);
                }
                break;

            // Caso o usuário escolha remover algum empregado
            case 3:
                if (qtd_empregados == 0) {
                    imprimirAlarmeFormatado("Ainda nao foram inseridos empregados!");
                } else {
                    retirarEmpregadoPorIndice(vetor_empregados, qtd_empregados);
                    vetor_empregados = (Empregado*) realloc(vetor_empregados, (qtd_empregados - 1) * sizeof(Empregado));
                    qtd_empregados -= 1;
                }
                break;

            // Caso o usuário escolha terminar a execução do programa
            case 4:
                imprimirAlarmeFormatado("Execucao terminada com sucesso!");
                sair_loop = 1;
                break;

            default:
                imprimirAlarmeFormatado("Inserir numeros apenas entre 1 e 4!");
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
    // apenas retirando o \n da string (usando o strcspn para ver o índice do \n e modificando por \0 para a string 
    // finalizar onde antes era o \n)
    empregado[indice].nome[strcspn(empregado[indice].nome, "\n")] = '\0'; 

    printf("- Insira a data de nascimento (separado por espaco, dia mes ano) do empregado: ");
    scanf(" %d %d %d", &empregado[indice].data_nascimento.dia, &empregado[indice].data_nascimento.mes, &empregado[indice].data_nascimento.ano);

    getchar();
    
    printf("- Insira o rg do empregado: ");
    fgets(empregado[indice].rg, 7, stdin);
    // apenas retirando o \n, como fez no nome
    empregado[indice].rg[strcspn(empregado[indice].rg, "\n")] = '\0';

    getchar();

    printf("- Insira a data de admissao (separado por espaco, dia mes ano) do empregado: ");
    scanf(" %d %d %d", &empregado[indice].data_admissao.dia, &empregado[indice].data_admissao.mes, &empregado[indice].data_admissao.ano);
    
    printf("- Insira o salario do empregado: ");
    scanf(" %f", &empregado[indice].salario);
    
    printf("----------------\n");

    imprimirAlarmeFormatado("Empregado inserido com sucesso!");
}

void imprimir_empregados(Empregado* empregados, int qtd_empregados) {
    printf("--------------- IMPRIMINDO EMPREGADOS ---------------\n");
    for (int i = 0; i < qtd_empregados; i++) {
        printf("\n----- Empregado indice %d -----\n", i);
        printf("- Nome: %s\n", empregados[i].nome);
        printf("- Data de nascimento: %d/%d/%d\n", empregados[i].data_nascimento.dia, empregados[i].data_nascimento.mes, empregados[i].data_nascimento.ano);
        printf("- Registro Geral: %s\n", empregados[i].rg);
        printf("- Data de admissao: %d/%d/%d\n", empregados[i].data_admissao.dia, empregados[i].data_admissao.mes, empregados[i].data_admissao.ano);
        printf("- Salario: %.2f\n", empregados[i].salario);
        printf("----------------------\n");
    }
    printf("-----------------------------------------------------\n");
}

void retirarEmpregadoPorIndice(Empregado* empregados, int qtd_empregados) {
    int indice_remocao;

    do {
        printf("- Insira o indice do empregado que deseja remover: ");
        scanf(" %d", &indice_remocao);

        if ((indice_remocao > (qtd_empregados - 1)) || (indice_remocao < 0)) {
            printf("TENTE NOVAMENTE: insira apenas valores de 0 ate %d\n", qtd_empregados - 1);
        } else {
            imprimirAlarmeFormatado("O empregado foi removido com sucesso! Consulte se isso realmente aconteceu imprimindo os empregados!");

            break;
        }
    } while (1);

    int indice_vazio = indice_remocao;
    int indice_proximo_vazio = indice_vazio + 1;
    // se chegou no fim da lista, ou seja, os outros elementos ocuparam o lugar dele, e se for o último elemento que vai
    // ser apagado, não será apagado, mas quando o realloc for usado na função main, ele vai sair automaticamente, mesmo
    // acontece caso seja um único elemento na lista, já que o realloc vai retirar ele automaticamente no main 
    while (indice_vazio < (qtd_empregados - 1)) {
        empregados[indice_vazio] = empregados[indice_proximo_vazio];
        indice_vazio = indice_proximo_vazio;
        indice_proximo_vazio += 1;
    }
}

void imprimirAlarmeFormatado(char* mensagem) {
    printf("-----------------------------------------\n");
    printf("| %s\n", mensagem);
    printf("-----------------------------------------\n");
}
