/*
    * Função: 
    * Autor: Pedro Peixoto Viana de Oliveira
    * Data: 22/maio/2023
    * Observações: Na questão 2, foi utilizado apenas um vetor que armazena estruturas. Nesse código foi usado um vetor de ponteiros para estruturas, um pouco diferente, por isso foi usado "vetor**", que indica um vetor bidimensional ou apenas um vetor de ponteiros.
*/

// 3. Suponha que uma empresa aérea mantém um cadastro de aeroportos como um vetor de
// ponteiros para estruturas que contêm as seguintes informações:
//                a. Sigla: string com até 3 caracteres;
//                b.Cidade: string com até 50 caracteres;
//                c.Pais: string com até 30caracteres;
//                d.Taxa: um valor real;
//                e.Capacidade: um valor inteiro;
// Defina uma estrutura em C com o nome de aeroporto, que tenha os campos apropriados
// para guardar todas as informações descritas anteriormente. Defina também um novo tipo
// de dados com o nome de Aeroporto, correspondendo a essa estrutura. Defina um vetor de
// Aeroportos (usando alocação dinâmica para a quantidade de aeroportos) para armazenar
// todos os aeroportos que a empresa aérea trabalha. Implementar rotinas para ler, escrever e
// excluir registros deste tipo.


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct aeroporto {
    char sigla[3];
    char cidade[50];
    char pais[30];
    float taxa;
    int capacidade;
} Aeroporto;

void imprimirQuadroOpcoes();
void lerAeroporto(Aeroporto* aeroporto);
void imprimirAeroportos(Aeroporto** aeroportos, int qtd_aeroportos);
void retirarAeroportoPorIndice(Aeroporto** aeroportos, int qtd_aeroportos);
void imprimirAlarmeFormatado(char* mensagem);

int main() {
    
    // Criando um vetor do tipo "vetor**", ou um vetor bidmensional, ou melhor, um vetor de ponteiros. Nesse caso, um
    // vetor de ponteiros para estruturas chamadas "Aeroporto"
    Aeroporto** vetor_de_ponteiros_para_estruturas_aeroportos;
    int qtd_ponteiros_para_aeroportos = 0;

    int sair_loop = 0;
    while (sair_loop == 0) {
        imprimirQuadroOpcoes();

        int escolha_usuario;
        printf("Insira sua resposta: ");
        scanf(" %d", &escolha_usuario);

        switch (escolha_usuario) {
            // Caso o usuário escolha inserir um novo aeroporto
            case 1:
                // Se não tiver nenhum ponteiro no array de ponteiros, criar apenas um espaço no array de ponteiros
                // referente ao novo elemento que será inserido, não precisa realocar nada, já que está vazio. Caso não 
                // esteja vazio realocar os dados para que o novo seja alocado perfeitamente.
                if (qtd_ponteiros_para_aeroportos == 0) {
                    vetor_de_ponteiros_para_estruturas_aeroportos = (Aeroporto**) malloc(sizeof(Aeroporto*));
                } else {
                    vetor_de_ponteiros_para_estruturas_aeroportos = (Aeroporto**) realloc(vetor_de_ponteiros_para_estruturas_aeroportos, (qtd_ponteiros_para_aeroportos + 1) * sizeof(Aeroporto*));
                }
                if (vetor_de_ponteiros_para_estruturas_aeroportos == NULL) {
                    imprimirAlarmeFormatado("Houve um problema com a alocacao do novo Aeroporto!");
                } else {
                    qtd_ponteiros_para_aeroportos += 1;
                    // Alocando dinamicamente o ponteiro do índice do vetor de ponteiro
                    vetor_de_ponteiros_para_estruturas_aeroportos[qtd_ponteiros_para_aeroportos - 1] = (Aeroporto*) malloc(sizeof(Aeroporto));
                    // Mandando o ponteiro que está no índice do último elemento que foi alocado
                    lerAeroporto(vetor_de_ponteiros_para_estruturas_aeroportos[qtd_ponteiros_para_aeroportos - 1]);
                }
                break;

            // Caso o usuário queira imprimir todos os aeroportos armazenados
            case 2:
                if (qtd_ponteiros_para_aeroportos == 0) {
                    imprimirAlarmeFormatado("Nao foram inseridos aeroportos!");
                } else {
                    imprimirAeroportos(vetor_de_ponteiros_para_estruturas_aeroportos, qtd_ponteiros_para_aeroportos);
                }
                break;
            
            case 3:
                break;

            case 4:
                break;

            default:
                break;
        }
    }

    // Desalocando todos os ponteiros dentro do vetor de ponteiros
    for (int i = 0; i < qtd_ponteiros_para_aeroportos; i++) {
        free(vetor_de_ponteiros_para_estruturas_aeroportos[i]);
    }

    // Desalocando, por fim, o vetor que acopla todos os ponteiros
    free(vetor_de_ponteiros_para_estruturas_aeroportos);

    return 0;
}

void imprimirQuadroOpcoes() {
    printf(" -----------------------------------------------\n");
    printf("| INSIRA O QUE VOCE DESEJA REALIZAR\t\t|\n");
    printf(" -----------------------------------------------\n");
    printf("| 1. Inserir um novo aeroporto\t\t\t|\n");
    printf(" -----------------------------------------------\n");
    printf("| 2. Ver os dados de todos os aeroportos\t|\n");
    printf(" -----------------------------------------------\n");
    printf("| 3. Remover algum aeroporto\t\t\t|\n");
    printf(" -----------------------------------------------\n");
    printf("| 4. Sair da execucao\t\t\t\t|\n");
    printf(" -----------------------------------------------\n");
}

void lerAeroporto(Aeroporto* aeroporto) {
    printf("\n--- Inserindo um novo aeroporto ---\n");

    getchar();

    printf("- Insira a sigla do aeroporto: ");
    fgets(aeroporto->sigla, 3, stdin);
    // retirando o "\n", caso a sigla tenha menos que 3 caracteres, do contrário, o próprio fgets limita e não pega o \n
    aeroporto->sigla[strcspn(aeroporto->sigla, "\n")] = '\0';

    getchar();
    getchar();

    printf("- Insira a cidade do aeroporto: ");
    fgets(aeroporto->cidade, 50, stdin);
    aeroporto->cidade[strcspn(aeroporto->cidade, "\n")] = '\0';

    printf("- Insira o pais do aeroporto: ");
    fgets(aeroporto->pais, 30, stdin);
    aeroporto->pais[strcspn(aeroporto->pais, "\n")] = '\0';

    printf("- Insira a taxa do aeroporto: ");
    scanf(" %f", &(aeroporto->taxa));

    printf("- Insira a capacidade do aeroporto: ");
    scanf(" %d", &(aeroporto->capacidade));

    printf("----------------\n");

    imprimirAlarmeFormatado("Aeroporto inserido com sucesso!");
}

void imprimirAeroportos(Aeroporto** aeroportos, int qtd_aeroportos) {
    printf("--------------- IMPRIMINDO AEROPORTOS ---------------\n");
    for (int i = 0; i < qtd_aeroportos; i++) {
        printf("\n----- Aeroporto indice %d -----\n", i);
        printf("- Sigla: %s\n", aeroportos[i]->sigla);
        printf("- Cidade: %s\n", aeroportos[i]->cidade);
        printf("- Pais: %s\n", aeroportos[i]->pais);
        printf("- Taxa: %.2f\n", aeroportos[i]->taxa);
        printf("- Capacidade: %d\n", aeroportos[i]->capacidade);
        printf("----------------------\n");
    }
    printf("-----------------------------------------------------\n");
}




void imprimirAlarmeFormatado(char* mensagem) {
    printf("-----------------------------------------\n");
    printf("| %s\n", mensagem);
    printf("-----------------------------------------\n");
}
