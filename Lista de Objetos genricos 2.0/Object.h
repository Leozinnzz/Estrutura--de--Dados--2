#ifndef OBJECT_H
#define OBJECT_H
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
	int id;
	void* item; 
	int type;
	struct Node* right;
	struct Node* left;
	void (*print)(struct Node*);
	void (*destroy)(struct Node*); 
	void (*set)(struct Node*, void*);
}Node; 

typedef Node* Object; 
void set_up(Object obj, void (*f_set)(Object));
void destroy(Object obj);

Object new_Object(){
	Object obj = malloc(sizeof(Node)); 
	obj->print = NULL;
	obj->item = NULL; 
	obj->left = NULL; 
	obj->right = NULL;
	obj->destroy = destroy;
	obj->set = NULL;
	return obj;  	
}

void destroy(Object obj){
	if(!obj) return; 
	if(obj->item)
		free(obj->item); 
	free(obj); 
}

//void set_up(Object obj, void (*f_set)(Object)){
	//if(obj && f_set)
		//f_set(obj);
//}





#endif
