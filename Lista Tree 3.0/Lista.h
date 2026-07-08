#ifndef LISTA_H 
#define LISTA_H 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Object.h"


#define new(TYPE,...) new_##TYPE(__VA_ARGS__)

typedef struct __BSTree {
	Object root;
	int size; 
	
	void (*insert) (Object, void*, int);
	void (*search) (Object, int);
}__BSTree; 

typedef __BSTree* BSTree; 

BSTree new_BSTree(){
	BSTree abb = malloc(sizeof(__BSTree)); 
	abb->root = NULL; 
	abb->size = 0; 
	return abb;
}
 

Object insert(Object node, void* item, int key){
	if(!node) {
		Object novo = new_Object(); 
		
		novo->key = key; 
        novo->item = item;
		return novo;
	}
	
	if(key < node->key)
    node->left = insert(node->left, item,  key);

	else if(key > node->key)
		node->right = insert(node->right, item, key);

	return node; 
}

Object search(Object node, int key) {
	Object current = node; 
	
	while(current) {
		if(key == current->key)
			return current; 
		if(key < current->key)
			current = current->left;
		else 
			current = current->right;
	}
	return NULL;
}

//proximas funcoes
void remove(Object node, int key) {

}

//clear(BSTRee) 
//preorder(BSTRee)
//inorder(BSTRee)
//postorder(BSTRee)



#endif
