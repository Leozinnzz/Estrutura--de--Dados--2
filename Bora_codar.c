#include <stdio.h>
#include <stdlib.h>

int fiboR(int p){
	if(p == 0)
		return 0; 
	if(p == 1)
		return 1;
	return fiboR(p-1) + fiboR(p-2);
}


int main() {
	
	int p;
	
	printf("\n FUNCAO RECURSIVA: \n");
	
	printf("Digite uma posição da sequencia de fibonacci: ");
	scanf("%d", &p);
	
	int resp = fiboR(p);
	
	printf("O numero na posicao do termo e: %d", resp);
	
	printf("\n FUNCAO INTERATIVA: \n");
	
	int n;
	printf("Digite a quantidade de termos: ");
	scanf("%d", &n);
	
	int a = 0, b = 1, temp;
	for(int i = 0; i < n; i++) {
		printf(" %d ", a);
		temp = a + b;
		a = b; 
		b = temp;
	}

}


