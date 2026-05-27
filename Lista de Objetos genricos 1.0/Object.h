#ifndef OBJECT_H
#define OBJECT_H

#include <stdio.h>
#include <stdlib.h>


typedef struct Node{
	void* item; 
	struct Node* left;
	struct Node* right;
}Node;

typedef Node* Object; 

Object new_Object(){
	Object obj = malloc(sizeof(Node));
	obj->item = NULL;
	obj->left = NULL;
	obj->right = NULL;
	return obj;
}
void destroy(Object obj){
	if(!obj) return;
	if(obj->item)
		free(obj->item);
	free(obj);
}

#endif
