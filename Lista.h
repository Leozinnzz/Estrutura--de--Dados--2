#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Lista_encadeada.h"

typedef struct TypeList {
	TypeDocument* head;
	TypeDocument* tail; 
}TypeList;

typedef TypeList* List;

List new_list(){
	List list = (List) malloc(sizeof(List));
	list->head = NULL;
	list->tail = NULL;
	return list;
}
