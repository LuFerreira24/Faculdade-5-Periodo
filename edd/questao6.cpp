#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main(int argc, char *argv[]) {
    setlocale(LC_ALL, "Portuguese");

    int *vetor1, *vetor2;
    int i, n;

    printf("Digite o tamanho dos vetores: ");
    scanf("%d", &n);

    vetor1 = (int *) malloc(n * sizeof(int));

    if (vetor1 == NULL) {
        printf("Erro ao alocar a memória para o vetor 1!\n");
        return 1;
    }

    vetor2 = (int *) calloc(n, sizeof(int));

    if (vetor2 == NULL) {
        printf("Erro ao alocar a memória para o vetor 2!\n");
        free(vetor1);
        return 1;
    }

    printf("\nValores iniciais do vetor 1 (lixo de memória):\n");
    for (i = 0; i < n; i++) {
        printf("%d ", vetor1[i]);
    }

    printf("\n\nValores iniciais do vetor 2 (zerados pelo calloc):\n");
    for (i = 0; i < n; i++) {
        printf("%d ", vetor2[i]);
    }

    printf("\n\nDigite os elementos do vetor 1:\n");
    for (i = 0; i < n; i++) {
        printf("Vetor 1 [%d]: ", i);
        scanf("%d", &vetor1[i]);
    }

    printf("\nDigite os elementos do vetor 2:\n");
    for (i = 0; i < n; i++) {
        printf("Vetor 2 [%d]: ", i);
        scanf("%d", &vetor2[i]);
    }

    printf("\nValores finais do vetor 1:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", vetor1[i]);
    }

    printf("\n\nValores finais do vetor 2:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", vetor2[i]);
    }
    printf("\n");

    free(vetor1);
    free(vetor2);
    vetor1 = NULL;
    vetor2 = NULL;

    return 0;
}