#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main(){
        setlocale(LC_ALL, "Portuguese"); 

        int i;
        int numeros[10];
        int inicio, fim, temp;
        
                printf("Digite 10 números inteiros:\n\n");

        for(i=0; i<10; i++){
            printf("Digite o %dº número: ", i + 1);
            scanf("%d", &numeros[i]);
        }

            printf("Números na ordem correta: ");
        for(i=0; i<10; i++){
            printf("%d ", numeros[i]);
        }
        printf("\n");

        for(i=0; i<5; i++){
            temp = numeros[i];
            numeros[i] = numeros[9 - i];
            numeros[9 - i] = temp;
        }

            printf("Números na ordem invertida: ");
        for(i=0; i<10; i++){
            printf("%d ", numeros[i]);
        }
                printf("\n");

return 0;
}