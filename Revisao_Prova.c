#include <stdio.h>
#include <stdlib.h>
#include "Revisao_Prova.h"

void next(){
	while(getchar() != '\n'); 
	getchar();
}

int interface() {
	system("clear");
    printf("\n╔══════════════════════════════════════════════════════╗\n");
    printf("║       	     Playlist Musical                  ║\n");      
    printf("╠══════════════════════════════════════════════════════╣\n");
    printf("║  [1]  Adicionar musica                               ║\n");
    printf("║  [2]  Playlist       		                       ║\n");
    printf("║  [3]  Tocar musica                                   ║\n");
    printf("║  [4]  Excluir musica                                 ║\n");
    printf("║  [5]  Priorizar musica                               ║\n");
    printf("║  [0]  Sair                                           ║\n");
    printf("╚══════════════════════════════════════════════════════╝\n");
    int opt;
    printf("Digite uma opção: ");
    if (scanf("%d", &opt) != 1) {
        printf("  [ERRO] Digite um numero valido!\n");
        while (getchar() != '\n');
        return -1;
    }
    while (getchar() != '\n');
    return opt;
}

void get_music(Playlist pl) {
	char name[100];
	int inicio = 1 + rand()%5;
	int fim = rand()%60;
	printf(">>>>>> Digite o nome da musica >>>>>>"); 
	scanf(" %[^\n]", name); 
	new_music(pl, name, inicio, fim);
}


int main() {
	
	Playlist pl = new_playlist(); 
	
	do {
		switch(interface()) {
			case 1: get_music(pl);  break; 
			case 2: print_list(pl); next();  break; 
			case 3:	playMusic(pl); next();break; 
			case 4: remove_music(pl); next(); break; 
			case 5: priority(pl); next(); break; 
			case 0: break; 
		}
		
	}while(1);
}


