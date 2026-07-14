#ifndef HTABLE_H 
#define HTABLE_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Object.h"
#include "Lista.h"

#define new(TYPE,...) new_##TYPE(__VA_ARGS__)

typedef struct __HashTable* HashTable;

typedef struct __HashTable{
    List* bucket;
    int size; 
    int capacidade;
    void(*insert)(HashTable ht, Object obj); 
    Object(*search)(HashTable ht, int key); 
    void(*remove)(HashTable ht, int key);
    void(*print)(HashTable ht);
    void(*clear)(HashTable ht);
}__HashTable; 

int hash_function(HashTable htable, int key) {
    return abs(key) % htable->capacidade;
}

void _hash_insert(HashTable ht, Object obj){
    if(!ht || !obj) return; 
    
    int index = hash_function(ht, obj->id);
    
    if(!ht->bucket[index])
        ht->bucket[index] = new_List();
    
    enqueue(ht->bucket[index], obj); 
    ht->size++; 
}

Object _hash_search(HashTable ht, int key) {
    if(!ht) return NULL; 
    
    int index = hash_function(ht, key); 
    List lst = ht->bucket[index]; 
    
    if(!lst) return NULL; 
    
    Object current = lst->head; 
    while(current) {
        if(current->id == key)
            return current; 
        current = current->right; 
    }
    return NULL; 
}

void _hash_remove(HashTable ht, int key) {
    if(!ht) return; 
    
    int index = hash_function(ht, key); 
    List lst = ht->bucket[index];
    if(!lst) return; 
    
    Object alvo = lst->head;
    while(alvo){
        if(alvo->id == key) {
            if(alvo->left)
                alvo->left->right = alvo->right;
            else 
                lst->head = alvo->right; 
            if(alvo->right)
                alvo->right->left = alvo->left; 
            else 
                lst->tail = alvo->left; 
                
            if(alvo->item)
                free(alvo->item);
                
            alvo->destroy(alvo);
            ht->size--;
            lst->size--;
            return;
        }
        alvo = alvo->right;
    }
}

void _hash_print(HashTable ht){
    if(!ht) return; 
    for(int i = 0; i < ht->capacidade; i++) {
        printf("Bucket [%d]: ", i); 
        List lst = ht->bucket[i]; 
        if(!lst || lst->size == 0) {
            printf("Lista vazia\n");
            continue;
        }
        Object current = lst->head; 
        while(current) {
            printf("[%d] -> ", current->id); 
            current = current->right; 
        }
       
    }
}

void _hash_clear(HashTable ht) {
    if(!ht) return; 
    
    for(int i = 0; i < ht->capacidade; i++) {
        if(ht->bucket[i]) {
            Object current = ht->bucket[i]->head;
            while(current) {
                if(current->item){
                    free(current->item);
                    current->item = NULL; 
                }
                current = current->right;
            }
            list_clear(ht->bucket[i]);
        }
    }
    ht->size = 0;
}

HashTable new_HashTable(int capacidade){
    HashTable ht = malloc(sizeof(__HashTable));
    ht->size = 0; 
    ht->capacidade = capacidade;
    ht->bucket = malloc(sizeof(List) * capacidade);
    
    for(int i = 0; i < ht->capacidade; i++) 
        ht->bucket[i] = NULL; 

    ht->insert = _hash_insert;
    ht->search = _hash_search;
    ht->remove = _hash_remove;
    ht->print = _hash_print;
    ht->clear = _hash_clear;

    return ht;
}

#endif
