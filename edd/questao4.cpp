#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main(int argc, char *argv[]) {
    setlocale(LC_ALL, "Portuguese");

    int *vetor;
    int numero;
    int soma = 0;

    printf("Quantos valores quer armazenar? ");
    scanf("%d", &numero);

    vetor = (int *) malloc(numero * sizeof(int));

    if (vetor == NULL) {
        printf("Erro ao alocar a memória!\n");
        return 1;
    }

    printf("Escreva os %d valores:\n", numero);
    for (int i = 0; i < numero; i++) {
        scanf("%d", &vetor[i]);
        soma += vetor[i];
    }

    printf("\nValores armazenados: ");
    for (int i = 0; i < numero; i++) {
        printf("%d ", vetor[i]);
    }

    printf("\nSoma dos elementos: %d\n", soma);

    free(vetor);
    vetor = NULL;

    return 0;
}