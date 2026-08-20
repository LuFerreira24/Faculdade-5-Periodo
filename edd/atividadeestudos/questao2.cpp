#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main() {
setlocale(LC_ALL, "Portuguese"); 

int num[10];
int i;
int soma = 0;
float media = 0;

printf("Digite 10 valores inteiros: ");
for (i=0; i<10; i++){
scanf("%d", &num[i]);
soma = soma + num[i];
}

int maior = num[0];
int menor = num[0];

for (i = 0; i < 10; i++) {
    if (maior < num[i]) maior = num[i];
    if (menor > num[i]) menor = num[i];
}

 media = soma/10.0;

printf("A soma dos valores é: %d\n", soma);
printf("A média dos valores é: %.2f\n", media);
printf("O maior número é: %d\n", maior);
printf("O menor número é: %d\n", menor);

return 0;
}