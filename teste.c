#include <stdio.h>
#include <stdlib.h>
#include "config.h"
#include "comum.h"



int main(){
  TAux lista = NULL;
  inserir(&lista, 2, LISTA, DECRESCENTE);
  inserir(&lista, 3, LISTA, DECRESCENTE);
  inserir(&lista, 4, LISTA, DECRESCENTE);
  inserir(&lista, 5, LISTA, DECRESCENTE);
  inserir(&lista, 6, LISTA, DECRESCENTE);
  exibir(lista);
}
