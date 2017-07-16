#include <stdio.h>
#include <stdlib.h>
#include "config.h"
#include "comum.h"



int main(){
  TAux fila = NULL;
  inserir(&fila, 2, PILHA, DESORDENADO);
  inserir(&fila, 3, PILHA, DESORDENADO);
  inserir(&fila, 4, PILHA, DESORDENADO);
  inserir(&fila, 5, PILHA, DESORDENADO);
  inserir(&fila, 6, PILHA, DESORDENADO);
  exibir(fila);
}
