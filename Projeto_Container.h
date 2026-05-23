#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum {INTERROMPIDO, EXECUTANDO} type;


//Containers
typedef struct TypeContainer{
	int id;
	char* nome;
	type status; 
	int idImg;
	struct TypeContainer* ant; 
	struct TypeContainer* prox;
}TypeContainer;

typedef TypeContainer* Container;

typedef struct listContainers {
	Container head; 
	Container tail; 
	int lastId;
	int size;
}listContainers;

typedef listContainers* ListC;

//Imagems;
typedef struct TypeImagem{
	int id;
	char* nome;
	struct listContainers* containers;
	struct TypeImagem* ant;
	TypeImagem* prox;
}TypeImagem;

typedef TypeImagem* Imagem;

typedef struct listImagems{
	Imagem head; 
	Imagem tail;
	int lastId;
	int size;
}listImagems;

typedef listImagems* ListI;

ListC new_list_container(){
	ListC lc = (ListC) malloc(sizeof(listContainers));
	lc->head = NULL; 
	lc->tail = NULL; 
	lc->lastId = 1000 + rand()%8999;
	lc->size = 0; 
	return lc;
}

ListI new_list_imagem(){
	ListI li = (ListI) malloc(sizeof(listImagems));
	li->head = NULL; 
	li->tail = NULL; 
	li->lastId = 1000 + rand()%8999;
	li->size = 0; 
	return li;
}

Container new_container(ListC lst, char* name, int idImg){
	Container ct = (Container) malloc(sizeof(TypeContainer)); 
	ct->id = lst->lastId++; 
	ct->ant = lst->tail; 
	ct->prox = NULL;
	
	if(!lst->tail)
		lst->head = ct;
	else 
		lst->tail->prox = ct; 
	lst->tail = ct;

	ct->idImg = idImg;
	ct->nome = (char*) malloc(strlen(name)+1);
	strcpy(ct->nome, name);
	ct->status = EXECUTANDO;
	lst->size++;
	return ct; 
}

Imagem new_imagem(ListI lst, char* name){
	Imagem img = (Imagem) malloc(sizeof(TypeImagem)); 
	img->id = lst->lastId++; 
	img->ant = lst->tail;
	img->prox = NULL;
	img->containers = new_list_container();
	
	if(!lst->tail) 
		lst->head = img; 
	else 
		lst->tail->prox = img;
	lst->tail = img;
	
	img->nome = (char*) malloc(strlen(name)+1); 
	strcpy(img->nome, name);
	lst->size++; 
	return img; 
}

void print_container(Container ct){
	printf("\n=========================================CONTAINERS=====================================\n");
	printf("Chave: %d\t\tNome: %s\t\tStatus: %s\n", ct->id, ct->nome, 
	ct->status == INTERROMPIDO ? "INTERROMPIDO" : "EXECUTANDO");
}

void print_imagem(Imagem img){
	printf("\n=========================================IMAGEMS=======================================\n");
	printf("Chave: %d\t\tNome: %s\t\t\n", img->id, img->nome);
}

void print_all_imagems(ListI lst){
	if(!lst->size || !lst->head) {
		printf("The list is empty\n");
		return; 
	}
	
	Imagem img = lst->head; 
	
	while(img) {
		print_imagem(img); 
		img = img->prox;
	}
}

void print_all_containers(ListC lst) {
	if(!lst->size || !lst->head) {
		printf("The list is empty\n");
		return; 
	}
	
	Container temp = lst->head; 
	
	while(temp) {
		print_container(temp); 
		temp = temp->prox;
	}
}

void stop_container(ListC lst, type status){
	if(!lst->size || !lst->head) {
		printf("The list is empty\n");
		return; 
	}
	
	Container ct = lst->head; 
	print_all_containers(lst);
	
	int id; 
	printf("\nDigite o id do container: ");
	if(scanf("%d", &id) != 1) {
		printf("Digite um id valido!");
		while(getchar() != '\n');
	}
	while(getchar() != '\n');
	
	while(ct){
		if(ct->id == id) {
			ct->status = status;
			printf(ct->status == INTERROMPIDO ? "Processo Interrompido" : "Processo Iniciado");
			return;
		}
		ct = ct->prox;
	}
	printf("Esse id que vc tentou digitar nao existe");
	
}

int existeContainer(ListC lst, int idImg) {
	if(!lst->size || !lst->head) return 0; 
	
	Container aux = lst->head; 
	
	while(aux) {
		if(aux->idImg == idImg) 
			return 1;
		aux = aux->prox;
	}
	return 0;
}

int existeImg(ListI lstI, int id_img){
	if(!lstI->size || !lstI->head) return 0; 
	
	Imagem img = lstI->head; 
	
	while(img){
		if(img->id == id_img) 
			return 1; 
		img = img->prox;
	}
	return 0;
}
void excluir_imagem(ListI lst, ListC lstC){
	if(!lst->size || !lst->head) {
		printf("The list is empty\n");
		return; 
	}
	
	Imagem img = lst->head; 
	
	print_all_imagems(lst);
	
	int id; 
	printf("\nDigite o id da imagem: ");
	if(scanf("%d", &id) != 1) {
    printf("Digite um id valido!\n");
    while(getchar() != '\n'); 
    return;
}
	while(getchar() != '\n');
	
	while(img){
		if(img->id == id) {
			if(existeContainer(lstC, img->id)) {
				printf("Ja existe um container relacionado a imagem");
				return;
			}
			if(img->ant)
				img->ant->prox = img->prox;
			else 
				lst->head = img->prox;
			if(img->prox)
				img->prox->ant = img->ant; 
			else 
				lst->tail = img->ant;
			free(img->nome);
			free(img);
			lst->size--;
			printf("Imagem excluida\n");
			return;
			}
		img = img->prox;
	}
	printf("Esse id que vc tentou digitar nao existe");
}

void excluir_container(ListC lst) {
	if(!lst->size || !lst->head) {
		printf("The list is empty\n");
		return; 
	}
	
	print_all_containers(lst);
	int id; 
	
	printf("\nDigite o id do container para excluir: ");
	scanf("%d", &id); 
	
	Container ct = lst->head; 
	
	while(ct) {
		if(ct->id == id){
			if(ct->status == EXECUTANDO) {
				printf("Voce nao pode excluir um container enquanto ele estiver em execução!");
				return;
			}
			if(ct->ant)
				ct->ant->prox = ct->prox;
			else 
				lst->head = ct->prox;
			if(ct->prox)
				ct->prox->ant = ct->ant; 
			else 
				lst->tail = ct->ant;
			free(ct->nome);
			free(ct); 
			lst->size--;
			printf("container excluido");
			return;
		}
		ct = ct->prox;
	}
	printf("Esse id que vc tentou digitar nao existe");
}






