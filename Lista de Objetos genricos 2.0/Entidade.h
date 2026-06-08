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

Object new_Entity(){
	Object obj = new_Object(); 
	obj->print = print_Entity;
	Entity ent = malloc(sizeof(__Entity));
	ent->id = -1; 
	obj->item = ent; 
	return obj; 
}

void print_Entity(Object obj) {
	if(!obj) return; 
	
	Entity ent = (Entity) obj->item; 
	printf("ID: %d\t\tNome: %s\t\t\n", obj->id, ent->name); 
}

void set_Entity(Object obj, char* name){
	if(!obj) return;
	
	Entity ent = (Entity) obj->item; 
	
	if(ent->name)
		free(ent->name);
		
	ent->name = malloc(strlen(name)+1);
	strcpy(ent->name, name); 
}

#endif
