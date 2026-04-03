#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char* nome;
    int idade; 
    float altura;
}Pessoa;

//builder
Pessoa* new_Pessoa(char* nome, int idade, float altura) {
    Pessoa* p = (Pessoa*) malloc(sizeof(Pessoa)); 
    p->nome = (char*) malloc((strlen(nome) + 1 ));
    strcpy(p->nome, nome);
    p->idade = idade;
    p->altura = altura;
    return p;
}
//criacao da lista
typedef struct Node {
	Pessoa conteudo;
	struct Node *next;
}Node;

//inserir na lista
Node* new_node(Node* head, Pessoa* p){
    Node* n = malloc(sizeof(Node)); 
    n->conteudo = *p; 
    n->next = head;
    return n;
}
void print_pessoa(Node* lista){
    while(lista != NULL){
        printf("\nNome: %s\n", lista->conteudo.nome);
        printf("Idade: %d\n", lista->conteudo.idade);
        printf("Altura: %.2f\n", lista->conteudo.altura);
        lista = lista->next;
    }

}
void delete_pessoa(Pessoa* p){
    if(p != NULL) {
        free(p->nome);
        free(p);
    }
}

void delete_lista(Node* lista) {
	while(lista != NULL) {
		Node* proximo = lista->next;
		free(lista);
		lista = proximo;	
	}	
}
