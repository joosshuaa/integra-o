#include <stdio.h>
#include <string.h>

struct Jogador {
    char nome[50];
    int funcao;
    float avaliacao;
};

int main() {
    // Inicializar jogadores
    struct Jogador players[23] = {
        {"Diego Alves", 3, 7.5},
        {"Hugo Souza", 3, 7},
        {"Gabriel Batista", 3, 6},
        {"Matheuzinho", 7, 6},
        {"Filipe Luis", 7, 7},
        {"Gustavo Henrique", 7, 6},
        {"Leo Pereira", 7, 6.5},
        {"Bruno Viana", 7, 6},
        {"Rodrigo Caio", 7, 8},
        {"Willian Arao", 8, 7},
        {"Gerson", 8, 8},
        {"Thiago Maia", 8, 6.5},
        {"Diego", 8, 7},
        {"Hugo Moura", 8, 6},
        {"Everton Ribeiro", 8, 8},
        {"De Arrascaeta", 8, 8},
        {"Max", 8, 6},
        {"Michael", 5, 6.5},
        {"Pedro", 5, 8},
        {"Vitinho", 5, 6},
        {"Bruno Henrique", 5, 8},
        {"Gabigol", 5, 9},
        {"Pedro Rocha", 5, 6.5}
    };

    // Ordenar por avaliação
    for (int i = 0; i < 22; i++) {
        for (int j = i + 1; j < 23; j++) {
            if (players[i].avaliacao < players[j].avaliacao) {
                struct Jogador temp = players[i];
                players[i] = players[j];
                players[j] = temp;
            }
        }
    }

    // Selecionar jogadores para a formação
    struct Jogador formacao[11];
    int goleiro = 0, defesa = 0, meio_campo = 0, atacante = 0;
    for (int i = 0; i < 23; i++) {
        if (players[i].funcao == 3 && goleiro < 1) {
            strcpy(formacao[0].nome, players[i].nome);
            formacao[0].funcao = players[i].funcao;
            formacao[0].avaliacao = players[i].avaliacao;
            goleiro++;
        } else if (players[i].funcao == 7 && defesa < 4) {
            strcpy(formacao[defesa + 1].nome, players[i].nome);
            formacao[defesa + 1].funcao = players[i].funcao;
            formacao[defesa + 1].avaliacao = players[i].avaliacao;
            defesa++;
        } else if (players[i].funcao == 8 && meio_campo < 4) {
            strcpy(formacao[meio_campo + 5].nome, players[i].nome);
            formacao[meio_campo + 5].funcao = players[i].funcao;
            formacao[meio_campo + 5].avaliacao = players[i].avaliacao;
            meio_campo++;
        } else if (players[i].funcao == 5 && atacante < 2) {
            strcpy(formacao[atacante + 9].nome, players[i].nome);
            formacao[atacante + 9].funcao = players[i].funcao;
            formacao[atacante + 9].avaliacao = players[i].avaliacao;
            atacante++;
            }
            if (goleiro == 1 && defesa == 4 && meio_campo == 4 && atacante == 2) {
                break;
            }
    }
    // Imprimir formação
    printf("Formacao:\n");
    printf("Goleiro: %s (Avaliacao: %.1f)\n", formacao[0].nome, formacao[0].avaliacao);
    printf("Defesa:\n");
    for (int i = 1; i < 5; i++) {
        printf("%d - %s (Avaliacao: %.1f)\n", i, formacao[i].nome, formacao[i].avaliacao);
    }
    printf("Meio-campo:\n");
    for (int i = 5; i < 9; i++) {
        printf("%d - %s (Avaliacao: %.1f)\n", i, formacao[i].nome, formacao[i].avaliacao);
    }
    printf("Ataque:\n");
    for (int i = 9; i < 11; i++) {
        printf("%d - %s (Avaliacao: %.1f)\n", i, formacao[i].nome, formacao[i].avaliacao);
    }

    return 0;
}
