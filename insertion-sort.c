/* percorre uma lista de elementos e insere cada elemento em sua posição correta, 
mantendo sempre uma sublista ordenada. 
começa percorrendo a lista a partir do segundo elemento. Em seguida, ele compara 
o elemento atual com o elemento anterior, e se o elemento atual for menor que o 
elemento anterior, eles são trocados de posição. Então, o algoritmo percorre a 
sublista ordenada anterior para encontrar a posição correta para o elemento 
atual e o insere lá. Esse processo é repetido até que todos os elementos estejam
na lista ordenada */

#include <stdio.h>
#include <stdlib.h>

// insertion sort
void insertionSort(int *vetor, int tamanho) {
  int i, j, aux;

  for (i = 1; i < tamanho; i++) {
    aux = vetor[i];
    for (j = i; (j > 0) && (aux < vetor[j - 1]); j--) {
      vetor[j] = vetor[j - 1];
    }
    vetor[j] = aux;
  }
}