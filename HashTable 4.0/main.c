#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "htable.h"
#include "Object.h"

int main() {
    HashTable ht = new(HashTable, 10);

    Object obj1 = new(Object);
    obj1->id = 23;

    Object obj2 = new(Object);
    obj2->id = 45;

    Object obj3 = new(Object);
    obj3->id = 13; 
    
    Object obj4 = new(Object);
    obj4->id = 90; 
    
    Object obj5 = new(Object);
    obj5->id = 85; 

 

    
    printf("====== Tabela Hash Inicial ======\n");
    ht->print(ht);
    
    printf("\n====== Inserindo elementos ======\n");
    ht->insert(ht, obj1);
    ht->insert(ht, obj2);
    ht->insert(ht, obj3);
    ht->insert(ht, obj4);
    ht->insert(ht, obj5);

   
    printf("\n======Buscando ID 45  ======\n");
    Object encontrado = ht->search(ht, 45);
    if (encontrado) {
        printf("Objeto com ID %d encontrado.\n", encontrado->id);
    }


    printf("\n====== Removendo ID 23 ======\n");
    ht->remove(ht, 23);
    ht->print(ht);

  
    printf("\n====== Limpando a Tabela  ======\n");
    ht->clear(ht);
    ht->print(ht);


    free(ht->bucket);
    free(ht);

    return 0;
}


