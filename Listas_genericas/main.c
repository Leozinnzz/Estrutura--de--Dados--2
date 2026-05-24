#include <stdio.h>
#include <stdlib.h>
#include "Object.h"
#include "Lista.h"
#include "Item.h"
#include "Player.h"


int main(){
	List lst = new(List);
		
	for(int i=0; i<5; i++){
		char name[100];
		sprintf(name,"%s%d","link",i+1);
		//Object p1 = new(Player,ELFO,name,50+rand()%50);
		Object p1 = new(Player, name, ELFO, 50);
		list_enqueue(lst, p1);
	}
	foreach(lst,set_bonus,ELFO,100);
	print_List(lst, print_player);
	
	
	//resolvam o seguinte problema...
	//aplicar um bonus de HP (+50) para todo player com type==HUMANO
	//usar a função foreach para isso
	//pesquisar sobre contextos como parâmetros de função 

	//p.ex..
	//foreach(lst,set_Bonus,HUMANO,50);
}

