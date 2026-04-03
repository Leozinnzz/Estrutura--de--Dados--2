#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	char* nome;
	int quantidade;
	float preco;
}Produto;

//criar a Linked list
typedef struct No{
	Produto conteudo;
	struct No* proximo;
}No;

//Inserir a linked list
No* criar_node(No* head, Produto* p){
	No* n = (No*) malloc(sizeof(No));
	n->conteudo = *p;
	n->proximo = head;
	return n;
}

//criacao do produto
Produto* criar_produto(char* nome, int quant, float preco) {
	Produto* p = malloc(sizeof(Produto));
	p->nome = (char*) malloc(strlen(nome)+1); 
	strcpy(p->nome, nome); 
	p->quantidade = quant;
	p->preco = preco;
	return p;
}

//mostrar na tela
void print_produto(No* lista){
	while(lista != NULL) {
		printf("\nNome do produto: %s\n", lista->conteudo.nome);
        printf("Quantidade disponivel: %d\n", lista->conteudo.quantidade);
        printf("Preco do produto: %.2f\n", lista->conteudo.preco);
        lista = lista->proximo;
	}
}

//apagar o produto
void delete_produto(Produto* p){
	while(p != NULL) {
		free(p->nome);
		free(p);
	}
}

//apagar a lista
void delete_lista(No* lista){
	while(lista != NULL) {
		No* proximo = lista->proximo;
		free(lista);
		lista = proximo;
	}
}

