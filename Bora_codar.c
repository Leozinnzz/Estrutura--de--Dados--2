#include <stdio.h>
#include <stdlib.h>

int f(int n){
	return !n ? 0: f(n-1)+n;
}


int main() {
	int n;
	
	printf("Digite o valor de n: ");
	scanf("%d", &n);
	
	int resultado = f(n);
	
	printf("Resultado da função de n: %d", resultado);

}


