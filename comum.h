void encerrar_execucao(char *s);
void alocar_e_atribuir(TAux *destino, TAux *novo, int valor, TAux prox);
int tamanho(TAux lista);
int is_vazio(TAux lista);
int is_par(int numero);
int is_impar(int numero);
int is_menor(int primeiro, int segundo);
int is_maior(int primeiro, int segundo);
void iterar(TAux *lista);
TAux buscar(TAux lista, int valor);
int quantidade_de_em(int valor, TAux lista);
void exibir(TAux lista);
int inserir_pilha(TAux *estrutura, int valor);
int inserir_fila(TAux *estrutura, int valor);
int inserir_lista(TAux *lista, int valor, int ordem);
int inserir(TAux *estrutura, int valor, int option, int ordem);
int ler_Num(TAux *auxiliar, int option, int ordem);
int condition_inserir(int primeiro, int segundo, int condition);
int comparar(TAux L1, TAux L2);
void copiar(TAux orig,TAux *cop);

void encerrar_execucao(char *s){
  puts(s);
  exit(EXIT_FAILURE);
}

void copiar(TAux orig,TAux *cop) // copia uma lista para outra
{
	if(orig)
	{
       	*cop = (TAux) malloc(sizeof(Tno));
       	(*cop)->valor = orig->valor;
       	(*cop)->prox = NULL;
    	copiar(orig->prox,&((*cop)->prox));
	}
}

int comparar(TAux L1, TAux L2)
{
	TAux aux1=L1, aux2=L2;
	int tam1=0, tam2=0, cont=0;
	
	tam1=tamanho(aux1);
	tam2=tamanho(aux2);
	
	if(tam1 == tam2)
	{
		aux1 = L1;
		aux2 = L2;

		while (aux1 != NULL)
		{
			if (aux1->valor == aux2->valor)
			{
				cont++;
			}
			aux1 = aux1->prox;
			aux2 = aux2->prox;
		}
		
		if(cont == tam1)
		{
			return TRUE;
		}
		return FALSE;
	}
	return FALSE;
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

int tamanho(TAux lista){
  int total = 0;
  TAux auxiliar = lista;
  while(!is_vazio(auxiliar)){
	total++;
	iterar(&auxiliar);
  }
  return total;
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

int condition_inserir(int primeiro, int segundo, int condition){
  if(condition == DECRESCENTE)
    return is_maior(primeiro, segundo);
  else
    return is_menor(primeiro, segundo);
}

int inserir_lista(TAux *lista, int valor, int ordem){
  TAux auxiliar, novo;
  if(ordem == DESORDENADO)
    return inserir_pilha(lista, valor);
  else{
    if(is_vazio(*lista) || condition_inserir(valor, (*lista)->valor, ordem)){
      alocar_e_atribuir(lista, &novo, valor, *lista);
      return TRUE;
    }
    auxiliar = *lista;
    while(auxiliar->prox){
      if(condition_inserir(valor, (*lista)->valor, ordem)){
        alocar_e_atribuir(&auxiliar, &novo, valor, auxiliar->prox);
        return TRUE;
      }
      iterar(&auxiliar);
    }
    alocar_e_atribuir(&(auxiliar->prox), &novo, valor, NULL);
    return TRUE;
  }
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

int ler_Num(TAux *auxiliar, int option, int ordem)
{
  FILE *arq = fopen("numeros.txt","r");
  int i;
  if(!arq){
    printf("\n\t\t Erro na abertura de arquivo!\n");
    fclose(arq);
    return 1;
  }
  else{
  while(!feof(arq)){
    fscanf(arq,"%d",&i);
    inserir(auxiliar, i, option, ordem);
  }
    fclose(arq);
    return 0;
  }
}
