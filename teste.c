#include <stdio.h>
#include <stdlib.h>
#include "config.h"
#include "comum.h"

int main(){
  TAux lista1 = NULL, lista2 = NULL;
  int info;
  
  
  ler_Num(&lista2, LISTA, CRESCENTE);
  exibir(lista2);
  /* */
  
  
  inserir(&lista1, 2, LISTA, DECRESCENTE);
  inserir(&lista1, 3, LISTA, DECRESCENTE);
  inserir(&lista1, 4, LISTA, DECRESCENTE);
  inserir(&lista1, 5, LISTA, DECRESCENTE);
  inserir(&lista1, 6, LISTA, DECRESCENTE);
  
  exibir(lista1);
  /* */
  
  
  info = comparar(lista1,lista2);
  
  if(info==0)
	printf("\n DIFERENTES \n");
  else
  	printf("\n IGUAIS \n");
  /* */
}
