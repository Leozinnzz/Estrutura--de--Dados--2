#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct TypeMusic {
	int id; 
	char* name; 
	int inicio;
	int fim; 
	struct TypeMusic* ant; 
	struct TypeMusic* prox;  		
}TypeMusic; 

typedef TypeMusic* Music; 

typedef struct TypePlaylist {
	Music head; 
	Music tail; 
	int size; 
	int id;
}TypePlaylist;

typedef TypePlaylist* Playlist; 

Playlist new_playlist(){
	Playlist pl = malloc(sizeof(TypePlaylist)); 
	pl->head = NULL;
	pl->tail = NULL; 
	pl->id = 1 + rand()%999;
	pl->size = 0; 
	return pl;
} 

Music new_music(Playlist pl, char* name, int inicio, int fim){
	Music msc = (Music)malloc(sizeof(TypeMusic));
	msc->id = pl->id++; 
	msc->ant = pl->tail; 
	msc->prox = NULL; 
	
	if(!pl->tail)
		pl->head = msc;
	else 
		pl->tail->prox = msc; 
		
	pl->tail = msc;
	
	msc->inicio = inicio; 
	msc->fim = fim;
	msc->name = malloc(strlen(name)+1);
	strcpy(msc->name, name); 
	pl->size++; 
	return msc;
}


void print_music(Music msc){
	printf("ID da musica: %d\t\tNome da musica: %s\t\tDuração: %d:%02d\n",
	msc->id, msc->name, msc->inicio, msc->fim); 
}

void print_list(Playlist pl){
	if(!pl->size ||!pl->head) {
		printf("The list is empty"); 
		return;
	}
	
	Music msc = pl->head; 
	
	while(msc) {
		print_music(msc);
		msc = msc->prox;  
	}
}

void playMusic(Playlist pl) {
	if(!pl->size ||!pl->head) {
		printf("The list is empty"); 
		return;
	}
	
	Music aux = pl->head; 
	
	while(aux) {
		pl->head = aux->prox; 
		print_music(aux);
		
		free(aux->name);
		free(aux);
		pl->size--;
		return;
	}

}


void remove_music(Playlist pl) {
	if(!pl->size ||!pl->head) {
		printf("The list is empty"); 
		return;
	}
	
	Music msc = pl->head;
	printf("\n==============PLAYLIST==============\n");
	print_list(pl);
	
	int id; 
	printf(">>>>Digite o id da musica >>>>"); 
	if(scanf("%d", &id) != 1) {
		printf("Digite um numero valido!"); 
		while(getchar() != '\n'); 
		return; 
	}
	
	
	while(msc) {
		if(msc->id == id) {
			if(msc->ant) 
				msc->ant->prox = msc->prox; 
			else 
				pl->tail = msc->ant; 
			if(msc->prox)
				msc->prox->ant = msc->ant; 
			else 
				pl->tail = msc->ant; 
				
			free(msc->name); 
			free(msc); 
			pl->size--; 
			printf("Exclusao concluida!"); 
			return;
		}
		msc = msc->prox;
	}
	
}

void priority(Playlist pl) {
	if(!pl->size ||!pl->head) {
		printf("The list is empty"); 
		return;
	}
	
	Music msc = pl->head;
	printf("\n==============PLAYLIST==============\n");
	print_list(pl);
	
	int id; 
	printf(">>>>Digite o id da musica >>>>"); 
	if(scanf("%d", &id) != 1) {
		printf("Digite um numero valido!"); 
		while(getchar() != '\n'); 
		return; 
	}
	
	
	while(msc) {
		if(msc->id == id) {
			if(msc->ant) 
				msc->ant->prox = msc->prox; 
			else 
				pl->tail = msc->ant; 
			if(msc->prox)
				msc->prox->ant = msc->ant; 
			else 
				pl->tail = msc->ant; 
			msc->ant = NULL; 
			msc->prox = pl->head;
			if(!pl->head) 
				pl->tail = msc; 
			else 
				pl->head->ant = NULL; 
			pl->head = msc;
		}
		msc = msc->prox;
	}
	
}



