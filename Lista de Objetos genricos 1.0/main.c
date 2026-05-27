#include <stdio.h>
#include <stdlib.h>
#include "Entidade.h"
#include "Lista.h"
#include "Object.h"


/*int interface(){
	printf("\n====================INTERFACE===================\n"); 
	printf("0 - Encerrar:\n"); 
	printf("1 - Criar entidade:\n"); 
	printf("2 - Imprimir entidades (foreach):\n"); 
	printf("3 - Retirar da lista(list_pop):\n"); 
	printf("4 -	Limpar a lista:\n"); 
	printf("5 - Adicionar na lista(Stack):\n"); 
	printf("6 - Adicionar na lista(Queue):\n");
	int opc; 
	printf("\n Digite uma opção: ");
	if(scanf("%d", &opc) != 1 ) {
		printf("Digite um numero!");
		while(getchar() != '\n');
		return -1;
	}
	while(getchar() != '\n');
	return opc;  
}
*/

/*void get_Entity(List lst){
	int id, age;
	id =  rand()%100; 
	char name[100]; 
	printf("\n===CADASTRO===\n");
	printf("Digite o nome da entidade: ");
	scanf(" %[^\n]", name); 
	printf("Digite a idade da entidade: "); 
	scanf("%d", &age);
	new_Entity(id, name, age);
}
*/

int main() {
	List lst = new(List);

	Object p1 = new(Entidade, 12, "leonardo", 19);
	Object p2 = new(Entidade, 11, "Jose", 18);
	push(lst, p1);
	push(lst, p2);
	Object obj = list_pop(lst);
	printf("\n\n");
	printf("Item retirado da lista\n");
	print_Entity(obj);
	Object p3 = new(Entidade, 4, "Asdruval", 29);
	push(lst, p3);
	list_clear(lst);
	foreach(lst, (void*) print_Entity, NULL);

}


