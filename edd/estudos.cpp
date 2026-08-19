#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main() {
setlocale(LC_ALL, "Portuguese"); 

int n[10];
int i;

printf("Digite os 10 valores:");
for (i=0;i<10;i++){
    scanf("%d", &n[i]);
}

    printf("\n");

    printf("Valores inseridos:\n");
    for(i=0;i<10;i++){
    printf("%d3 ", n[i]);
    }
}