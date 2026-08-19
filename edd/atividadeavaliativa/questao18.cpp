#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int* alocarMemoria(int n) {
    int *v = (int *) malloc(n * sizeof(int));
    if (v == NULL) {
        printf("Erro de alocação de memória!\n");
    }
    return v;
}

void preencherMemoria(int *v, int n) {
    if (v == NULL) return;
    for (int i = 0; i < n; i++) {
        printf("Digite o %dº valor: ", i + 1);
        scanf("%d", &v[i]);
    }
}

void exibirMemoria(int *v, int n) {
    if (v == NULL) return;
    printf("\nElementos armazenados: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", v[i]);
    }
    printf("\n");
}

void liberarMemoria(int **v) {
    if (v != NULL && *v != NULL) {
        free(*v);
        *v = NULL;
        printf("Memória liberada com sucesso.\n");
    }
}

int main(int argc, char *argv[]) {
    setlocale(LC_ALL, "Portuguese");

    int *vetor = NULL;
    int n;

    printf("Digite a quantidade de elementos: ");
    scanf("%d", &n);

    vetor = alocarMemoria(n);

    if (vetor == NULL) {
        return 1;
    }

    preencherMemoria(vetor, n);
    exibirMemoria(vetor, n);
    liberarMemoria(&vetor);

    return 0;
}