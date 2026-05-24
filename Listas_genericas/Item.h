#ifndef ITEM_H
#define ITEM_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Object.h"


typedef struct __Item{
	char name[100]; 
	int power; 
}__Item;

typedef __Item* Item; 


Object new_Item(char* name, int power){
	Object obj = new_Object(); 
	Item i = (Item)malloc(sizeof(__Item));
	obj->tipo = ITEM;
	obj->item = i;
	strcpy(i->name, name); 
	i->power = power; 
	return obj; 
}

#endif
