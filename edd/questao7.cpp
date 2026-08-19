#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main(int argc, char *argv[]) {
    setlocale(LC_ALL, "Portuguese");

    int *vetor;
    int i, n; 
    int pares = 0, impares = 0;

    printf("Digite a quantidade de números: ");
    scanf("%d", &n);

    vetor = (int *) malloc(n * sizeof(int));

    if (vetor == NULL) {
        printf("Erro ao alocar a memória para o vetor!\n");
        return 1;
    }

    for (i = 0; i < n; i++) {
        printf("Digite o %dº valor: ", i + 1);
        scanf("%d", &vetor[i]);
    }

    for (i = 0; i < n; i++) {
        if (vetor[i] % 2 == 0) {
            pares++;
        } else {
            impares++;
        }
    }

    printf("\nQuantidade de pares: %d\n", pares);
    printf("Quantidade de ímpares: %d\n", impares);

    free(vetor);
    vetor = NULL;

    return 0;
}