//Made by Flavix and Leozinzz
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	char nome[100];
	char tipo;
}Processo;

typedef struct{
	Processo processos[100];
	int cont;
}Ds;

Ds iniciarDs(){
	Ds temp;
	temp.cont = 0;
	return temp;
}

void alert(){
	printf("Tipo inválido. Prenssione ENTER...");
	while(getchar() != '\n');
	getchar();
}

int interface() {
	printf("1 - Adicionar Processo: \n");
	printf("2 - Listar\n");
	printf("3 - Desligar \n");
	int opc; 
	printf("\nDigite uma opção: ");
	scanf("%d", &opc);
	
	return opc;
	
}

void addProcesso(Ds* usuario, Ds* kernel) {
	printf("Nome: ");
	char nome[100];
	scanf(" %[^\n]s", nome);
	
	char tipo;
	do{
		printf("Tipo: ");
		scanf(" %c", &tipo);
		if(tipo != 'u' && tipo != 'k'){
			alert();
			continue;
		}
		break;
	}while(1);
	

	if(tipo == 'u'){
			strcpy(usuario->processos[usuario->cont].nome, nome);
			usuario->processos[usuario->cont].tipo = tipo;
			usuario->cont++;
	}else if(tipo == 'k'){
			strcpy(kernel->processos[kernel->cont].nome, nome);
			kernel->processos[kernel->cont].tipo = tipo;
			kernel->cont++;
	}
	system("clear");
} 


void listarPro(Ds memoria) {
	for(int i = 0; i < memoria.cont; i++){
		printf("Nome: %s | Tipo: %s\n", memoria.processos[i].nome, memoria.processos[i].tipo == 'u' ? "Usuário" : "Kernel");
	}
}


int main() {
	Ds usuario = iniciarDs();
	Ds kernel = iniciarDs();
	
	do {
		switch(interface()){
			case 1:
				addProcesso(&usuario, &kernel);
				break;
			case 2:
				listarPro(usuario);
				printf("--------------------------- \n");
				listarPro(kernel);
				printf("\n");
				printf("Total de processos: %d\n\n", usuario.cont+kernel.cont);
				break;
			case 3:
				printf("Programa encerrado\n");
				return 0;
			default:
				printf("Digita uma opção valida ai po\n");
		}
	}while(1);
}


