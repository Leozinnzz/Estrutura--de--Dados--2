#include <stdio.h>
#include <stdlib.h>

int busca(int alvo, int n, int arr[]) {
	if(n == 0)
		return -1;
	if(alvo == arr[n-1])
		return n-1;
	else 
		return busca(alvo, n-1, arr);
	return -1;
	
}

int main() {
	
	/*
	 for(int i = 0; i < n; i++) {
	 
	}
	 */
	
	int n;
    
    printf("Digite o tamanho do array: ");
    scanf("%d", &n);
    
    int v[n];
    
    //preencher vetor
    for(int i = 0; i < n; i++) {
		v[i] = rand()%100;
		printf(" [%d] ", v[i]);
	}
	
	int alv;
	printf("\nDigite o nuimero que deja buscar: ");
	scanf("%d", &alv);
	
	int idc = busca(alv, n, v);
	if(idc == -1)
		printf("Numero nao encontrado!");
	else 
		printf("\nO numero foi encontrado no indice %d: ", idc);
}


