#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

typedef struct {
    char nome[50];
    int idade;
    float nota;
} Aluno;

int main(int argc, char *argv[]) {
    setlocale(LC_ALL, "Portuguese");

    Aluno *alunos = NULL;
    int n, i, encontrado = 0;
    char busca[50];

    printf("Digite a quantidade de alunos: ");
    scanf("%d", &n);

    alunos = (Aluno *) malloc(n * sizeof(Aluno));

    if (alunos == NULL) {
        printf("Erro ao alocar memória!\n");
        return 1;
    }

    for (i = 0; i < n; i++) {
        printf("\n--- Aluno %d ---\n", i + 1);
        printf("Nome: ");
        scanf(" %[^\n]", alunos[i].nome);
        printf("Idade: ");
        scanf("%d", &alunos[i].idade);
        printf("Nota: ");
        scanf("%f", &alunos[i].nota);
    }

    printf("\nDigite o nome do aluno que deseja buscar: ");
    scanf(" %[^\n]", busca);

    for (i = 0; i < n; i++) {
        if (strcmp(alunos[i].nome, busca) == 0) {
            printf("\nAluno localizado:\n");
            printf("Nome: %s | Idade: %d | Nota: %.2f\n", alunos[i].nome, alunos[i].idade, alunos[i].nota);
            encontrado = 1;
            break;
        }
    }

    if (!encontrado) {
        printf("\nAluno '%s' não foi localizado.\n", busca);
    }

    free(alunos);
    alunos = NULL;

    return 0;
}