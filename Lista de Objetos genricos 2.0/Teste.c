#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Lista.h"
#include "Object.h"

// --- Suas structs reais de dados (Armazenadas na lista) ---
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

// --- As structs auxiliares de Contexto (Transporte dos dados) ---
typedef struct __CtxProfessor{
    char* name;
    int idade;
} __CtxProfessor;
typedef __CtxProfessor* CxtProfessor; 

typedef struct __CtxDisciplina{
    char* name;
    int horas;
} __CtxDisciplina;
typedef __CtxDisciplina* CxtDisciplina;


// --- Protótipos das funções ---
void print_Disciplina(Object obj);
void print_Professor(Object obj);
void destroy_Disciplina(Object obj);
void destroy_Professor(Object obj);
void set_Disciplina(Object obj, void* dados);
void set_Professor(Object obj, void* dados);


// --- Construtores de Dados p/ usar dentro do ->set ---
CxtProfessor new_Professor(char* name, int idade) {
    CxtProfessor ctx = malloc(sizeof(__CtxProfessor));
    ctx->idade = idade;
    ctx->name = malloc(strlen(name) + 1);
    strcpy(ctx->name, name);
    return ctx;
}

CxtDisciplina new_Disciplina(char* name, int horas) {
    CxtDisciplina ctx = malloc(sizeof(__CtxDisciplina));
    ctx->horas = horas;
    ctx->name = malloc(strlen(name) + 1);
    strcpy(ctx->name, name);
    return ctx;
}


// --- Construtores dos Objetos/Nós da lista ---
Object new_ObjDisciplina(){
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

Object new_ObjProfessor(){
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


// --- Funções de Print ---
void print_Disciplina(Object obj){
    if(!obj || !obj->item) return; 
    Disciplina d = (Disciplina) obj->item;
    printf("[ID: %d]\t\t[Name: %s]\t\t[Horas: %d]\n", obj->id, d->name, d->horas);
}

void print_Professor(Object obj){
    if(!obj || !obj->item) return; 
    Professor p = (Professor) obj->item;
    printf("[ID: %d]\t\t[Name: %s]\t\t[Idade: %d]\n", obj->id, p->name, p->idade);
}


// --- Funções de Destruição ---
void destroy_Disciplina(Object obj){
    if(!obj) return; 
    if(obj->item){
        Disciplina dc = (Disciplina)obj->item;
        if(dc->name) free(dc->name);
        free(dc);
    }
    free(obj);
}

void destroy_Professor(Object obj){
    if(!obj) return; 
    if(obj->item){
        Professor pr = (Professor)obj->item;
        if(pr->name) free(pr->name);
        free(pr);
    }
    free(obj);
}

// --- Funções Set ---
void set_Disciplina(Object obj, void* dados){
    if(!obj || !obj->item || !dados) return; 
    Disciplina dc = (Disciplina) obj->item;
    CxtDisciplina novos_dados = (CxtDisciplina) dados; 
    
    dc->horas = novos_dados->horas;
    
    if(dc->name) free(dc->name);
    dc->name = malloc(strlen(novos_dados->name) + 1); 
    strcpy(dc->name, novos_dados->name);
    
    free(novos_dados->name);
    free(novos_dados);
}

void set_Professor(Object obj, void* dados){
    if(!obj || !obj->item || !dados) return; 
    Professor pr = (Professor) obj->item; 
    CxtProfessor novos_dados = (CxtProfessor) dados; 
    
    pr->idade = novos_dados->idade;
        
    if(pr->name) free(pr->name);
    pr->name = malloc(strlen(novos_dados->name) + 1); 
    strcpy(pr->name, novos_dados->name);
    
    free(novos_dados->name);
    free(novos_dados);
}


// Função que você precisa adicionar acima da main para o Exercício 1 funcionar:
List filter_disciplinas(List lst) {
    List nova_lista = new(List);
    if (!lst || !lst->head) return nova_lista;

    Object atual = lst->head;
    while (atual) {
        // Truque elegante: descobrimos se é Disciplina checando o ponteiro de print!
        if (atual->print == print_Disciplina) {
            // Criamos um novo nó cópia para não estragar os ponteiros da lista original
            Object copia = new(ObjDisciplina);
            Disciplina dados_originais = (Disciplina)atual->item;
            
            // Copiamos os dados usando o construtor de contexto
            copia->set(copia, new(Disciplina, dados_originais->name, dados_originais->horas));
            
            nova_lista->append_enqueue(nova_lista, copia);
        }
        atual = atual->right;
    }
    return nova_lista;
}

int main() {
    List lst = new(List);

    // Inserindo Disciplinas e Professores intercalados
    Object d1 = new(ObjDisciplina); d1->set(d1, new(Disciplina, "Calculo I", 80));
    lst->append_enqueue(lst, d1);

    Object p1 = new(ObjProfessor); p1->set(p1, new(Professor, "Adriano", 42));
    lst->append_enqueue(lst, p1);

    Object d2 = new(ObjDisciplina); d2->set(d2, new(Disciplina, "Estrutura de Dados", 120));
    lst->append_push(lst, d2); // Inserindo no início (push)

    Object p2 = new(ObjProfessor); p2->set(p2, new(Professor, "Pasquale", 50));
    lst->append_push(lst, p2); // Inserindo no início (push)

    printf("--- Lista Original Completa ---\n");
    lst->print(lst);

    // Filtrando apenas as disciplinas
    List lst_temp = filter_disciplinas(lst);

    printf("\n--- Lista Original Depois do Filtro (Deve continuar igual) ---\n");
    lst->print(lst);

    printf("\n--- Nova Lista Filtrada (Apenas Disciplinas) ---\n");
    lst_temp->print(lst_temp);

    // Limpeza de memória
    clear(lst); free(lst);
    clear(lst_temp); free(lst_temp);

    return 0;
}
