#include <stdio.h>
#include <stdlib.h>
#include "gconio.h"

typedef enum {Kernel, Usuario}type;

typedef struct TypeProcesso{
	int cont;
	int inst;
	int tempo;
	int PID; 
	type tipo;
	struct TypeProcesso* ant; 
	struct TypeProcesso* prox;
}TypeProcesso;

typedef TypeProcesso* Processo;

typedef struct TypeList{
	Processo head; 
	Processo tail; 
	Processo Running;
	int size;
}TypeList;

typedef TypeList* List;

List new_List(){
	List l = malloc(sizeof(TypeList)); 
	l->head = NULL; 
	l->tail = NULL; 
	l->size = 0; 
	return l; 
}

Processo Kernel_process(List lst){
	Processo new = malloc(sizeof(TypeProcesso));
	new->prox = NULL; 
	new->ant = lst->tail;
	 
	if(!lst->tail) {
		lst->head = new;
		new->PID = 100 + rand()%30;
	}
	else { 
		new->PID = lst->tail->PID+1;
		lst->tail->prox = new;
	}
	
	lst->tail = new; 
	
	new->inst = 1 + rand()%11;
	new->tempo = 1 + rand()%10;
	new->cont = 0;
	new->tipo = Kernel;

	lst->size++;
	return new;
}
Processo User_process(List lst){
	Processo new = malloc(sizeof(TypeProcesso));
	new->prox = NULL; 
	new->ant = lst->tail;
	 
	if(!lst->tail) {
		lst->head = new;
		new->PID = 100 + rand()%30;
	}
	else { 
		new->PID = lst->tail->PID+1;
		lst->tail->prox = new;
	}
	
	lst->tail = new; 
	
	new->inst = 1 + rand()%11;
	new->tempo = 1 + rand()%11;
	new->cont = 0;
	new->tipo = Usuario;

	lst->size++;
	return new;
}


/* void delete_process(List lst, Processo status) {
	if(!lst->size && !lst->head) return; 
	
	Processo p = status;
	if(status->prox)
		status = status->prox;
	else 
		status = lst->head;

	if(p == status) {
		lst->head = status->prox;
		
		if(!lst->head)
			lst->tail = NULL;
		else 
			lst->head->ant = NULL;
	
		free(p);
		lst->size--;
		return; 
	}
	
	Processo target = status; 
	
	if(target == status) {
		if(target->ant)
			target->ant->prox = target->prox; 
		else 
			lst->head = target->prox; 
		if(target->prox)
			target->prox->ant = target->ant;
		else 
			lst->tail = target->ant; 
			
		free(target); 
		lst->size--; 
		return;
	}
	target = target->prox;
}
*/ 

void delete_process(List lst, Processo status) {
	if(!lst->size || !lst->head) return; 
	
	Processo alvo = status;
	
	if(alvo->ant)
		alvo->ant->prox = alvo->prox; 
	else 
		lst->head = alvo->prox;
		
	if(alvo->prox)
		alvo->prox->ant = alvo->ant; 
	else 
		lst->tail = alvo->ant;
		
	free(alvo);
	lst->size--; 
	return;
}

void print_processo(List lst, Processo status) {
	Processo aux = lst->head;
	
	while(aux != NULL) {	
		Processo prox = aux->prox;
		
		char marcador = (aux == status) ? '*' : ' ';
		char* tipo = (aux->tipo == Kernel) ?  "KERNEL" : "USER";
		
		printf("%c\t\t%s\t\t%d\t%d\t\t%d %d\n", marcador, tipo, aux->PID, aux->inst, aux->cont, aux->tempo);
	
		if(aux == status) {
			status->cont++;
		
			if(status->tempo <= status->cont) {
				if(lst->size == 1) {
					delete_process(lst, aux); 
					status = NULL;
				} else {
					if(aux->prox)
						status = aux->prox;
					else 
						status = lst->head;
		
					delete_process(lst, aux);
				}
			}
		}
		aux = prox;
	}
	
}









