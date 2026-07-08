#ifndef OBJECT_H
#define OBJECT_H
#include <stdio.h>
#include <stdlib.h>


typedef struct Node {
	int key;
    void* item; 
    struct Node* right;
    struct Node* left;
} Node; 

typedef Node* Object; 

Object new_Object(){
	Object obj = malloc(sizeof(Node));

    obj->key = 0;
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
