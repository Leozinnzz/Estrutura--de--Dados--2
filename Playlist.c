#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Playlist.h"

int interface(){
	printf("\n========================================Playlist========================================\n");
	//interromper e iniciar musica
	//iniciar musica
	printf("0 - Sair\n"); 
	printf("1 - Adicionar musica\n"); 
	printf("2 - Listar musica\n"); 
	printf("3 - Tocar musica\n"); 
	printf("4 - Remover musica\n"); 
	printf("5 - Priorizar musica\n"); 
	int opc; 
	printf("\nDigite uma opcao: "); 
	if(scanf("%d", &opc) != 1){
		printf("Entrada invalida! ");

		while(getchar() != '\n');

		return -1;
	}
	return opc;
}

void setMusic(Playlist pls){
	char name[100];
	char banda[100];
	int timeM = 1+rand()%5;
	int timeS = rand()%60;
	printf("Digite o nome da musica: ");
	scanf(" %[^\n]", name);
	printf("Digite o nome da banda: ");
	scanf(" %[^\n]", banda);
	new_Music(pls, name, banda, timeS, timeM);
}

int main() {
	srand(time(NULL));
    Playlist pls = new_playlist();
    
    do {
		switch(interface()) {
			case 1: setMusic(pls); break;
			case 2: print_playlist(pls); break;
			case 3: play_music(pls); break;
			case 4: delete_music(pls); break;
			case 5: priority_music(pls); break;
			case 0: printf("Programa encerrado"); return 0;
			default: printf("Digite uma opcao valida\n");
			
		}
	}while(1);
    
}


