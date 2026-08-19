#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main(int argc, char *argv[]) {
		    setlocale(LC_ALL, "Portuguese");

	int *vetor;
	int numero;
	
	printf ("Quantos valores quer armazenar? ");
	scanf("%d",&numero);
	
	 vetor = (int *) malloc (numero *sizeof(int));
 
 if (vetor == NULL){
 	printf("Erro ao alocar memória!");
 	
 	return 1;
}
   printf("Escreva os %d valores \n", numero);
   for(int i=0; i<numero; i++){
   scanf("%d",&vetor[i]);
   
}
   
   printf("Valores armazenados: \n");
   for( int i=0; i<numero; i++){
   printf("%d ", vetor[i]);	
	
}

printf("\n");

	free(vetor);
	
	return 0;
}