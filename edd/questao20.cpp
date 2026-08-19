#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

typedef struct {
    int codigo;
    char nome[50];
    float preco;
    int estoque;
} Produto;

void cadastrarProduto(Produto **produtos, int *qtd) {
    Produto *temp = (Produto *) realloc(*produtos, (*qtd + 1) * sizeof(Produto));
    if (temp == NULL) {
        printf("Erro ao realocar memória!\n");
        return;
    }
    *produtos = temp;

    printf("\nCódigo: ");
    scanf("%d", &((*produtos)[*qtd].codigo));
    printf("Nome: ");
    scanf(" %[^\n]", (*produtos)[*qtd].nome);
    printf("Preço: ");
    scanf("%f", &((*produtos)[*qtd].preco));
    printf("Quantidade em estoque: ");
    scanf("%d", &((*produtos)[*qtd].estoque));

    (*qtd)++;
    printf("Produto cadastrado com sucesso!\n");
}

void listarProdutos(Produto *produtos, int qtd) {
    if (qtd == 0) {
        printf("\nNenhum produto cadastrado.\n");
        return;
    }
    printf("\n=== Produtos em Estoque ===\n");
    for (int i = 0; i < qtd; i++) {
        printf("Código: %d | Nome: %s | Preço: R$ %.2f | Estoque: %d\n",
               produtos[i].codigo, produtos[i].nome, produtos[i].preco, produtos[i].estoque);
    }
}

int buscarPorCodigo(Produto *produtos, int qtd, int codigo) {
    for (int i = 0; i < qtd; i++) {
        if (produtos[i].codigo == codigo) return i;
    }
    return -1;
}

void alterarProduto(Produto *produtos, int qtd) {
    int codigo, idx;
    printf("\nDigite o código do produto a alterar: ");
    scanf("%d", &codigo);
    idx = buscarPorCodigo(produtos, qtd, codigo);

    if (idx != -1) {
        printf("Novo nome: ");
        scanf(" %[^\n]", produtos[idx].nome);
        printf("Novo preço: ");
        scanf("%f", &produtos[idx].preco);
        printf("Novo estoque: ");
        scanf("%d", &produtos[idx].estoque);
        printf("Produto alterado!\n");
    } else {
        printf("Produto não localizado.\n");
    }
}

void removerProduto(Produto **produtos, int *qtd) {
    int codigo, idx;
    printf("\nDigite o código do produto a remover: ");
    scanf("%d", &codigo);
    idx = buscarPorCodigo(*produtos, *qtd, codigo);

    if (idx != -1) {
        for (int i = idx; i < *qtd - 1; i++) {
            (*produtos)[i] = (*produtos)[i + 1];
        }
        (*qtd)--;

        if (*qtd > 0) {
            Produto *temp = (Produto *) realloc(*produtos, (*qtd) * sizeof(Produto));
            if (temp != NULL) *produtos = temp;
        } else {
            free(*produtos);
            *produtos = NULL;
        }
        printf("Produto removido com sucesso!\n");
    } else {
        printf("Produto não localizado.\n");
    }
}

void aumentarEstoque(Produto *produtos, int qtd) {
    int codigo, idx, qtd_add;
    printf("\nDigite o código do produto: ");
    scanf("%d", &codigo);
    idx = buscarPorCodigo(produtos, qtd, codigo);

    if (idx != -1) {
        printf("Quantidade a adicionar ao estoque: ");
        scanf("%d", &qtd_add);
        produtos[idx].estoque += qtd_add;
        printf("Estoque atualizado para %d unidades!\n", produtos[idx].estoque);
    } else {
        printf("Produto não localizado.\n");
    }
}

void calcularTotalEstoque(Produto *produtos, int qtd) {
    float total = 0.0;
    for (int i = 0; i < qtd; i++) {
        total += (produtos[i].preco * produtos[i].estoque);
    }
    printf("\nValor total investido no estoque: R$ %.2f\n", total);
}

int main(int argc, char *argv[]) {
    setlocale(LC_ALL, "Portuguese");

    Produto *produtos = NULL;
    int qtd = 0;
    int opcao, codigo, idx;

    do {
        printf("\n--- GERENCIAMENTO DE ESTOQUE ---\n");
        printf("1. Cadastrar produto\n");
        printf("2. Listar produtos\n");
        printf("3. Buscar por código\n");
        printf("4. Alterar produto\n");
        printf("5. Remover produto\n");
        printf("6. Aumentar estoque\n");
        printf("7. Calcular valor total do estoque\n");
        printf("0. Sair\n");
        printf("Opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                cadastrarProduto(&produtos, &qtd);
                break;
            case 2:
                listarProdutos(produtos, qtd);
                break;
            case 3:
                printf("\nDigite o código: ");
                scanf("%d", &codigo);
                idx = buscarPorCodigo(produtos, qtd, codigo);
                if (idx != -1) {
                    printf("Localizado: %s | Preço: R$ %.2f | Estoque: %d\n",
                           produtos[idx].nome, produtos[idx].preco, produtos[idx].estoque);
                } else {
                    printf("Produto não localizado.\n");
                }
                break;
            case 4:
                alterarProduto(produtos, qtd);
                break;
            case 5:
                removerProduto(&produtos, &qtd);
                break;
            case 6:
                aumentarEstoque(produtos, qtd);
                break;
            case 7:
                calcularTotalEstoque(produtos, qtd);
                break;
            case 0:
                printf("\nSaindo do sistema...\n");
                break;
            default:
                printf("\nOpção inválida!\n");
        }
    } while (opcao != 0);

    free(produtos);
    produtos = NULL;

    return 0;
}