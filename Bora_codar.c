#include <stdio.h>
#include <stdlib.h>


void ordenar(int arr[], int n) {
	if(n <= 1)
		return;
	for(int i = 0; i < n-1; i++) {
		if(arr[i] > arr[i+1]) {
			int temp = arr[i];
			arr[i] = arr[i+1];
			arr[i+1] = temp;
		}
	}
	
	ordenar(arr, n-1);
}
int buscaBinaria(int alvo, int inicio, int fim, int arr[]){
	if(inicio > fim)
		return -1;
	
	int meio = (inicio + fim) / 2;
	
	if(arr[meio] == alvo)
		return meio;
		
	if(alvo < arr[meio])
		return buscaBinaria(alvo, inicio, meio -1,  arr);
	else
		return buscaBinaria(alvo, meio+1, fim, arr);
	
		
}

int main() {
	
	int n;
    
    printf("Digite o tamanho do array: ");
    scanf("%d", &n);
    
    int v[n];
    
    //preencher vetor
    for(int i = 0; i < n; i++) {
		v[i] = rand()%100;
		printf(" [%d] ", v[i]);
	}

	
	ordenar(v, n);
	
	printf("\nVetor ordenardo\n");
	
	
	for(int i = 0; i < n; i++) {
		printf(" [%d] ", v[i]);
	}
	
	int alv;
	
	printf("\nDigite o nuimero que deja buscar: ");
	scanf("%d", &alv);
	
	
	int idc = buscaBinaria(alv, 0, n-1, v);
	
	if(idc == -1)
		printf("Numero nao encontrado!");
	else 
		printf("\nO numero foi encontrado no indice %d: ", idc);
}


