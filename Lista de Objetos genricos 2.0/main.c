#include <stdio.h>
#include <stdlib.h>
#include "Lista.h"
#include "Entidade.h"
#include "Object.h"


int main() {
    
    List lst = new(List); 
	Object p1 = new(Entity, 12, "Leonardo");
	Object p2 = new(Entity, 8, "Jose");
	lst->append_enqueue(lst, p1); 
	lst->append_enqueue(lst, p2); 
	Object obj = pop(lst); 
	lst->print(lst);
	printf("\nObjeto retirado da lista\n");
	obj->print(obj);
} 


