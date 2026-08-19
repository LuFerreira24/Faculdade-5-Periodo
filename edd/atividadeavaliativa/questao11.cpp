#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main(int argc, char *argv[]) {
    setlocale(LC_ALL, "Portuguese");

    float *notas = NULL;
    int n, i;
    float soma = 0.0, media, maior, menor;

    printf("Quantas notas serão cadastradas?: ");
    scanf("%d", &n);

    notas = (float *) malloc(n * sizeof(float));

    if (notas == NULL) {
        printf("Erro ao alocar memória!\n");
        return 1;
    }

    for (i = 0; i < n; i++) {
        printf("Digite a %dª nota: ", i + 1);
        scanf("%f", &notas[i]);
        soma += notas[i];
    }

    media = soma / n;
    maior = notas[0];
    menor = notas[0];

    for (i = 1; i < n; i++) {
        if (notas[i] > maior) maior = notas[i];
        if (notas[i] < menor) menor = notas[i];
    }

    printf("\nMédia: %.2f\n", media);
    printf("Maior nota: %.2f\n", maior);
    printf("Menor nota: %.2f\n", menor);

    free(notas);
    notas = NULL;

    return 0;
}