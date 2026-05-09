#include <stdio.h>
#include <stdlib.h>
#include "gconio.h"
#include "Escalonador.h"

int main(){
	
	List lst = new_List();
	Processo atual = lst->head; 
	
	do{
		char opcao;
		
		while(!kbhit(&opcao)){
			system("clear");
			printf("Create: (K)ernel Process / (U)ser Process\n");
			printf("Actions: kil(L) Process / (E)xit Aplication\n");
			if(lst->size) 
				printf("%d Process => Running PID: %d\n", lst->size, lst->head->PID);
			else 
				printf("%d Process \n", lst->size); 
				
			printf("\nRUNNING\t\tTYPE\t\tPID\tINSTRUCTIONS\tDONE\n");
			print_processo(lst, atual);
			
			if(atual && atual->prox) 
				atual = atual->prox;
			else 
				atual = lst->head;
		
			system("sleep 1");
		}
		
		if(opcao == 'k' || opcao == 'K' ) {
			Kernel_process(lst);
			atual = lst->tail;
		}
		
		if(opcao == 'u' || opcao == 'U' ) {
			User_process(lst);
			atual = lst->tail;     
		}
		
		if(opcao == 'l' || opcao == 'L' ) {
			delete_process(lst, atual);
		}
	
		
		opcao = ' ';
		
	}while(1);
	
}

