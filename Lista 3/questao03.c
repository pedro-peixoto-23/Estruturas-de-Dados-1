/*
    * Função: 
    * Autor: Pedro Peixoto Viana de Oliveira
    * Data: 22/maio/2023
    * Observações: Na questão 2, foi utilizado apenas um vetor que armazena estruturas. Nesse código, foi usado um vetor de ponteiros para
                   estruturas, um pouco diferente, por isso foi usado "vetor**", que indica um vetor bidimensional ou apenas um vetor de 
                   ponteiros.
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct aeroporto {
    // Todas as strings foram colocadas com um caractere a mais, pois todas elas terminam com o caractere '\0'
    char sigla[3 + 1]; 
    char cidade[50 + 1];
    char pais[30 + 1];
    float taxa;
    int capacidade;
} Aeroporto;

void imprimirQuadroOpcoes();
void lerAeroporto(Aeroporto* aeroporto);
void imprimirAeroportos(Aeroporto** aeroportos, int qtd_aeroportos);
void retirarAeroportoPorIndice(Aeroporto** aeroportos, int qtd_aeroportos);
void imprimirAlarmeFormatado(char* mensagem);
// Essa função foi desenvolvida porque existem fgets aninhados na função lerAeroporto
void limparCaracteresQuePassaramNoFgets(char* string_do_fgets);

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

            // Caso o usuário escolha imprimir todos os aeroportos armazenados
            case 2:
                if (qtd_ponteiros_para_aeroportos == 0) {
                    imprimirAlarmeFormatado("Nao foram inseridos aeroportos!");
                } else {
                    imprimirAeroportos(vetor_de_ponteiros_para_estruturas_aeroportos, qtd_ponteiros_para_aeroportos);
                }
                break;
            
            // Caso o usuário escolha retirar algum aeroporto
            case 3:
                if (qtd_ponteiros_para_aeroportos == 0) {
                    imprimirAlarmeFormatado("Nao foram inseridos aeroportos!");
                } else {
                    retirarAeroportoPorIndice(vetor_de_ponteiros_para_estruturas_aeroportos, qtd_ponteiros_para_aeroportos);
                    // Realocando e tirando o último elemento, já que a função que foi chamada para retirar, modificou o array para que 
                    // o que precisa ser retirado fique na última posição.
                    vetor_de_ponteiros_para_estruturas_aeroportos = (Aeroporto**) realloc(vetor_de_ponteiros_para_estruturas_aeroportos, (qtd_ponteiros_para_aeroportos - 1) * sizeof(Aeroporto*));
                    qtd_ponteiros_para_aeroportos -= 1;
                }
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
    getchar();

    printf("\n--- Inserindo um novo aeroporto ---\n");

    printf("- Insira a sigla do aeroporto: ");
    fgets(aeroporto->sigla, sizeof(aeroporto->sigla), stdin);
    limparCaracteresQuePassaramNoFgets(aeroporto->sigla);
    // retirando o "\n" caso o usuário não use todos os espaços da string, pois ele armazena o '\n' caso todos os
    // espaços não sejam ocupados.
    aeroporto->sigla[strcspn(aeroporto->sigla, "\n")] = '\0';

    printf("- Insira a cidade do aeroporto: ");
    fgets(aeroporto->cidade, sizeof(aeroporto->cidade), stdin);
    limparCaracteresQuePassaramNoFgets(aeroporto->cidade);
    aeroporto->cidade[strcspn(aeroporto->cidade, "\n")] = '\0';

    printf("- Insira o pais do aeroporto: ");
    fgets(aeroporto->pais, sizeof(aeroporto->pais), stdin);
    limparCaracteresQuePassaramNoFgets(aeroporto->pais);
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

void retirarAeroportoPorIndice(Aeroporto** aeroportos, int qtd_aeroportos) {
    int indice_remocao;

    do {
        printf("Insira o indice do aeroporto que deseja remover: ");
        scanf(" %d", &indice_remocao);

        if ((indice_remocao > (qtd_aeroportos - 1)) || (indice_remocao < 0)) {
            printf("TENTE NOVAMENTE: Insira apenas valores de 0 ate %d!\n", qtd_aeroportos - 1);
        } else {
            imprimirAlarmeFormatado("O aeroporto foi removido com sucesso! Consulte se isso realmente aconteceu imprimindo os aeroportos!");

            break;
        }
    } while (1);

    // Liberando a memória que o ponteiro que armazena a estrutura está apontando, pois ela não vai mais ser usada
    free(aeroportos[indice_remocao]);

    int indice_vazio = indice_remocao;
    int indice_proximo_vazio = indice_vazio + 1;
    // Se chegou no fim da lista, ou seja, os outros elementos ocuparam o lugar dele, e se for o último elemento que vai
    // ser apagado, não será apagado, mas quando o realloc for usado na função main, ele vai sair automaticamente, mesmo
    // acontece caso seja um único elemento na lista, já que o realloc vai retirar ele automaticamente no main 
    while (indice_vazio < (qtd_aeroportos - 1)) {
        // O ponteiro anterior agora aponta para o endereço de memória do próximo
        aeroportos[indice_vazio] = aeroportos[indice_proximo_vazio];
        indice_vazio = indice_proximo_vazio;
        indice_proximo_vazio += 1;
    }

}

void imprimirAlarmeFormatado(char* mensagem) {
    printf("-----------------------------------------\n");
    printf("| %s\n", mensagem);
    printf("-----------------------------------------\n");
}

void limparCaracteresQuePassaramNoFgets(char* string_do_fgets) {
    // A função strchr retorna NULL caso não exista um caractere informado
    // Então é verificado se a string possui o '\n', caso não possua, significa que sobrou caracteres no buffers de entrada
    // Sabendo disso, é criado uma rotina para retirar esses caracteres até chegar no '\n', que significa o final dos carac-
    // teres que passaram no fgets.
    if (strchr(string_do_fgets, '\n') == NULL) {
        while (getchar() != '\n') {}
    }
}
