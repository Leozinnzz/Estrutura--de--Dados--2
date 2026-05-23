#ifndef OBJECT_H
#define OBJECT_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum {ITEM, PLAYER} type; 

typedef struct __Object {
	void* item;
	type tipo;
	struct __Object* left; 
	struct __Object* right; 
}__Object;

typedef __Object* Object;

Object new_Object(){	
	Object obj = (Object) malloc(sizeof(__Object)); 
	obj->left = NULL; 
	obj->right = NULL; 
	return obj;	
}
#endif





