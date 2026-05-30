#ifndef LISTA_H 
#define LISTA_H 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Object.h"

#define new(TYPE,...) new_##TYPE(__VAR_ARGS__)

typedef struct __List {
	Object head; 
	Object tail; 
	int size; 
	void (*append)();
}__List; 

typedef __List* List; 

List new_List(){
	List lst = malloc(sizeof(__List)); 
	lst->head = NULL; 
	lst->tail = NULL; 
	lst->size = 0; 
	return lst;
}

void enqueue(List lst, Object obj){
	if(!lst->size || !lst->head) {
		lst->head = obj; 
		lst->tail = obj; 
	}
	lst->head->right = obj; 
	obj->left = lst->tail;
	lst->tail = obj;
}

void push(List lst, Object obj){
	obj->left = NULL; 
	obj->right = lst->head;
	
	if(lst->head)
		lst->head->left = obj;
	lst->head = obj; 
	
	if(!lst->tail)
		lst->tail = obj;
}

Object pop(List lst){
	if(!lst->size || !lst->head) return NULL; 
	Object aux = lst->head; 
	if(lst->head)
		lst->head->left = NULL;
	else 
		lst->tail = NULL; 
	return aux;
}

void clear(List lst) {
	if(!lst->size || !lst->head) return; 
	Object obj = lst->head; 
	while(obj) {
		Object temp = obj->right; 
		destroy(temp); 
		temp = obj;
	}
	lst->head = NULL; 
	lst->tail = NULL;
	lst->
	size = 0;  
}

 
#endif
