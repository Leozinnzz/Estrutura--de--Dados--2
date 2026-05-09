/*
============= Leozinzz =================
============= CachyOS --%d/%m/%Y-- =================
============= LI4ever ======================
============= Made-by-Leozinzz-Desktop ===============
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Produto.h"

int interface(){
	printf("\n========================= MENU =========================\n");
	printf("0 - Encerrar programa\n");
	printf("1 - cadastrar produto\n");
	printf("2 - Listar produtos\n");
	printf("3 - Comprar produto\n");
	printf("4 - Excluir produto\n");
	printf("5 - Priorizar produto\n");
	int opc; 
	printf("\nEscolha uma opcao: "); 
	scanf("%d", &opc);
	return opc;
}

void set_product(List lst) {
	char name[100]; 
	int id, quant; 
	float value; 
	id = 1 + rand()%99;
	printf("Digite o nome do produto: ");
	scanf(" %[^\n]", name); 
	printf("Digite o preco do produto: ");
	scanf("%f", &value); 
	printf("Digite a quantidade: ");
	scanf(" %d", &quant); 
	new_product(lst, id, name, value, quant);
}


int main() {
	
	List lst = new_list();
	
	do{
		switch(interface()){
			case 1: set_product(lst); break;
			case 2: get_list(lst); break;
			case 3: buy_product(lst); break;
			case 4: delete_product(lst); break;
			case 5: priority(lst); break;
			case 0: printf("Programa encerrado"); return 0;
			default: printf("Digite uma op;'ao valida! ");
		}
	}while(1);

 
}


