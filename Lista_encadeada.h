#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct TypeDocument{
	int id;
	char* name;
	int pag;
	int tam;
	struct TypeDocument* ant;
	struct TypeDocument* prox;
}TypeDocument;

typedef TypeDocument* Document;

typedef struct TypeList {
	Document head;
	Document tail;
	int size;
}TypeList;

typedef TypeList* List;

List new_List(){
	List lst = (List) malloc(sizeof(TypeList));
	lst->head = NULL; 
	lst->tail = NULL;
	lst->size = 0;
	return lst;
}

Document new_Document(List lst, int id,  char* name, int pag, int tam){
	Document novo = (Document) malloc(sizeof(TypeDocument)); 
	novo->prox = NULL;
	
	novo->ant = lst->tail; 
	if(lst->tail)
		lst->tail->prox = novo; 
		
	novo->id = id;
	novo->pag = pag;
	novo->tam = tam;
	novo->name = (char*) malloc(strlen(name)+1);
	strcpy(novo->name, name);
	
	lst->tail = novo; 
	if(!lst->head) 
		lst->head = novo; //caso nao tiver o inicio o novo inicio vai ser o novo documento
		
	lst->size++; 
	return novo;
	
}

void print_Document(Document d){
	printf("ID: %d		Nome: %s		Paginas: %d		Tamanho: %d	\n", d->id, d->name, d->pag, d->tam);
}

void print_List(List l){
	Document doc = l->head; 
	if(!doc) {
		printf("Nao ha documentos para mostrar");
		return;
	}
	while(doc) {
		print_Document(doc);
		doc = doc->prox;
	}
}



void imprimir_doc(List lst){
	
	if(!lst->size || !lst->head) {
		printf("A lista esta vazia");
		return;
	}
	
	Document doc = lst->head; 

	
	printf("\n============== Fila de documentos ===============\n");
	print_List(lst);
	

		
	if(doc != NULL) {
		
		lst->head = doc->prox; 
		
		if(!lst->head)		
			lst->tail = NULL;
		else 
			lst->head->ant = NULL;
		
		print_Document(doc);
		free(doc->name);
		free(doc);
		lst->size--;
		return;
	}
	printf("Alvo nao encontrado");
}

void delete_doc(List lst){
	
	if(!lst->size || !lst->head){
		printf("A lista esta vazia");
		return;
	}
	
	Document alvo = lst->head;
	int id;
	
	printf("Digita o id do alvo: ");
	scanf("%d", &id);
	
	if(alvo->id == id) {
		lst->head = alvo->prox;
		
		if(lst->head)
			lst->tail = NULL;
		else 
			lst->head->ant = NULL;
			
		free(alvo->name);
		free(alvo);
		lst->size--;
		printf("Exclusão concluida!");
		return;
	}
	
	Document target = lst->head;
	
	while(target) {
		if(target->id == id) {
			if(target->ant)
				target->ant->prox = target->prox;
			else 
				lst->head = target->prox;
			
			if(target->prox)
				target->prox->ant = target->ant;
			else 
				lst->tail = target->ant;
			
			free(target->name);
			free(target);
			printf("Exclusao concluida!");
			return;
		}
		target = target->prox;
	}
	printf("Alvo nao encontrado!");
}

void doc_priority(List lst){
	Document atual = lst->head;
	
	int id;
	printf("Digita o id do alvo para priorizar: ");
	scanf("%d", &id);
	
	while(atual) {
		if(atual->id == id) {
			if(atual == lst->head) 
				return;
			if(atual->ant)
				atual->ant->prox = atual->prox;
			if(atual->prox)
				atual->prox->ant = atual->ant;
			else 
				lst->tail = atual->ant;
				
			atual->prox = lst->head;
			atual->ant = NULL;
			
			if(lst->head)
				lst->head->ant = atual;
			lst->head = atual;
			printf("Documento priorizado");
			return;
		}
		atual = atual->prox;
	}
	printf("Esse id nao existe");
}
