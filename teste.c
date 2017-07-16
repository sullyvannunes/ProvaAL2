#include <stdio.h>
#include <stdlib.h>
#include "config.h"
#include "comum.h"



int main(){
  TAux fila = NULL;
  inserir(&fila, 2, FILA);
  exibir(fila);
  inserir(&fila, 3, FILA);
  exibir(fila);
}
