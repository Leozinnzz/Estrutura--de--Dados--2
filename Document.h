#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Document{
	int id;
	char* name;
	int bytes;
	int pag;
	struct Document* next; 
}Document;

//Document* temp = head->next
//free(head)
//return p

/*
 encapsular a lista // lista circular com cabeça
 typedef struct Queue {
	Produto* head;
	Produto* tail;
	int size/
 }Queue;

*/

//cricao da lista
typedef struct List{
	Document* head;
	Document* tail;
	int size;
}List;

typedef List* Lista;

List* new_list(){
	List* l = (List*) malloc(sizeof(List)); 
	
	l->head = NULL;
	l->tail = NULL;
	l->size = 0;
	return l;
}

void new_document(List* list){
	Document* new = (Document*) malloc(sizeof(Document)); 
	new->id = rand()%100;
	
	char temp[100];
	
	printf("Digite o nome do documento: ");
	scanf(" %[^\n]", temp); 
	
	new->name = (char*) malloc(strlen(temp)+1);
	strcpy(new->name, temp);
	
	printf("Digite a quantidade de paginas do documento: ");
	scanf("%d", &new->pag);
	
	new->bytes = 100 + rand()%1000;
	
	/*new->next = list->head; //o novo no aponta para o documento atual
	list->tail->next = new; // o antigo ultimo aponta para o novo 
	list->tail = new; // o tail agora e o novo no */
	
	new->next = NULL;
	
	if (!list->head) {
		list->head = list->tail = new;
		list->size++;
		return;
	}
	
	list->tail->next = new;
	list->tail = new;
	
	list->size++; //incrementa a lista
}

void fila_imprimir(List* l){
	
	if(l->size == 0) {
		printf("A lista esta vazia");
		return;
	}
	
	Document* aux = l->head;

	
	while(aux) {
		printf("ID: %d || Nome: %s || Paginas %d. || Tamanho(Bytes): %db\n",
		aux->id, aux->name, aux->pag, aux->bytes);
		aux = aux->next;
	}
}


void imprimir(List* l){
	
	if (l->size == 0) {
		printf("A lista esta vazia...");
		return;
	}
	
	Document* act = l->head->next; 
	
	if(!l->head->next) {
		printf("Nao ha documentos na lista");
		return;
	}
		
	
	if(l->head->next)  {
		printf("ID: %d || Nome: %s || Paginas %d. || Tamanho(Bytes): %db\n",
		act->id, act->name, act->pag, act->bytes);
		free(act->name);
		free(act);
		l->size--;
	}
	

}

void excluir_doc(List* list){
	if(!list || !list->head) {
		printf("Nao ha documentos para exclusao");
		return;
	}
	
	int alvo;
	printf("Digite o ID: "); 
	scanf(" %i", &alvo);
	
	 list->head->id == alvo? printf(" %d", alvo) : printf("Falso");
	
	
	//errro
	if(list->head->id == alvo) {
		
		Document* head = list->head;
		
		printf("Documento encontrado! ID %d | Nome: %s | numero de paginas: %d | tamanho: %d\n", head->id, head->name, head->pag, head->bytes);
		list->head = list->head->next;
		
		if(!list->head)
			list->tail = NULL;
		
		free(head->name);
		free(head);
		list->size--;
	
		printf("Documento excluido com sucesso!");
		return;
	}
	
	printf("Produto nao encontrado");
}


