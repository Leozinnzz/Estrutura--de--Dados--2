#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Lista_D_encadeada.h"
#include <time.h>

int interface(){
	printf("\n=======================TELA==============================\n");
	printf("0. Finalziar o programa: \n");
	printf("1. Criar Documento: \n");
	printf("2. Fila de impressão: \n");
	printf("3. Imprimir Documento: \n");
	printf("4. Excluir Documento: \n");
	printf("5. Priorizar Documento: \n");
	int opc;
	printf("\nEscolha uma opção: ");
	scanf(" %d", &opc);
	return opc;
}


void set_product(List lst){
	char name[100];
	int pgs, tam, id;
	id = rand()%100;
	printf("Digite o nome do documento: ");
	scanf(" %[^\n]", name);
	printf("Quantidade de paginas: ");
	scanf(" %d", &pgs);
	tam = 100 + rand()%899;
	new_Document(lst, id, name, pgs, tam);
}


int main() {
	
	srand(time(NULL));
	
	List lst = new_List();
	

	do {	
		switch(interface()) {
			case 1:
				set_product(lst);
				printf("Produto cadastrado!");
				break;
			case 2:
				print_lista(lst);
				break;
			case 3:
				impr_doc(lst);
				break;
			case 4: 
				excluir(lst);
				break;
			case 5: 
				
				break;
			case 0:
				return 0;
			default:
				printf("\nDigite uma opção valida\n");
		}
	
	}while(1);
    

}


