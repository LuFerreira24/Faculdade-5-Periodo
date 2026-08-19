#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main(int argc, char** argv) {
    setlocale(LC_ALL, "Portuguese");
	
	int *numero;
	int espaco;
	
 numero = (int *) malloc (sizeof(int));
 
 if (numero == NULL){
 	printf("Erro ao alocar memória!");
 	
 	return 1;
 	
 }
 printf("Digite o valor do número: ");
 scanf ("%d", &espaco);
  
 *numero = espaco;
 printf ("Valor armazenado: %d\n", *numero);
 printf ("Endereço de memória: %p\n", (void*)numero);

 free(numero);
	
	
	return 0;
}