#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

typedef struct {
    int codigo;
    char nome[50];
} Aluno;

int main(int argc, char *argv[]) {
    setlocale(LC_ALL, "Portuguese");

    Aluno *alunos = NULL;
    Aluno *temp = NULL;
    int qtd = 0;
    int opcao, codigo_rem, i, j, encontrado;

    do {
        printf("\n--- Sistema de Alunos ---\n");
        printf("1. Incluir aluno\n");
        printf("2. Remover aluno por código\n");
        printf("3. Listar alunos\n");
        printf("0. Sair\n");
        printf("Opção: ");
        scanf("%d", &opcao);

        if (opcao == 1) {
            temp = (Aluno *) realloc(alunos, (qtd + 1) * sizeof(Aluno));
            if (temp == NULL) {
                printf("Erro ao realocar memória!\n");
            } else {
                alunos = temp;
                printf("\nCódigo: ");
                scanf("%d", &alunos[qtd].codigo);
                printf("Nome: ");
                scanf(" %[^\n]", alunos[qtd].nome);
                qtd++;
                printf("Aluno incluído com sucesso!\n");
            }
        } else if (opcao == 2) {
            if (qtd == 0) {
                printf("Nenhum aluno cadastrado.\n");
                continue;
            }
            printf("\nDigite o código para remover: ");
            scanf("%d", &codigo_rem);
            encontrado = 0;

            for (i = 0; i < qtd; i++) {
                if (alunos[i].codigo == codigo_rem) {
                    encontrado = 1;
                    for (j = i; j < qtd - 1; j++) {
                        alunos[j] = alunos[j + 1];
                    }
                    qtd--;

                    if (qtd > 0) {
                        temp = (Aluno *) realloc(alunos, qtd * sizeof(Aluno));
                        if (temp != NULL) alunos = temp;
                    } else {
                        free(alunos);
                        alunos = NULL;
                    }
                    printf("Aluno removido com sucesso!\n");
                    break;
                }
            }
            if (!encontrado) printf("Código não localizado.\n");
        } else if (opcao == 3) {
            printf("\n=== Lista de Alunos (%d) ===\n", qtd);
            for (i = 0; i < qtd; i++) {
                printf("Código: %d | Nome: %s\n", alunos[i].codigo, alunos[i].nome);
            }
        }
    } while (opcao != 0);

    free(alunos);
    alunos = NULL;

    return 0;
}