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
} Node; 

typedef Node* Object; 

void destroy(Object obj);

static inline Object new_Object(){
    Object obj = malloc(sizeof(Node)); 
    obj->id = -1;
    obj->type = -1;
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
    
    if(obj->destroy && obj->destroy != destroy) {
        obj->destroy(obj);
        return;
    }
    
    if(obj->item)
        free(obj->item); 
    free(obj); 
}

#endif
