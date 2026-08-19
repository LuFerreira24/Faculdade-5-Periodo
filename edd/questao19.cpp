#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

typedef struct {
    int codigo;
    char produto[50];
    int quantidade;
    float preco_unitario;
} Venda;

int main(int argc, char *argv[]) {
    setlocale(LC_ALL, "Portuguese");

    Venda *vendas = NULL;
    Venda *temp = NULL;
    int qtd = 0;
    int opcao, codigo_busca, i, encontrado;
    float faturamento_total;

    do {
        printf("\n--- Sistema de Vendas ---\n");
        printf("1. Cadastrar Venda\n");
        printf("2. Listar Vendas\n");
        printf("3. Calcular Faturamento Total\n");
        printf("4. Buscar Venda por Código\n");
        printf("0. Sair\n");
        printf("Opção: ");
        scanf("%d", &opcao);

        if (opcao == 1) {
            temp = (Venda *) realloc(vendas, (qtd + 1) * sizeof(Venda));
            if (temp == NULL) {
                printf("Erro ao realocar memória!\n");
            } else {
                vendas = temp;
                printf("\nCódigo da Venda: ");
                scanf("%d", &vendas[qtd].codigo);
                printf("Nome do Produto: ");
                scanf(" %[^\n]", vendas[qtd].produto);
                printf("Quantidade: ");
                scanf("%d", &vendas[qtd].quantidade);
                printf("Preço Unitário: ");
                scanf("%f", &vendas[qtd].preco_unitario);
                qtd++;
                printf("Venda cadastrada com sucesso!\n");
            }
        } else if (opcao == 2) {
            printf("\n=== Lista de Vendas (%d) ===\n", qtd);
            for (i = 0; i < qtd; i++) {
                printf("Código: %d | Produto: %s | Qtd: %d | Unidade: R$ %.2f | Total: R$ %.2f\n",
                       vendas[i].codigo, vendas[i].produto, vendas[i].quantidade,
                       vendas[i].preco_unitario, vendas[i].quantidade * vendas[i].preco_unitario);
            }
        } else if (opcao == 3) {
            faturamento_total = 0.0;
            for (i = 0; i < qtd; i++) {
                faturamento_total += (vendas[i].quantidade * vendas[i].preco_unitario);
            }
            printf("\nFaturamento Total: R$ %.2f\n", faturamento_total);
        } else if (opcao == 4) {
            printf("\nDigite o código da venda: ");
            scanf("%d", &codigo_busca);
            encontrado = 0;
            for (i = 0; i < qtd; i++) {
                if (vendas[i].codigo == codigo_busca) {
                    printf("Venda localizada:\n");
                    printf("Produto: %s | Qtd: %d | Total: R$ %.2f\n",
                           vendas[i].produto, vendas[i].quantidade,
                           vendas[i].quantidade * vendas[i].preco_unitario);
                    encontrado = 1;
                    break;
                }
            }
            if (!encontrado) printf("Venda não encontrada.\n");
        }
    } while (opcao != 0);

    free(vendas);
    vendas = NULL;

    return 0;
}