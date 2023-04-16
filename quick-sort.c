/*  começa escolhendo um elemento pivô da lista, geralmente o primeiro ou o último elemento,
e divide a lista em duas sub-listas menores: uma sub-lista de elementos menores que o pivô 
e outra sub-lista de elementos maiores que o pivô. O pivô é colocado em sua posição final na 
lista ordenada. Em seguida, o algoritmo repete esse processo recursivamente para as sub-listas 
menores até que toda a lista esteja ordenada. */

#include <stdio.h>
#include <stdlib.h>

// quick sort
void quickSort(int *vetor, int inicio, int fim) {
  int i, j, pivo, aux;

  i = inicio;
  j = fim - 1;
  pivo = vetor[(inicio + fim) / 2];

  while (i <= j) {
    while (vetor[i] < pivo && i < fim) {
      i++;
    }
    while (vetor[j] > pivo && j > inicio) {
      j--;
    }
    if (i <= j) {
      aux = vetor[i];
      vetor[i] = vetor[j];
      vetor[j] = aux;
      i++;
      j--;
    }
  }

  if (j > inicio) {
    quickSort(vetor, inicio, j + 1);
  }
  if (i < fim) {
    quickSort(vetor, i, fim);
  }
}