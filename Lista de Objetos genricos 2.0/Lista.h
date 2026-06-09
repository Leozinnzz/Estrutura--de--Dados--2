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
	int idx;
	void (*append_push)(struct __List*, Object);
	void (*append_enqueue)(struct __List*, Object);
	void (*print)(struct __List*);
	void (*delete)(struct __List*, int);
	Object (*get)(struct __List*, int);
}__List; 

typedef __List* List; 

void enqueue(List lst, Object obj);
void push(List lst, Object obj);
void print_List(List lst);
Object get(List lst, int index);
void delete_idx(List lst, int idx);

List new_List(){
	List lst = malloc(sizeof(__List)); 
	lst->head = NULL; 
	lst->tail = NULL; 
	lst->idx = 0;
	lst->size = 0; 
	lst->append_enqueue = enqueue;
	lst->append_push = push;
	lst->print = print_List;
	lst->get = get;
	lst->delete = delete_idx;
	return lst;
}

void enqueue(List lst, Object obj){
	
	obj->id = lst->idx++;
	
	if(!lst->size || !lst->head) {
		lst->head = obj; 
		lst->tail = obj; 
	} else{
		lst->tail->right = obj;
        obj->left = lst->tail;
        lst->tail = obj;
	}
	lst->size++;
}

void push(List lst, Object obj){
	
	obj->id = lst->idx++;
	
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
	obj->left = NULL; 
	obj->right = NULL; 
	lst->size--;
	return obj; 
}

void clear(List lst) {
	if(!lst->size || !lst->head) return; 
	Object obj = lst->head; 
	while(obj) {
		Object temp = obj->right; 
		obj->destroy(obj); 
		obj = temp;
	}
	lst->head = NULL; 
	lst->tail = NULL;
	lst->size = 0;  
}

void print_List(List lst){
	if(!lst->size || !lst->head) { 
		printf("A lista esta vazia\n");
		return; 
	}
	Object obj = lst->head; 
	while(obj) {
		obj->print(obj); 
		obj = obj->right;
	}
} 

void delete_idx(List lst, int idx){
	if(!lst->size || !lst->head) return; 
	Object obj = lst->head; 
	while(obj) {
		if(obj->id == idx) {
			if(obj->left)
				obj->left->right = obj->right;
			else 
				lst->head = obj->right; 
			if(obj->right)
				obj->right->left = obj->left;
			else 
				lst->tail = obj->left;
			obj->destroy(obj);
			printf("\nObjeto destruido\n");
			
			lst->size--;
			return;
		}
		obj = obj->right;
	}
}

Object get(List lst, int index){
	if(!lst->size || !lst->head) return NULL;
	Object obj = lst->head; 
	while(obj){
		if(obj->id == index)
			return obj; 
		obj = obj->right;
	}
	return NULL;
}



 
#endif
