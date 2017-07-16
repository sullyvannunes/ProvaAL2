void encerrar_execucao(char *s){
  puts(s);
  exit(EXIT_FAILURE);
}

void alocar_e_atribuir(TAux *destino, TAux *novo, int valor, TAux prox){
  if(!(*novo = (TAux) malloc(sizeof(Tno))))
    encerrar_execucao("Memoria insuficiente");
  (*novo)->valor = valor;
  (*novo)->prox = prox;
  *destino = *novo;
}

int is_vazio(TAux lista){
  return !lista;
}

int is_par(int numero){
  return !(numero % 2);
}

int is_impar(int numero){
  return numero % 2;
}

int is_menor(int primeiro, int segundo){
  return primeiro < segundo;
}

int is_maior(int primeiro, int segundo){
  return primeiro > segundo;
}

void iterar(TAux *lista) {
  *lista = (*lista)->prox;
}

TAux buscar(TAux lista, int valor){
  TAux auxiliar = lista;
  while(!is_vazio(auxiliar)){
    if(auxiliar->valor == valor)
      return auxiliar;
  }
  return NULL;
}

int quantidade_de_em(int valor, TAux lista){
  int total = 0;
  TAux auxiliar = lista;
  while(auxiliar){
    if(auxiliar->valor == valor)
      total++;
  }
  return total;
}

void exibir(TAux lista) {
  TAux auxiliar = lista;
  while (auxiliar) {
    printf("Valor: %d\n", auxiliar->valor);
    iterar(&auxiliar);
  }
  puts("");
}

int inserir_pilha(TAux *estrutura, int valor){
  TAux novo;
  if(is_vazio(*estrutura))
   alocar_e_atribuir(estrutura, &novo, valor, NULL);
  else
    alocar_e_atribuir(estrutura, &novo, valor, *estrutura);
  return TRUE;
}

int inserir_fila(TAux *estrutura, int valor){
  TAux auxiliar, novo;
  if(is_vazio(*estrutura)){
    alocar_e_atribuir(estrutura, &novo, valor, NULL);
    return TRUE;
  }
  auxiliar = *estrutura;
  while(!is_vazio(auxiliar->prox)){
    iterar(&auxiliar);
  }
  alocar_e_atribuir(&(auxiliar->prox), &novo, valor, NULL);
  return TRUE;
}

int inserir_lista(TAux *lista, int valor, int ordem){
  return 1;
}

int inserir(TAux *estrutura, int valor, int option, int ordem){
  switch (option) {
    case PILHA:
      return inserir_pilha(estrutura, valor);
    case LISTA:
      return inserir_lista(estrutura, valor, ordem);
    case FILA:
      return inserir_fila(estrutura, valor);
    default:
      return FALSE;
  }
}

int ler_Num(TAux *auxiliar)
{
  FILE *arq=fopen("numeros.txt","r");
  int i;
  if(!arq){
    printf("\n\t\t Erro na abertura de arquivo!\n");
    fclose(arq);
    return 1;
  }
  else{
  while(!feof(arq)){
    fscanf(arq,"%d",&i);
    inserir(auxiliar, i, FILA, DESORDENADO);
  }
    fclose(arq);
    return 0;
  }
}

int tamanho(TAux lista){
int total = 0;
  TAux auxiliar = lista;
  while(!is_vazio(auxiliar)){
    total++;
  }
  return total;
}
