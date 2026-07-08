#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <string.h>
#include "Lista.h"
#include "Object.h"

typedef struct __Disciplina{
    int id;
    char* name; 
    int horas; 
} __Disciplina;
typedef __Disciplina* Disciplina;

typedef struct __Professor{
    int id;
    char* name;
    int idade;
} __Professor;
typedef __Professor* Professor;


typedef struct __CtxProfessor{
    char* name;
    int idade;
} __CtxProfessor;
typedef __CtxProfessor* CtxProfessor; 

typedef struct __CtxDisciplina{
    char* name;
    int horas;
} __CtxDisciplina;
typedef __CtxDisciplina* CtxDisciplina;


void print_Disciplina(Object obj);
void print_Professor(Object obj);
void destroy_Disciplina(Object obj);
void destroy_Professor(Object obj);
void set_Disciplina(Object obj, void* dados);
void set_Professor(Object obj, void* dados);

CtxDisciplina new_Disciplina(char* name, int horas){
	CtxDisciplina ctx = malloc(sizeof(__CtxDisciplina));
	ctx->horas = horas; 
	ctx->name = malloc(strlen(name)+1);
	strcpy(ctx->name, name);
	return ctx;
}

CtxProfessor new_Professor(char* name, int idade){
	CtxProfessor ctx = malloc(sizeof(__CtxProfessor));
	ctx->idade = idade; 
	ctx->name = malloc(strlen(name)+1);
	strcpy(ctx->name, name);
	return ctx;
}

Object new_ObjDisciplina(){
	Object obj = new_Object(); 
	Disciplina d = malloc(sizeof(__Disciplina));
	obj->item = d; 
	d->horas = 0; 
	d->id = -1; 
	d->name = NULL; 
	
	obj->print = print_Disciplina;
	obj->destroy = destroy_Disciplina; 
	obj->set = set_Disciplina;
	
	return obj;
	
}

Object new_ObjProfessor(){
	Object obj = new_Object(); 
	Professor p = malloc(sizeof(__Professor));
	obj->item = p; 
	p->idade = 0; 
	p->id = -1; 
	p->name = NULL; 
	
	obj->print = print_Professor;
	obj->destroy = destroy_Professor; 
	obj->set = set_Professor;
	
	return obj;
	
}

void print_Disciplina(Object obj){
	if(!obj || !obj->item) return; 
	Disciplina d = (Disciplina)obj->item;
	printf("(ID: %d)   (Nome: %s)   (Horas: %d)\n", obj->id, d->name, d->horas);
}

void print_Professor(Object obj){
	if(!obj || !obj->item) return; 
	Professor p = (Professor)obj->item;
	printf("(ID: %d)   (Nome: %s)   (Idade: %d)\n", obj->id, p->name, p->idade);
}

void destroy_Disciplina(Object obj){
	if(!obj) return; 
	if(obj->item){
		Disciplina d = (Disciplina) obj->item; 
		if(d->name)
			free(d->name);
		free(d);
	}
	free(obj);
}

void destroy_Professor(Object obj){
	if(!obj) return; 
	if(obj->item){
		Professor p = (Professor) obj->item; 
		if(p->name)
			free(p->name);
		free(p);
	}
	free(obj);
}

void set_Disciplina(Object obj, void* dados){
	if(!obj || !obj->item || !dados) return; 
	Disciplina d = (Disciplina) obj->item; 
	CtxDisciplina novos_dados = (CtxDisciplina) dados;
	
	d->horas = novos_dados->horas; 
	if(d->name) free(d->name);
	d->name = malloc(strlen(novos_dados->name)+1);
	strcpy(d->name, novos_dados->name);
	
	free(novos_dados->name);
	free(novos_dados);
}

void set_Professor(Object obj, void* dados){
	if(!obj || !obj->item || !dados) return; 
	Professor p = (Professor) obj->item; 
	CtxProfessor novos_dados = (CtxProfessor) dados;
	
	p->idade = novos_dados->idade; 
	if(p->name) free(p->name);
	p->name = malloc(strlen(novos_dados->name)+1);
	strcpy(p->name, novos_dados->name);
	
	free(novos_dados->name);
	free(novos_dados);
}

void list_clear(List lst){
	if(!lst->size || !lst->head) return; 
	Object obj = lst->head;
	while(obj){
		Object temp = obj->right; 
		obj->destroy(obj); 
		obj = temp; 
	}
	lst->head = NULL; 
	lst->tail = NULL;
	lst->size = 0;
}

void delete_Idx(List lst, int idx){
	if(!lst->size || !lst->head) return; 
	Object obj = lst->head;
	while(obj){
		if(obj->id == idx){
			if(obj->left)
				obj->left->right = obj->right; 
			else 
				lst->head = obj->right; 
			if(obj->right)
				obj->right->left = obj->left;
			else 
				lst->tail = obj->left; 
			obj->destroy(obj);
			printf("Objeto destruido\n");
			lst->size--;
		}
		obj = obj->right;
	}
}

int main() {
	List lst = new(List);
	
	Object p1 = new(ObjProfessor);
	Object p2 = new(ObjDisciplina);
	
	p1->set(p1, new(Professor, "AAA", 12));
	p2->set(p2, new(Disciplina, "Estruturas de dados", 80));
	lst->append_push(lst, p1);
	lst->append_push(lst, p2);
	
	delete_Idx(lst, 1);
	
	lst->print(lst);
	
}
