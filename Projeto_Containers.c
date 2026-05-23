#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Projeto_Container.h"

int interface() {
    printf("\n╔══════════════════════════════════════════════════════╗\n");
    printf("║        GERENCIADOR DE CONTAINERS E IMAGENS           ║\n");
    printf("╠══════════════════════════════════════════════════════╣\n");
    printf("║  [1]  Baixar imagem                                  ║\n");
    printf("║  [2]  Excluir imagem                                 ║\n");
    printf("║  [3]  Criar container                                ║\n");
    printf("║  [4]  Interromper container                          ║\n");
    printf("║  [5]  Iniciar container                              ║\n");
    printf("║  [6]  Excluir container                              ║\n");
    printf("║  [7]  Listar todas as imagens                        ║\n");
    printf("║  [8]  Listar todos os containers                     ║\n");
    printf("║  [0]  Sair                                           ║\n");
    printf("╚══════════════════════════════════════════════════════╝\n");
    int opt;
    printf("Digite uma opção: ");
    if (scanf("%d", &opt) != 1) {
        printf("  [ERRO] Digite um numero valido!\n");
        while (getchar() != '\n');
        return -1;
    }
    while (getchar() != '\n');
    return opt;
}

void baixar_imagem(ListI lst){
	char nome[100]; 
	printf("Digite o nome da imagem: "); 
	scanf(" %[^\n]", nome);
	new_imagem(lst, nome); 
}

void criar_container(ListC lstC, ListI lstI){
	char nome[100]; 
	int id_img;
	
	if(!lstI->size) {
		printf("Nao ha imagems criadas");
		return;
	}	
	print_all_imagems(lstI);
	printf("Digite o id da imagem: ");
	if(scanf("%d", &id_img) != 1) {
		printf("Digite um id valido! "); 
		
		while(getchar() != '\n');
		
		return;
	} 
	
	if(!existeImg(lstI, id_img)) {
		printf("O id da imagem deve ser valido");
		return;
	} 
	
	printf("Digite o nome do container: "); 
	scanf(" %[^\n]", nome);
	new_container(lstC, nome, id_img); 
}

int main() {
	srand(time(NULL));
	ListI lstI = new_list_imagem();
	ListC lstC = new_list_container();
	
	do{
		switch(interface()){ 
			case 1: baixar_imagem(lstI); break;
			case 2: excluir_imagem(lstI, lstC); break;
			case 3: criar_container(lstC, lstI); break;
			case 4: stop_container(lstC, INTERROMPIDO); break;
			case 5: stop_container(lstC, EXECUTANDO); break;
			case 6: excluir_container(lstC); break;
			case 7: print_all_imagems(lstI); break;
			case 8: print_all_containers(lstC); break;
			default: printf("Digite uma opção correta");
		}
	  
	}while(1);

}


