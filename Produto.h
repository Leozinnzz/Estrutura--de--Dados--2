#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct TypeProduct {
	int id;
	char* name; 
	float preco; 
	int quantity;
	struct TypeProduct* ant; 
	struct TypeProduct* prox; 
}TypeProduct;

typedef TypeProduct* Product;

typedef struct TypeList {
	Product head;
	Product tail; 
	int size; 
}TypeList;

typedef TypeList* List;

List new_list() {
	List lst = (List) malloc(sizeof(TypeList)); 
	lst->head = NULL; 
	lst->tail = NULL; 
	lst->size = 0;
	return lst;
}

Product new_product(List lst, int id, char* name, float value, int quant){
	Product novo = (Product) malloc(sizeof(TypeProduct)); 
	novo->prox = NULL; 
	novo->ant = lst->tail;
	if(!lst->tail)
		lst->head = novo; 
	else 
		lst->tail->prox = novo;
		
	lst->tail = novo;
	
	novo->id = id; 
	novo->preco = value; 
	novo->quantity = quant; 
	novo->name = (char*) malloc(strlen(name)+1);
	strcpy(novo->name, name);

	lst->size++; 
	return novo;
}

void get_product(Product p) {
	printf("ID: %d\t\tDescricao: %s\t\tPreco: %.2f\t\tQuantidade: %d\n", p->id, p->name, p->preco, p->quantity); 
}

void get_list(List lst){
	if(!lst->size || !lst->head) {
		printf("A lista esta vazia"); 
		return; 
	}

	Product temp = lst->head;
	while(temp) {
		get_product(temp);
		temp = temp->prox;
	}
		
}

void buy_product(List lst){
	if(!lst->size ||!lst->head) {
		printf("A lista esta vazia"); 
		return;
	}
	
	Product aux = lst->head; 
	
	while(aux){
		lst->head = aux->prox;
		
		if(!lst->head)
			lst->tail = NULL; 
		else 
			lst->head->ant = NULL;
			
		get_product(aux);
		free(aux->name); 
		free(aux);
		lst->size--;  
		return;
	}
}

void delete_product(List lst) {
	if(!lst->size || !lst->head) {
		printf("Essa lista esta vazia"); 
		return;
	}
	
	Product alvo = lst->head;
	
	printf("\n====================== LISTA DE PRODUTOS ======================\n"); 
	get_list(lst);
	
	int id; 
	printf("Digite o id para a exclusao: "); 
	scanf("%d", &id); 
	
	while(alvo) {
		if(alvo->id == id) {
			if(alvo->ant)
				alvo->ant->prox = alvo->prox;
			else 
				lst->head = alvo->prox;
				
			if(!lst->head)
				lst->tail = NULL; 
			else 
				lst->head->ant = NULL; 
				
			if(alvo->prox)
				alvo->prox->ant = alvo->ant; 
			else 
				lst->tail = alvo->ant;
				
			free(alvo->name);
			free(alvo); 
			lst->size--;
			printf("Exclusao concluida "); 
			return;
		}
		alvo = alvo->prox;
	}
	
}

void priority(List lst) {
	if(!lst->size ||!lst->head) {
		printf("A lista esta vazia"); 
		return;
	}
	
	Product aux = lst->head; 
	
	printf("\n====================== LISTA DE PRODUTOS ======================\n"); 
	get_list(lst);
	
	int id;
	printf("\nDigite o id do produto para ser priorizado: "); 
	scanf("%d", &id);
	
	while(aux) {
		if(aux->id == id) {
			if(aux->ant)
				aux->ant->prox = aux->prox;
			else 
				lst->head = aux->prox; 
				
			if(aux->prox) 
				aux->prox->ant = aux->ant;
			else 
				lst->tail = aux->ant;
				
			aux->prox = lst->head;
			aux->ant = NULL;
			
			if(lst->head)
				lst->head->ant = NULL; 
				
			lst->head = aux;
			printf("Produto priorizado: ");
			return;
		}
		aux = aux->prox;
	}
	
}
