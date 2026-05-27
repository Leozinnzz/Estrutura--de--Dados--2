#include <stdio.h>
#include <stdlib.h>
#include "Entidade.h"
#include "Lista.h"
#include "Object.h"

void cadastrar(List lst){
	int id, age;
	id =  rand()%100; 
	char name[100]; 
	printf("\n===CADASTRO===\n");
	printf("Digite o nome da entidade: ");
	scanf(" %[^\n]", name); 
	printf("Digite a idade da entidade: "); 
	scanf("%d", &age);
	new_entity(id, name, age);
}

int main() {
	List lst = new_list();
	
	for(int i = 0; i < 3; i++) {
		cadastrar(lst);
	
	}
  
}


