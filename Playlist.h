#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct TypeMusic {
	int id; 
	char* name; 
	char* banda;
	int timeS; 
	int timeM;
	struct TypeMusic* ant; 
	struct TypeMusic* prox; 
}TypeMusic; 

typedef TypeMusic* Music; 

typedef struct TypePlaylist {
	Music tail; 
	Music head; 
	int size; 
	int lastId;  
}TypePlaylist; 

typedef TypePlaylist* Playlist;

Playlist new_playlist(){
	Playlist pl = malloc(sizeof(TypePlaylist)); 
	pl->head = NULL; 
	pl->tail = NULL; 
	pl->lastId = 1 + rand()%99;
	pl->size = 0;
	return pl;
}

Music new_Music(Playlist pls, char* name, char* banda, int timeS, int timeM) {
	Music msc = (Music) malloc(sizeof(TypeMusic)); 
	msc->id = pls->lastId++; 
	msc->ant = pls->tail;
	msc->prox = NULL; 
	
	if(!pls->tail) 
		pls->head = msc; 
	else 
		pls->tail->prox = msc; 
		
	pls->tail = msc; 
	
	msc->name = malloc(strlen(name)+1); 
	strcpy(msc->name, name);
	msc->banda = malloc(strlen(banda)+1); 
	strcpy(msc->banda, banda);
	msc->timeM = timeM; 
	msc->timeS = timeS;
	pls->size++; 
	return msc;
}

void print_music(Music msc) {
	printf("ID: %d\t\t Nome: %s\t\t Banda: %s\t\t Duracao: %d:%02d\n", msc->id, msc->name, msc->banda, msc->timeM, msc->timeS); 	
}

void print_playlist(Playlist pls) {
	if(!pls->size || !pls->head) {
		printf("A Playlist esta vazia\n"); 
		return; 
	}
	
	Music temp = pls->head; 
	
	printf("\n=========================================Musicas========================================\n");
	
	while(temp) {
		print_music(temp);
		temp = temp->prox; 
	}
}

void play_music(Playlist pls) {
	if(!pls->size || !pls->head) {
		printf("A Playlist esta vazia\n"); 
		return; 
	}
	
	Music aux = pls->head; 
	
	while(aux) {
		pls->head = aux->prox;
		printf("\n====================================Playing music=======================================\n");
		print_music(aux); 
		
		free(aux->name); 
		free(aux->banda); 
		free(aux); 
		pls->size--; 
		return;
	}

}

void delete_music(Playlist pls){
	if(!pls->size || !pls->head) {
		printf("A Playlist esta vazia\n"); 
		return; 
	}
		
	Music msc = pls->head; 
	printf("\n=========================================Musicas========================================\n");
	print_playlist(pls);
	
	int id; 
	printf("\nDigte o id da musica para deletar: "); 
	scanf("%d", &id);
	
	while(msc) {
		if(msc->id == id) {
			if(msc->ant)
				msc->ant->prox = msc->prox; 
			else 
				pls->head = msc->prox;
			if(msc->prox)
				msc->prox->ant = msc->ant; 
			else 
				pls->tail = msc->ant; 
			
			free(msc->name); 
			free(msc->banda); 
			free(msc); 
			pls->size--;
			printf("Musica excluida\n"); 
			return;
		}
		msc = msc->prox;
	}
}

void priority_music(Playlist pls){
	if(!pls->size || !pls->head) {
		printf("A Playlist esta vazia\n"); 
		return; 
	}
		
	Music msc = pls->head; 
	printf("\n=========================================Musicas========================================\n");
	print_playlist(pls);
	
	int id; 
	printf("\nDigte o id da musica para deletar: "); 
	scanf("%d", &id);
	
	while(msc) {
		if(msc->id == id) {
			if(msc->ant) 
				msc->ant->prox = msc->prox; 
			else 
				pls->head = msc->prox; 
			if(msc->prox)
				msc->prox->ant = msc->ant; 
			else 
				pls->tail = msc->ant; 
			
			msc->prox = pls->head; 
			msc->ant = NULL; 
			if(pls->head) 
				pls->head->ant = msc; 
				
			pls->head = msc; 
			printf("Musica priorizada para tocar\n");
			return; 
		}
		msc = msc->prox;
	}


}
