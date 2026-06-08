#include <stdio.h>
#include <stdlib.h>
#include "Lista.h"
#include "Entidade.h"
#include "Item.h"
#include "Object.h"

int main() {
    List lst = new(List); 
   
	Object obj = new(Item);
	set_item(obj, 12, "arma");
	lst->append_enqueue(lst, obj); 
	obj = new(Entity);
	set_Entity(obj, "Leonardo");
	lst->append_push(lst, obj);
	lst->print(lst);	

} 


