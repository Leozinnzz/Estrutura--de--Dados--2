#include <stdio.h>
#include <stdlib.h>

// Troca dois elementos de posição em dois arrays simultaneamente (inicio e fim)
void trocar(int inicio[], int fim[], int i, int j) {
    int temp;          
    temp = fim[i];     
    fim[i] = fim[j];  
    fim[j] = temp;     
    temp = inicio[i];  
    inicio[i] = inicio[j]; 
    inicio[j] = temp;  
}

// Ordena os intervalos pelo valor de fim utilizando Selection Sort recursivo
void ordenar(int inicio[], int fim[], int i, int n) {
    if (i >= n - 1) return; // Caso base: se chegou ao penúltimo elemento, para a recursão

	
    int menor = i; 

    for (int j = i + 1; j < n; j++) { 
        if (fim[j] < fim[menor]) {    
            menor = j;                 
        }
    }

    if (menor != i) {             
        trocar(inicio, fim, i, menor); // Troca o intervalo atual com o menor encontrado
    }

    ordenar(inicio, fim, i + 1, n); // Chamada recursiva para ordenar o restante do array
}

// Exibe todos os intervalos no formato [inicio, fim]
void mostrarIntervalos(int inicio[], int fim[], int n) {
    for (int i = 0; i < n; i++) {       
        printf("[%d,%d] ", inicio[i], fim[i]); 
    }
    printf("\n"); 
}

// Escolhe os intervalos não sobrepostos usando algoritmo Guloso de forma recursiva
void greedyRecursivo(int inicio[], int fim[], int i, int n, int ultimo_fim) {
    if (i >= n) return; // Caso base: se percorreu todos os intervalos, encerra

    printf("Analisando [%d,%d] ... ", inicio[i], fim[i]); 

    if (inicio[i] >= ultimo_fim) {       // Se o início do intervalo atual não sobrepõe o último escolhido
        printf("escolhido -> NAO SOBREPOE\n"); 
        ultimo_fim = fim[i];             // Atualiza o fim do último intervalo escolhido
    } else {                        
        printf("descartado -> SOBREPOE\n");   // Informa que foi descartado
    }

    greedyRecursivo(inicio, fim, i + 1, n, ultimo_fim); // Chamada recursiva para o próximo intervalo
}

// Função principal que coordena todo o processo guoloso
void greedyIntervalos(int inicio[], int fim[], int n) {
    printf("Intervalos originais:\n");      
    mostrarIntervalos(inicio, fim, n);      // Exibe os intervalos antes de ordenar

    ordenar(inicio, fim, 0, n);             // Ordena os intervalos pelo valor de fim (recursivo)

    printf("\nIntervalos ordenados pelo fim:\n"); 
    mostrarIntervalos(inicio, fim, n);           // Exibe os intervalos após ordenação

    printf("\nEscolhendo intervalos:\n");         
    printf("Escolhido -> [%d,%d]\n", inicio[0], fim[0]); 
    
    greedyRecursivo(inicio, fim, 1, n, fim[0]);  // Inicia a seleção greedy recursiva a partir do segundo intervalo
}

int main() {
    int inicio[] = {6, 4, 2, 1}; 
    int fim[]    = {8, 7, 4, 2}; 
    int n = 4;                   

    greedyIntervalos(inicio, fim, n); // Função que executa o algoritmo guloso

}
