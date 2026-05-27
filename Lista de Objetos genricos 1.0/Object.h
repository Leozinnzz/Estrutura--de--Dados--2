#ifndef OBJECT_H_H
#define OBJECT_H

#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
	void* item; 
	struct Node* left;
	struct Node* right;
}Node;

typedef Node* Object; 

Object new_object(){
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

Object list_pop(List lst, Object obj){
	if(!lst->size || !lst->head) return; 
	Object obj = lst->head; 
	Object copia = obj;
	while(obj) {
		lst->head = obj->right
		if(obj->item)
			free(obj->item); 
		free(obj);
		return copia;
	}
}



#endif
