#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Document.h"

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
	scanf("%d", &opc);
	return opc;
}

int main() {
	List* list = new_list();

	do {
	switch(interface()) {
		case 1:
			new_document(list);
			printf("Produto criado ");
			break;
		case 2:
			fila_imprimir(list);
			break;
		case 3:
			imprimir(list);
			break;
		case 4: 
			excluir_doc(list);
			break;
		case 0:
			return 0;
		default:
			printf("\ncara o que q vc tentou digitar man\n");
		}
	
	}while(1);
	
}


