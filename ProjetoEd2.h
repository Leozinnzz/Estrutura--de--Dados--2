#include <stdio.h>
#include <stdlib.h>
#include <string.h> 

typedef enum {KERNEL, USER} type;

typedef struct TypeProcesso{
	int cont; 
	int inst;
	int pid; 
	int tempo; 
	type tipo;
	struct TypeProcesso* ant; 
	struct TypeProcesso* prox; 
}TypeProcesso; 

typedef TypeProcesso* Processo; 

typedef struct TypeList{
	Processo head; 
	Processo tail; 
	Processo Running;
	Processo lastkernel;
	int pid;
	int size; 
}TypeList;

typedef TypeList* List; 

List new_list() {
	List lst = (List) malloc(sizeof(TypeList)); 
	lst->head = NULL; 
	lst->tail = NULL; 
	lst->Running = NULL;
	lst->lastkernel = NULL; 
	lst->pid = 100;
	lst->size = 0;
	return lst;
}

Processo new_kernel(List lst) {
	Processo p = (Processo) malloc(sizeof(TypeProcesso));
	p->pid = lst->pid;
	 
	p->prox = NULL; 
	
	lst->Running = p;
	
	if(!lst->tail) {
		lst->tail = p;
		lst->head = p; 
	}
	p->inst = 1 + rand()%11;
	p->tempo = 0; 
	p->cont = 0;
	p->tipo = KERNEL;
	
	if(lst->lastkernel) {
		Processo lastkernel = lst->lastkernel; 
		p->ant = lastkernel; 
		p->prox = lastkernel->prox;
		lastkernel->prox = p;
		if(!p->prox) lst->tail = p;
	}
	
	lst->lastkernel = p;
		
	lst->pid += 1;
	lst->size++; 
	return p; 
}

Processo new_User(List lst) {
	Processo pu = (Processo) malloc(sizeof(TypeProcesso)); 
	pu->pid = lst->pid;
	pu->prox = NULL; 
	pu->ant = lst->tail; 
	lst->Running = pu;
	
	if(!lst->tail)
		lst->head = pu; 
	else 
		lst->tail->prox = pu;
	lst->tail = pu; 
	
	pu->cont = 0; 
	pu->inst = 1 + rand()%11;
	pu->tempo = 0; 
	pu->tipo = USER;
	lst->pid += 1;
	lst->size++;
	return pu;
}

void show_process(List lst){
	if(!lst->size || !lst->head) return;
	
	Processo aux = lst->head;
	
	while(aux) {
		const char* marcador = (lst->Running == aux) ? "*" : "";
		const char* tipo = (aux->tipo == KERNEL) ? "KERNEL" : "USER";
		
		printf("%s\t\t%s\t\t%d\t%d\t\t%d %d\n", marcador, tipo, aux->pid, aux->inst, aux->cont, aux->tempo);
		aux = aux->prox;
	}
} 

void delete_p(List lst) {
	if(!lst->size || !lst->head) return;
	
	Processo alvo = lst->head;
	Processo atual = lst->Running;
	
	while(alvo){
		if(alvo == atual){
			if(alvo == lst->lastkernel)
				lst->lastkernel = alvo->ant;
				
			if(alvo->prox)
				lst->Running = alvo->prox; 
			else 
				lst->Running = lst->head;
				
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
		alvo = alvo->prox;
	}
}

void moveP(List lst) {
	if(!lst->size ||!lst->head ||!lst->Running) return;
	
	Processo running = lst->Running; 
	
	running->tempo += 1; 
	
	if(running->tempo == running->inst) {
		delete_p(lst);
		return;
	}
	
	if(running->prox)
		lst->Running = running->prox;
	else 
		lst->Running = lst->head;
	
}


