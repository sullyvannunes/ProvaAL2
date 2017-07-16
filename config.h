/*arquivo que declara as variaveis que serão usadas durante a execução do programa*/

#define TRUE 1
#define FALSE 0

#define FILA 10
#define LISTA 11
#define PILHA 12

typedef struct no{
  int valor;
  struct no *prox;
  struct no *pre;
} Tno;

typedef Tno* TAux;
