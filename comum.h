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
    auxiliar = auxiliar->prox;
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

int inserir(TAux *estrutura, int valor, int option){
  switch (option) {
    case PILHA:
      return inserir_pilha(estrutura, valor);
    case LISTA:
      return inserir_pilha(estrutura, valor);
    case FILA:
      return inserir_fila(estrutura, valor);
    default:
      return FALSE;
  }
}

int alterar_lista (TAux *lista, int valor1, int valor2){
TAux auxiliar = *lista;
TAux aux;

	if ( (is_vazio(auxiliar)) || (aux = buscar(auxiliar,valor1) ==  NULL) ){
	return FALSE;	
	}else
	{
	auxiliar = buscar(auxiliar,valor1);
	auxiliar->valor = valor2;
	return TRUE;	
	}
  
}
