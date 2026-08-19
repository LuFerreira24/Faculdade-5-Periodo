#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main(int argc, char *argv[]) {
    setlocale(LC_ALL, "Portuguese");

    int *vetor = NULL;
    int *temp = NULL;
    int n, nova_qtd, i;

    printf("Digite a quantidade inicial de elementos: ");
    scanf("%d", &n);

    vetor = (int *) malloc(n * sizeof(int));

    if (vetor == NULL) {
        printf("Erro ao alocar memória!\n");
        return 1;
    }

    printf("Digite os %d elementos iniciais:\n", n);
    for (i = 0; i < n; i++) {
        printf("Elemento %d: ", i + 1);
        scanf("%d", &vetor[i]);
    }

    printf("\nDigite a nova quantidade de elementos: ");
    scanf("%d", &nova_qtd);

    temp = (int *) realloc(vetor, nova_qtd * sizeof(int));

    if (temp == NULL) {
        printf("Erro ao realocar memória! O vetor original foi mantido.\n");
    } else {
        vetor = temp;
        if (nova_qtd > n) {
            printf("Digite os novos %d elementos:\n", nova_qtd - n);
            for (i = n; i < nova_qtd; i++) {
                printf("Elemento %d: ", i + 1);
                scanf("%d", &vetor[i]);
            }
        }
        n = nova_qtd;
    }

    printf("\nElementos no vetor:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", vetor[i]);
    }
    printf("\n");

    free(vetor);
    vetor = NULL;

    return 0;
}