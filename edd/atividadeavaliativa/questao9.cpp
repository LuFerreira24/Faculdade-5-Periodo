#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main(int argc, char *argv[]) {
    setlocale(LC_ALL, "Portuguese");

    int *vetor, *temp;
    int i;

    vetor = (int *) malloc(5 * sizeof(int));

    if (vetor == NULL) {
        printf("Erro ao alocar memória!\n");
        return 1;
    }

    printf("Digite os 5 primeiros valores:\n");
    for (i = 0; i < 5; i++) {
        printf("Valor %d: ", i + 1);
        scanf("%d", &vetor[i]);
    }

    temp = (int *) realloc(vetor, 10 * sizeof(int));

    if (temp == NULL) {
        printf("Erro ao realocar memória!\n");
        free(vetor);
        return 1;
    }

    vetor = temp;

    printf("\nDigite mais 5 valores:\n");
    for (i = 5; i < 10; i++) {
        printf("Valor %d: ", i + 1);
        scanf("%d", &vetor[i]);
    }

    printf("\nValores armazenados no vetor:\n");
    for (i = 0; i < 10; i++) {
        printf("%d ", vetor[i]);
    }
    printf("\n");

    free(vetor);
    vetor = NULL;

    return 0;
}