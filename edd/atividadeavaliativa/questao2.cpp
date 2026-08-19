#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main(int argc, char *argv[]) {
	    setlocale(LC_ALL, "Portuguese");

	float *numero;
	float espaco;
	
 numero = (float *) malloc (sizeof(float));
 
 if (numero == NULL){
 	printf("Erro ao alocar memória!");
 	
 	return 1;
 	
 }
   printf("Digite o valor do número: ");
    scanf("%f", &espaco );
    
    
	*numero=espaco;
	    
  printf ("Valor original: %.2f\n", *numero);
  
  *numero=*numero *2;
     
 printf ("Valor armazenado: %.2f\n", *numero);
 printf ("Endereço de memória: %p\n", (void*)numero);
 
 free(numero);
     
	return 0;
}