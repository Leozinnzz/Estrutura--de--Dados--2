#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct TypeDocument {
	int id;
	char* name;
	int pgs;
	int tam;
	struct TypeDocument* ant;
	struct TypeDocument* prox;
}TypeDocument;

typedef TypeDocument* Document;


typedef struct TypeList{
	Document head;
	Document tail;
	int size;
}TypeList;

typedef TypeList* List;


List new_List(){
	List lst = malloc(sizeof(TypeDocument)); 
	lst->head = NULL;
	lst->tail = NULL;
	lst->size = 0;
	return lst;
}

Document new_Document(List lst, int id, char* name, int pgs, int tam){
	Document doc = malloc(sizeof(TypeDocument));
	doc->prox = NULL;
	
	doc->ant = lst->tail;
	if(!lst->tail)
		lst->tail->prox = doc;
	lst->tail = doc;
	
	doc->id = id;
	doc->pgs = pgs;
	doc->tam = tam;
	doc->name = malloc(strlen(name)+1);
	strcpy(doc->name, name);
	
	
	if(!lst->head)
		lst->head = doc;
		
	lst->size++;
	return doc;
}

void print_Document(Document d){
	printf("ID: %d		Nome: %s		Paginas: %d		Tamanho: %d	\n", d->id, d->name, d->pgs, d->tam);
}

void print_lista(List lst){
	Document doc = lst->head;
	
	if(!doc) {
		printf("A lista esta vazia");
		return;
	}
	
	while(doc){
		print_Document(doc);
		doc = doc->prox;
	}
}

void impr_doc(List lst){
	
	if(!lst->size || !lst->head) {
		printf("Nao ha elementos na lista");
		return;
	}
	
	Document dc = lst->head;
	
	printf("\n============== Fila de documentos ===============\n");
	print_lista(lst);
	
	int id;
	printf("Digite o id do documento para imprimir: ");
	scanf("%d", &id);
	
	if(!dc) {
		printf("Documento nao encontrado");
		return;
	}
	
	if(dc->id == id) {
		lst->head = dc->prox;
		if(!lst->head)
			lst->tail = NULL;
		else 
			lst->head->ant = NULL;
			
		print_Document(dc);
		free(dc->name);
		free(dc);
		lst->size--;
	}
	
}

void excluir(List lst){
	
	if(!lst->size || !lst->head) {
		printf("Nao ha elementos na lista para excluir");
		return;
	}
	
	Document alvo = lst->head;
	
	int id;
	printf("Digite o id para a exclusao: ");
	scanf("%d", &id);
	
	if(!alvo){ 
		printf("Alvo nao encontrado");
		return;
	}
	
	if(alvo->id == id) {
		lst->head = alvo->prox;
		
		if(!lst->head)
			lst->tail = NULL;
		else 
			lst->head->ant = NULL;
			
		free(alvo->name);
		free(alvo);
		lst->size--;
		return;
	}
	
	Document alvo2 = lst->head->prox;
	
	while(alvo2) {
		// se o alvo estiver no meio
		if(alvo->id == id) {
			
			if(alvo2->ant)
				alvo2->ant->prox = alvo2->prox;
	
			//se o proximo existir
			if(alvo->prox)
				alvo2->prox->ant = alvo->ant;
			else
				lst->tail = alvo2->ant; // caso contrario vai apontar para um novo tail
		
			free(alvo2->name);
			free(alvo2);
			lst->size--;
			printf("Exclusao concluida!!");
			return;
		}
		alvo2 = alvo2->prox;
	}
	
}


Document priori(List lst, int id, char* name, int pgs, int tam){
	Document new = malloc(sizeof(TypeDocument)); 
	
	new->ant = NULL;
	new->prox = lst->head;
	
	
	new->id = id;
	new->pgs = pgs;
	new->tam = tam;
	new->name = malloc(strlen(name)+1);
	strcpy(new->name, name);
	
	if(!lst->head)
		lst->tail = new;
	else 
		lst->head->ant = new;
	
	lst->head = new;
	lst->size++;
	return new;
}


