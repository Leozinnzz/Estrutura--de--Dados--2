#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	char* nome; 
	char* cpf;
	int idade;
	float altura;
}Pessoa;

typedef struct Node {
	Pessoa content;
	struct Node* next;
}Node;

//Construtor
Pessoa* criar_Pessoa(char* nome, char* cpf, int idade, float altura){
	Pessoa* p = malloc(sizeof(Pessoa));
	p->nome = (char*) malloc(strlen(nome)+1);
	strcpy(p->nome, nome);
	p->cpf = (char*) malloc(strlen(cpf)+1);
	strcpy(p->cpf, cpf);
	p->idade = idade;
	p->altura = altura;
	return p;
}

//criar nos
Node* criar_no(Node* head, Pessoa* content) {
	Node* n = malloc(sizeof(Node)); 
	n->content = *content;
	n->next = head;
	return n;
}

void print_pessoa(Node* lista){
	while(lista != NULL) {
		printf("\nPessoa 1\n"); 
		printf("Nome: %s\nCPF: %s\nIdade: %d\nAltura: %.2f\n", 
		lista->content.nome, lista->content.cpf, lista->content.idade,
		lista->content.altura);
		lista = lista->next;
	}
}


void deletar_pessoa(Pessoa* p) {
	if(p == NULL) return;
	free(p->nome);
	free(p);
}

void deletar_lista(Node* list) {
	while(list != NULL) {
		Node* prox = list->next;
		free(list);
		list = prox;
	}
}
