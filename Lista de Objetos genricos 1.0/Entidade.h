#ifndef ENTIDADE_H
#define ENTIDADE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Object.h"
#include "Lista.h"

#define new(TYPE,...) new_##TYPE(__VA_ARGS__)

typedef struct __Entidade{
	int id;
	char* name;
	int age;
}__Entidade;

typedef __Entidade* Entidade;

Object new_Entidade(int id, char* name, int age){
	Object obj = new_Object();
	Entidade ent = malloc(sizeof(__Entidade));
	ent->age = age; 
	ent->id = id; 
	ent->name = malloc(strlen(name)+1); 
	strcpy(ent->name, name);
	obj->item = ent; 
	return obj;
}

void print_Entity(Object obj){
	if(!obj) return; 
	
	Entidade ent = (Entidade) obj->item; 
	printf("ID: %d\t\tNome: %s\t\t idade: %d\n", ent->id, ent->name, ent->age);
}
#endif




