#include <stdio.h>
#include <stdlib.h>
#include "gconio.h"
#include "ProjetoEd2.h"

int main(){
	
	List lst = new_list();
	
	do{
		char opcao;
		while(!kbhit(&opcao)){
			system("clear");
			printf("Create: (K)ernel Process / (U)ser Process\n");
			printf("Actions: kil(L) Process / (E)xit Aplication\n");
			if(lst->size)
				printf("%d Process => Running PID: %d\n", lst->size, lst->head->pid);
			else 
				printf("%d Process \n", lst->size);
			printf("\nRUNNING\t\tTYPE\t\tPID\tINSTRUCTIONS\tDONE\n");
			show_process(lst);
			moveP(lst);
		
			system("sleep 1");
		}
		
		if(opcao == 'k' || opcao == 'K' ) {
			new_kernel(lst);
		}
		
		if(opcao == 'u' || opcao == 'U' ) {
		    new_User(lst);
		}
		
		if(opcao == 'l' || opcao == 'L' ) {
			delete_p(lst);
		}
	
		
	}while(1);
	
}

