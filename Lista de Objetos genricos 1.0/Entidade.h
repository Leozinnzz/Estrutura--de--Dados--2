#ifndef ENTIDADE_H
#define ENTIDADE_H

#include <stdio.h>
#include <stdlib.h>
#include "Object.h"
#include "Lista.h"


#define new(TYPE,...) new_##TYPE(__VA_ARGS__)

typedef struct __Entidade{
	int id;
	char* name;
	int idade;
}__Entidade;

typedef __Entidade* Entidade;

Entidade new_entity(List ){
	
}



#endif




