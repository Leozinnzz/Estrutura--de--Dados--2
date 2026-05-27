#include <stdio.h>
#include <stdlib.h>
#include "Object.h"
#include "List.h"
#include "Item.h"
#include "Player.h"

int main(){
	
	List lst = new(List);
		
	for(int i=0; i<5; i++){
		char name[100];
		sprintf(name,"%s%d","link",i+1);
		//Object p1 = new(Player,ELFO,name,50+rand()%50);
		Object p1 = new(Player, name, HUMANO, 50+rand()%50);
		list_enqueue(lst, p1);
	}
	
	foreach(lst, set_bonus, HUMANO, 50); 
	print_List(lst, print_player);
	
	
}

