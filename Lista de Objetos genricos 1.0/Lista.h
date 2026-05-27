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

List new_list(){
	List lst = malloc(sizeof(__List)); 
	lst->head = NULL; 
	lst->tail = NULL; 
	lst->size = 0; 
	return lst;
}

void push(List lst, Object obj){
	if(lst->head)
		lst->head->left = obj;
	else 
		lst->tail = obj;
	lst->head = obj;
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

#endif
