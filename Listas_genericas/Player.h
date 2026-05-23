#ifndef PLAYER_H
#define PLAYER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Object.h"

typedef enum{HUMANO, ELFO, OGRO, ANAO, GNOMO}  raca; 

typedef struct __Player{
	char name[100]; 
	int hp; 
}__Player;

typedef __Player* Player;
 
Object new_Player(char* name, int hp) {
	Object obj = new_Object();
	Player pl = malloc(sizeof(__Player));
	obj->tipo = PLAYER;
	obj->item = pl;
	strcpy(pl->name, name);
	pl->hp = hp;
	return obj;
}


void print_player(Object obj) {
	if(obj->tipo != PLAYER) return; 
	
	Player pl = (Player) obj->item;
	printf("Nome: %s\t\tVida: %d\t\t\n", pl->name, pl->hp);
	
}
#endif

