#ifndef LISTA_H 
#define LISTA_H 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Object.h"

#define new(TYPE,...) new_##TYPE(__VA_ARGS__)


typedef struct __List {
	Object head; 
	Object tail; 
	int size; 
	void (*append_push)(struct __List*, Object);
	void (*append_enqueue)(struct __List*, Object);
	void (*print)(struct __List*);
}__List; 

typedef struct Context{
	
}Context;

typedef __List* List; 

void enqueue(List lst, Object obj);
void push(List lst, Object obj);
void print_List(List lst);

List new_List(){
	List lst = malloc(sizeof(__List)); 
	lst->head = NULL; 
	lst->tail = NULL; 
	lst->size = 0; 
	lst->append_enqueue = enqueue;
	lst->append_push = push;
	lst->print = print_List;
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
	lst->size++;
}

void push(List lst, Object obj){
	 if(lst->head) {
		 obj->right = lst->head; 
		 lst->head->left = obj; 
	 }
	 else {
		 lst->tail = obj;
	 }
	 lst->head = obj; 
	 lst->size++;
}

Object pop(List lst){
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
	lst->size = 0;  
}

void print_List(List lst){
	if(!lst->size || !lst->head) return; 
	Object obj = lst->head; 
	while(obj) {
		obj->print(obj); 
		obj = obj->right;
	}
} 




 
#endif
