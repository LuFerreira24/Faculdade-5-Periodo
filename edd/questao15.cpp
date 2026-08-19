#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

typedef struct {
    int codigo;
    char nome[50];
    float preco;
} Produto;

int main(int argc, char *argv[]) {
    setlocale(LC_ALL, "Portuguese");

    Produto *produtos = NULL;
    Produto *temp = NULL;
    int capacidade = 3;
    int qtd = 0;
    char opcao;

    produtos = (Produto *) malloc(capacidade * sizeof(Produto));

    if (produtos == NULL) {
        printf("Erro ao alocar memória!\n");
        return 1;
    }

    do {
        if (qtd == capacidade) {
            capacidade *= 2;
            temp = (Produto *) realloc(produtos, capacidade * sizeof(Produto));
            if (temp == NULL) {
                printf("Erro ao expandir memória!\n");
                break;
            }
            produtos = temp;
        }

        printf("\n--- Cadastro do Produto %d ---\n", qtd + 1);
        printf("Código: ");
        scanf("%d", &produtos[qtd].codigo);
        printf("Nome: ");
        scanf(" %[^\n]", produtos[qtd].nome);
        printf("Preço: ");
        scanf("%f", &produtos[qtd].preco);
        qtd++;

        printf("Deseja cadastrar outro produto? (s/n): ");
        scanf(" %c", &opcao);

    } while (opcao == 's' || opcao == 'S');

    printf("\n=== Produtos Cadastrados (%d) ===\n", qtd);
    for (int i = 0; i < qtd; i++) {
        printf("Código: %d | Nome: %s | Preço: R$ %.2f\n", produtos[i].codigo, produtos[i].nome, produtos[i].preco);
    }

    free(produtos);
    produtos = NULL;

    return 0;
}