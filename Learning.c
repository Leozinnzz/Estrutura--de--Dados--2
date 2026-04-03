#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Learning.h"


int interface(){
	printf("\n=======================================MENU=============================================\n");
	printf("Digita 0 para finalziar o programa: \n");
	printf("Digita 1 para cadastrar um produto: \n");
	printf("Digita 2 ai para listar os produtos cadastrados: \n");
	int opc;
	printf("\nMano escolhe alguma coisa ai cara: ");
	scanf("%d", &opc);
	return opc;
}


int main() {
    
	do {
		switch(interface()) {
			case 1:
				Produto* prod1 = criar_produto("Danix", 15, 3.50);
				Produto* prod2 = criar_produto("Maca", 10, 1.00);
				Produto* prod3 = criar_produto("Cafe", 20, 7.00);
				Produto* prod4 = criar_produto("Salgadinho", 25, 2.00);
				Produto* prod5 = criar_produto("Leite", 30, 5.00);
				printf("Produto criado!\n");
				break;
			case 2:
				No* lista = NULL;
				lista = criar_node(lista, prod1);
				lista = criar_node(lista, prod2);
				lista = criar_node(lista, prod3);
				lista = criar_node(lista, prod4);
				lista = criar_node(lista, prod5);
				print_produto(lista);
				break;
			case 0:
				delete_produto(prod1);
				delete_produto(prod2);
				delete_produto(prod3);
				delete_produto(prod4);
				delete_produto(prod5);
				delete_lista(lista);
				printf("Programa encerrado!\n");
				return 0;
			default:
				printf("Digite uma opção valida: ");
		
		}
		
	}while(1);
    
}


