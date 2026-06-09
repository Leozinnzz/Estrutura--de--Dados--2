#ifndef ITEM_H
#define ITEM_H
#include <stdio.h>
#include <stdlib.h>
#include "string.h"
#include "Object.h"


typedef struct Context{
	int power;
	char* name;
}Context;


typedef struct __Item {
	int id;
	int power; 
	char* name;
}__Item;

typedef __Item* Item;

void print_Item(Object obj);
	
Object new_Item(){
	Object obj = new_Object();
	if(!obj) return NULL;
	obj->print = print_Item; 
	Item item = malloc(sizeof(__Item)); 
	item->id = -1;
	item->name = NULL; 
	obj->item = item;
	return obj;
}

void print_Item(Object obj){
	if(!obj) return; 
	
	Item it = (Item) obj->item; 
	printf("ID: %d\t\tNome: %s\t\tPower: %d\n", obj->id, it->name, it->power);
}

void set_item(Object obj, int power, char* name){
	if(!obj) return;
	
	Item it = (Item) obj->item;
	it->power = power; 
		
	it->name = malloc(strlen(name)+1); 
	strcpy(it->name, name); 
}


#endif
