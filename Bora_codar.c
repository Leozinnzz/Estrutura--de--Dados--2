#include <stdio.h>
#include <stdlib.h>

int sumArr(int c, int arr[]) {
	if(c == 0)
		return 0;
	return arr[c-1] + sumArr(c-1, arr);
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
	
	int sum = sumArr(n, v);
    
    printf("\n soma do vetor igual a %d: ", sum);
}


