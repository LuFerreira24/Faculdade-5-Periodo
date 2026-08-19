#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int* alocarVetor(int n) {
    int *v = (int *) malloc(n * sizeof(int));
    return v;
}

void preencherVetor(int *v, int n) {
    for (int i = 0; i < n; i++) {
        printf("Digite o %dº valor: ", i + 1);
        scanf("%d", &v[i]);
    }
}

float calcularMedia(int *v, int n) {
    float soma = 0.0;
    for (int i = 0; i < n; i++) {
        soma += v[i];
    }
    return soma / n;
}

void exibirVetor(int *v, int n) {
    printf("Elementos do vetor: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", v[i]);
    }
    printf("\n");
}

int main(int argc, char *argv[]) {
    setlocale(LC_ALL, "Portuguese");

    int *vetor = NULL;
    int n;

    printf("Digite o tamanho do vetor: ");
    scanf("%d", &n);

    vetor = alocarVetor(n);

    if (vetor == NULL) {
        printf("Erro ao alocar memória!\n");
        return 1;
    }

    preencherVetor(vetor, n);
    printf("\n");
    exibirVetor(vetor, n);
    printf("Média dos elementos: %.2f\n", calcularMedia(vetor, n));

    free(vetor);
    vetor = NULL;

    return 0;
}