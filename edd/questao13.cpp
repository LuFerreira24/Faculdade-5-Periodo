#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

typedef struct {
    char nome[50];
    int idade;
    float nota;
} Aluno;

int main(int argc, char *argv[]) {
    setlocale(LC_ALL, "Portuguese");

    Aluno *alunos = NULL;
    int n, i;

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

    printf("\n=== Lista de Alunos ===\n");
    for (i = 0; i < n; i++) {
        printf("Aluno %d: %s | Idade: %d | Nota: %.2f\n", i + 1, alunos[i].nome, alunos[i].idade, alunos[i].nota);
    }

    free(alunos);
    alunos = NULL;

    return 0;
}