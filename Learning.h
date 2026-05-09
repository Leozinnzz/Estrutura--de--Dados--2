#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct TipoDocumento{
	int id;
	char* nome; 
	int pgs;
	int tam; 
	struct TipoDocumento* ant;
	struct TipoDocumento* prox;
}TipoDocumento; 

typedef TipoDocumento* Documento; 

typedef struct TipoLista{
	Documento head; 
	Documento tail; 
	int size; 
}TipoLista;

typedef TipoLista* Lista; 

Lista criar_lista(){
	Lista lst = (Lista) malloc(sizeof(TipoLista));
	lst->head = NULL;
	lst->tail = NULL; 
	lst->size = 0; 
	return lst;
}

Documento criar_documento(Lista lst, int id, char nome[], int pgs, int tam){
	Documento novo = (Documento) malloc(sizeof(TipoDocumento));
	novo->prox = NULL;
	novo->ant = lst->tail;
	
	if(!lst->tail)
		lst->head = novo;
	else 
		lst->tail->prox = novo;
		
	lst->tail = novo;
		
	novo->id = id;
	novo->pgs = pgs;
	novo->tam = tam; 
	novo->nome = (char*) malloc(strlen(nome)+1);
	strcpy(novo->nome, nome);
	
	lst->size++;
	return novo;
}

void print_documento(Documento d) {
	printf("ID: %d		Nome: %s		Paginas: %d		Tamanho: %d	\n", d->id, d->nome, d->pgs, d->tam);
}

void print_Lista(Lista lst) {
	Documento aux = lst->head;
	if(!aux){
		printf("Não ha documentos na lista ");
		return;
	}
	while(aux != NULL) {
		print_documento(aux);
		aux = aux->prox;
	}
}

void imprimir(Lista lt) {
	
	if(!lt->size || !lt->head) {
		printf("A lista esta vazia");
		return;
	}
	
	Documento doc = lt->head; 
	
	while(doc){
		lt->head = doc->prox;
		if(!lt->head)
			lt->tail = NULL;
		else 
			lt->head->ant = NULL;
		
		print_documento(doc);
		free(doc->nome);
		free(doc);
		lt->size--; 
		break;
	}

}


void apagar_documento(Lista l){
	
	if(!l->size || !l->head) {
		printf("A lista esta vazia");
		return; 
	}
	
	Documento alvo = l->head;
	
	printf("\n-------------------------LISTA DE DOCUMENTOS-------------------------\n");
	print_Lista(l);
	
	int id;
	printf("Digite o id do documento para a exclusão: ");
	scanf("%d", &id);
	
	
	if(alvo->id == id) {
		l->head = alvo->prox;
		
		if(!l->head)
			l->tail = NULL;
		else 
			l->head->ant = NULL;
			
		free(alvo->nome);
		free(alvo);
		printf("Exclusão concluida");
		return;
	}
	
	Documento alvo2 = l->head;
	
	while(alvo2) {
		
		if(alvo2->id == id) { 
			if(alvo2->ant)
				alvo2->ant->prox = alvo2->prox;
			else 
				l->head = alvo2->prox;
			
			if(alvo2->prox) 
				alvo2->prox->ant = alvo2->ant;
			else
				l->tail = alvo2->ant;
				
		free(alvo2->nome);
		free(alvo2); 
		printf("Alvo excluido!");
		l->size--;
		return;
		}
		alvo2 = alvo2->prox;
	}
	printf("Alvo nao encontrado");
}

void priorizar(Lista lst){
	Documento current = lst->head;

	int id; 
	printf("Digite o id do documento para priorizar: ");
	scanf("%d", &id);
	
	while(current) {
		if(current->id == id) {
			if(current == lst->head)
				return;
			if(current->ant)
				current->ant->prox = current->prox;
			if(current->prox)
				current->prox->ant = current->ant;
			else 
				lst->tail = current->ant;
				
			current->prox = lst->head;
			current->ant = NULL;
			
			if(lst->head)
				lst->head->ant = current;
			
			lst->head = current;
			printf("Documento priorizado");
			return;
		}
		current = current->prox;
		
	}
	printf("Esse id nao existe");
}


