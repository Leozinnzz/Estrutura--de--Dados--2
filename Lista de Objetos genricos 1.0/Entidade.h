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

Object new_entity(int id, char* name, int age){
	Object obj = new_object();
	Entidade ent = malloc(sizeof(__Entidade));
	obj->item = ent; 
	ent->age = age; 
	ent->id = id; 
	ent->name = malloc(strlen(name)+1); 
	return obj;
}

Entidade print_Entity(Object obj){
	if(!obj) return NULL; 
	Entidade ent = (Entidade) obj->item; 
	printf("ID: %d\t\tNome: %s\t\t idade: %d\n", ent->id, ent->name, ent->age);
	return ent;
}
#endif




