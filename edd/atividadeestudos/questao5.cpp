#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

int main(){
SetConsoleOutputCP(65001);

        int i;
        int numeros[20];
        int buscado;
        int encontrados=0;

        for(i=0; i<20; i++){
            printf("Digite o %dº número: ", i + 1);
            scanf("%d", &numeros[i]);
        }

        printf("\nValores guardados! Qual número deseja buscar?");
        scanf("%d", &buscado);

                for(i=0; i<20; i++){
                    
                    if(buscado == numeros[i]){
                        printf("O número %d está na %dº posição!\n", buscado, i + 1);
                        encontrados++;
                    }
                }

                if(encontrados == 0){
                    printf("Valor não encontrado!");
                } else {
                printf("O valor %d aparece %d vezes!", buscado, encontrados);
                }

                return 0;
}