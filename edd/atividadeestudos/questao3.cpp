#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main(){
    setlocale(LC_ALL, "Portuguese"); 

    int numeros[20];
    int i;
    int positivos = 0;
    int negativos = 0;
    int zeros = 0;
    float porcentagem = 0;

    printf("Digite 20 números inteiros:\n\n");

    for(i = 0; i < 20; i++){
        printf("Digite o %dº número: ", i + 1);
        scanf("%d", &numeros[i]);

        if (numeros[i] > 0){
            positivos++;
        } else if (numeros[i] < 0){
            negativos++;
        } else {
            zeros++;
        }
    }

    porcentagem = (positivos/20.0)*100;

printf("Há %d números positivos.\n", positivos);
printf("Há %d números negativos.\n", negativos);
printf("Há %d números 0\n", zeros);
printf("A porcentagem de números positivos é: %.2f%", porcentagem);


    return 0;
}