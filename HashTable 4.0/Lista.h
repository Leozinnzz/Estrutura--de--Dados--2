#ifndef LISTA_H
#define LISTA_H

#include <stdio.h>
#include <stdlib.h>
#include "Object.h"

typedef struct __List{
	Object head;
	Object tail;
	int  size;
}__List;

typedef __List* List; 

List new_List(){
	List lst = malloc(sizeof(__List)); 
	lst->head = NULL; 
	lst->tail = NULL; 
	lst->size = 0; 
	return lst;
}

void push(List lst, Object obj){
	if(lst->head) {
		obj->right = lst->head;
		lst->head->left = obj;
	}
	else  {
		lst->tail = obj;
	}
	lst->head = obj;
	lst->size++;
}

void enqueue(List lst, Object obj) {
	if(!lst->head || !lst->size) {
		lst->head = obj;
		lst->tail = obj;
	}
	else {
		lst->head->right = obj; 
		obj->left = lst->tail;
		lst->tail = obj; 
	}
	lst->size++;
}


Object list_pop(List lst){
	if(!lst->size || !lst->head) return NULL; 
	
	Object obj = lst->head; 
	if(obj->right) 
		obj->right->left = NULL; 
	else 
		lst->tail = NULL; 
	lst->head = obj->right;
	obj->right = NULL;
	obj->left = NULL;
	return obj;
}


void list_clear(List lst) {
	if(!lst->size || !lst->head) return; 
	Object obj = lst->head; 
	while(obj){
		Object temp = obj->right;
		destroy(obj);
		obj = temp;
	}
	lst->head = NULL;
	lst->tail = NULL;
	lst->size = 0;
}

void foreach(List lst, void (*f) (Object, void*), void* contexto){
	if(!lst->size || !lst->head) return; 
	Object obj = lst->head; 
	while(obj){
		f(obj, contexto); 
		obj = obj->right;  
	}
}

#endif
