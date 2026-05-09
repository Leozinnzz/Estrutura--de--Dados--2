/*
============= Leozinzz =================
============= CachyOS --%d/%m/%Y-- =================
============= LI4ever ======================
============= Made-by-Leozinzz-Desktop ===============
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "Lista_encadeada.h"

int interface(){
	printf("\n=======================TELA==============================\n");
	printf("0. Finalziar o programa: \n");
	printf("1. Criar Documento: \n");
	printf("2. Fila de impressão: \n");
	printf("3. Imprimir Documento:: \n");
	printf("4. Excluir Documento: \n");
	printf("5. Priorizar Documento: \n");
	int opc;
	printf("\nEscolha uma opção: ");
	scanf(" %d", &opc);
	return opc;
}
/*
Void imprimir_documento(List lst) {
	if(!lst->size || !lst->head) {
		printf("A lista esta vazia");
		return;
	}
	
	Document doc = list->head;
	
	printf("================IMPRIMIR===================")
}

*/


void cadastrar_Documento(List lst){
	char name[100];
	int size, id, pgs;
	id = rand()%100;
	printf("\n==================Cadastrar Documento======================\n");
	printf("Digite o nome do documento: ");
	scanf(" %[^\n]", name);
	printf("Digite a quantidade de paginas: ");
	scanf(" %d", &pgs);
	size = 100 + rand()%900;
	new_Document(lst, id, name, pgs, size);
}

void cadast_priori(List lst){
	char name[100];
	int size, id, pgs;
	id = rand()%100;
	printf("\n==================Cadastrar Documento Prioritario======================\n");
	printf("Digite o nome do documento: ");
	scanf(" %[^\n]", name);
	printf("Digite a quantidade de paginas: ");
	scanf("%d", &pgs);
	size = 100 + rand()%900;
	doc_priori(lst, id, name, pgs, size);
}

int main() {
	
	srand(time(NULL));
    
   	List list = new_List();

	do {	
	switch(interface()) {
		case 1:
			cadastrar_Documento(list);
			break;
		case 2:
			print_List(list);
			break;
		case 3:
			imprimir_doc(list);
			break;
		case 4: 
			delete_doc(list);
			break;
		case 5: 
			cadast_priori(list);
			break;
		case 0:
			return 0;
		default:
			printf("\nDigite uma opção valida\n");
		}
	
	}while(1);

    //the destroyer of codes
}


