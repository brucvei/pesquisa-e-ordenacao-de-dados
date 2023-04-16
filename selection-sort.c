/*  percorre a lista de elementos repetidamente e seleciona o menor 
elemento e o coloca na primeira posição da lista não ordenada. Em seguida, 
ele encontra o segundo menor elemento e o coloca na segunda posição da lista 
não ordenada, e assim por diante, até que toda a lista esteja ordenada */

#include <stdio.h>
#include <stdlib.h>

// selection sort
void selectionSort(int *vetor, int tamanho) {
  int i, j, min, aux;

  for (i = 0; i < (tamanho - 1); i++) {
    min = i;
    for (j = (i + 1); j < tamanho; j++) {
      if (vetor[j] < vetor[min]) {
        min = j;
      }
    }
    if (i != min) {
      aux = vetor[i];
      vetor[i] = vetor[min];
      vetor[min] = aux;
    }
  }
}