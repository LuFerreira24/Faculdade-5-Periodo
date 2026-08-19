#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main(int argc, char *argv[]) {
    setlocale(LC_ALL, "Portuguese");

    float *vetor;
    int n, i;
    float soma = 0.0, media, maior;

    printf("Digite o tamanho do vetor: ");
    scanf("%d", &n);

    vetor = (float *) malloc(n * sizeof(float));

    if (vetor == NULL) {
        printf("Erro ao alocar a memória!\n");
        return 1;
    }

    for (i = 0; i < n; i++) {
        printf("Digite o %dº valor: ", i + 1);
        scanf("%f", &vetor[i]);
        soma += vetor[i];
    }

    media = soma / n;

    maior = vetor[0];
    for (i = 1; i < n; i++) {
        if (vetor[i] > maior) {
            maior = vetor[i];
        }
    }

    printf("\nMédia = %.2f\n", media);
    printf("Maior valor = %.2f\n", maior);

    free(vetor);
    vetor = NULL;

    return 0;
}