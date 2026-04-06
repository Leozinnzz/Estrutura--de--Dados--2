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
			Pessoa* p1 = criar_Pessoa("Leonardo", "1234506467", 19, 1.75);
			Pessoa* p2 = criar_Pessoa("Joao", "8594302835", 22, 1.88);
			Pessoa* p3 = criar_Pessoa("Matheus", "125643869", 32, 2.00);
			Pessoa* p4 = criar_Pessoa("Victor", "7658345", 45, 1.74);
			Pessoa* p5 = criar_Pessoa("Maria", "879544325", 52, 1.60);
			Pessoa* p6 = criar_Pessoa("Ana", "76482467", 39, 1.72);
			printf("\nPessoa criada\n");
			break;
		case 2:
			Node* lista = NULL;
			lista = criar_no(lista, p1);
			lista = criar_no(lista, p2);
			lista = criar_no(lista, p3);
			lista = criar_no(lista, p4);
			lista = criar_no(lista, p5);
			lista = criar_no(lista, p6);
			print_pessoa(lista);
			break;
		case 0:
			deletar_pessoa(p1);
			deletar_pessoa(p2);
			deletar_pessoa(p3);
			deletar_pessoa(p4);
			deletar_pessoa(p5);
			deletar_pessoa(p6);
			deletar_lista(lista);
			printf("\nAdeus\n");
			return 0;
		default:
			printf("\ncara o que q vc tentou digitar man\n");
			
		}
	
	}while(1);
	
}


