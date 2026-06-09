#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <string.h>
#include "Lista.h"
#include "Object.h"

typedef enum {DICIPLINA, PROFESSOR} tipo;

typedef struct __Disciplina{
	int id;
	tipo type;
	char* name; 
	int horas; 
}__Disciplina;

typedef __Disciplina* Disciplina;

typedef struct __Professor{
	int id;
	char* name;
	int idade;
}__Professor;

typedef __Professor* Professor;

void print_Disciplina(Object obj);
void print_Professor(Object obj);
void destroy_Disciplina(Object obj);
void destroy_Professor(Object obj);
void set_Disciplina(Object obj, void* dados);
void set_Professor(Object obj,void* dados);


Object new_Disciplina(){
	Object obj = new_Object();	
	Disciplina d = malloc(sizeof(__Disciplina));
	obj->item = d;
	d->id = -1; 
	d->horas = 0; 
	d->name = NULL;
	
	
	obj->print = print_Disciplina;
	obj->destroy = destroy_Disciplina;
	obj->set = set_Disciplina;
	
	return obj;
}

Object new_Professor(){
	Object obj = new_Object();
	Professor p = malloc(sizeof(__Professor)); 
	obj->item = p; 
	p->id = -1;
	p->idade = 0; 
	p->name = NULL; 
	
	
	obj->print = print_Professor;
	obj->destroy = destroy_Professor;
	obj->set = set_Professor;
	
	return obj; 
}

void print_Disciplina(Object obj){
	if(!obj) return; 
	Disciplina d = (Disciplina) obj->item;
	printf("[ID: %d]\t\t[Name: %s]\t\t[Horas: %d]\n", obj->id, d->name, d->horas);
}

void print_Professor(Object obj){
	if(!obj) return; 
	Professor p = (Professor) obj->item;
	printf("[ID: %d]\t\t[Name: %s]\t\t[Horas: %d]\n", obj->id, p->name, p->idade);
}

void destroy_Disciplina(Object obj){
	if(!obj) return; 
	if(obj->item){
		Disciplina dc = (Disciplina)obj->item;
		free(dc->name);
		free(dc);
	}
	free(obj);
}

void destroy_Professor(Object obj){
	if(!obj) return; 
	if(obj->item){
		Professor pr = (Professor)obj->item;
		free(pr->name);
		free(pr);
	}
	free(obj);
	
}

void set_Disciplina(Object obj, void* dados){
	if(!obj) return; 
	Disciplina dc = (Disciplina) obj->item;
	Disciplina novos_dados = (Disciplina) dados; 
	dc->horas = novos_dados->horas;
	
	free(dc->name);
	dc->name = malloc(strlen(novos_dados->name)+1); 
	strcpy(dc->name, novos_dados->name);
}

void set_Professor(Object obj, void* dados){
	if(!obj) return; 
	Professor pr = (Professor) obj->item; 
	Professor novos_dados = (Professor) dados;
	pr->idade = novos_dados->idade;
		
	free(pr->name);
	pr->name = malloc(strlen(novos_dados->name)+1); 
	strcpy(pr->name, novos_dados->name);
	
}


int main() {
    List lst = new(List); 
    Object obj = new(Professor);
    obj->set(obj, new(Professor, "Adriano", 42));
   
   
} 


