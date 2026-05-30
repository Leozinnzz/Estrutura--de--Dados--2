#ifndef ITEM_H
#define ITEM_H
#include <stdio.h>
#include <stdlib.h>
#include "Object.h"


typedef struct __Item {
	int id;
	int power; 
	char* name;
}__Item;

typedef __Item* Item;


void print_Item(Object obj);
	
Object new_Item();

void print_Item(Object obj){
	if(!obj) return; 
	
	Item it = (Item) obj->item; 
	printf("ID: %d\t\tNome: %s\t\tPower: %d\n", it->id, it->name, it->power);
}


#endif
