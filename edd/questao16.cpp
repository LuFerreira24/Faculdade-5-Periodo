#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main(int argc, char *argv[]) {
    setlocale(LC_ALL, "Portuguese");

    int *vetor = NULL;
    int n, i, j, valor, encontrado = 0;

    printf("Digite a quantidade de elementos: ");
    scanf("%d", &n);

    vetor = (int *) malloc(n * sizeof(int));

    if (vetor == NULL) {
        printf("Erro ao alocar memória!\n");
        return 1;
    }

    for (i = 0; i < n; i++) {
        printf("Digite o %dº valor: ", i + 1);
        scanf("%d", &vetor[i]);
    }

    printf("\nDigite um valor para remover: ");
    scanf("%d", &valor);

    for (i = 0; i < n; i++) {
        if (vetor[i] == valor) {
            encontrado = 1;
            for (j = i; j < n - 1; j++) {
                vetor[j] = vetor[j + 1];
            }
            n--;
            break;
        }
    }

    if (encontrado) {
        printf("\nValor %d removido com sucesso.\n", valor);
    } else {
        printf("\nValor %d não foi encontrado no vetor.\n", valor);
    }

    printf("\nVetor atualizado (%d elementos):\n", n);
    for (i = 0; i < n; i++) {
        printf("%d ", vetor[i]);
    }
    printf("\n");

    free(vetor);
    vetor = NULL;

    return 0;
}