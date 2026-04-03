#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Document.h"

int interface(){
	printf("\n=======================TELA==============================\n");
	printf("Digita 0 para finalziar o programa: \n");
	printf("Digita 1 para criar a entidade: \n");
	printf("Digita 2 ai para listar as entidades criadas: \n");
	int opc;
	printf("\nMano escolhe alguma coisa ai cara: ");
	scanf("%d", &opc);
	return opc;
}

int main() {
	

	do {
	
	switch(interface()) {
		case 1:
			Pessoa* p1= new_Pessoa("Joao", 18, 1.60);
			Pessoa* p2 = new_Pessoa("Leo", 20, 1.67);
			Pessoa* p3 = new_Pessoa("Otavio", 18, 1.90);
			printf("\nPessoa criada\n");
			break;
		case 2:
			Node* lista = NULL;
			lista = new_node(lista, p1);
			lista = new_node(lista, p2);
			lista = new_node(lista, p3);
			print_pessoa(lista);
			break;
		case 0:
			delete_pessoa(p1);
			delete_pessoa(p2);
			delete_pessoa(p3);
			delete_lista(lista);
			printf("\nAdeus\n");
			return 0;
		default:
			printf("\ncara o que q vc tentou digitar man\n");
			
		}
	
	}while(1);
	
}


