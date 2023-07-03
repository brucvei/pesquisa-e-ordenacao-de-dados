#include <stdio.h>
#include <stdlib.h>

static int pesquisa_sequencial(int *arr, int value){
	for (int i = 0; arr[i] <= value; i++){
		if (arr[i] == value) return i;
	}
	return -1;
}

static int pesquisa_binaria(int *arr, int value){
	int i = 0;
	int j =  sizeof(arr) - 1;
	
	while (i <= j){
		int k = (i + j) / 2;
		if (arr[k] == value) return k;
		else if (arr[k] < value) i = k + 1;
		else j = k - 1;
	}

	return -1;
}  

int main() {
    int lista[] = {10, 25, 30, 45, 50, 65, 70};
    int valor = 45;
    
    int indice = pesquisa_binaria(lista, valor);
    
    if (indice != -1) printf("Elemento encontrado no índice %d\n", indice);
    else printf("Elemento não encontrado\n");
    
    return 0;
}
