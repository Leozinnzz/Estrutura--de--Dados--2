#ifndef PRATICE_H
#define PRATICE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Object.h"

#define new(TYPE,...) new_##TYPE(__VA_ARGS__)

typedef struct __List {
	Object head; 
	Object tail; 
	int size; 
}__List;

typedef __List* List; 

List new_List() {
	List lst = (List) malloc(sizeof(__List)); 
	lst->head = NULL; 
	lst->tail = NULL; 
	lst->size = 0; 
	return lst; 
}

void LIST_append(List lst, Object obj) {
	if(!lst->head || !lst->size) {
		lst->head = obj; 
		lst->tail = obj;
	} 
	else {
		lst->tail->right = obj;  
		obj->left = lst->tail;
		lst->tail = obj;
	}
	
	lst->size++; 
}


void foreach(List lst, void f(Object)) {
	if(!lst->size || !lst->head) return; 
	Object obj = lst->head; 
	while(obj) {
		f(obj); 
		obj = obj->right;
	}
}
#endif















