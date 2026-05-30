#ifndef ENTIDADE_H
#define ENTIDADE_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Object.h"

typedef struct __Entity {
	int id; 
	char* name; 
}__Entity; 

typedef __Entity* Entity;

void print_Entity(Object obj);

Object new_Entity(int id, char* name){
	Object obj = new_Object(); 
	obj->print = print_Entity;
	Entity ent = malloc(sizeof(__Entity));
	ent->id = id; 
	ent->name = malloc(sizeof(name)+1); 
	strcpy(ent->name, name); 
	obj->item = ent; 
	return obj; 
}


void print_Entity(Object obj) {
	if(!obj) return; 
	
	Entity ent = (Entity) obj->item; 
	printf("ID: %d\t\tNome: %s\t\t", ent->id, ent->name); 
}

#endif
