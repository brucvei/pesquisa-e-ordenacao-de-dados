/* compara repetidamente cada par de elementos adjacentes em uma lista e troca-os se
estiverem na ordem errada. Ele percorre a lista várias vezes, comparando e trocando
os elementos adjacentes até que toda a lista esteja ordenada.*/

#include <stdio.h>
#include <stdlib.h>

// bubble sort
void bubbleSort(int *vetor, int tamanho) {
  int i, j, aux;

  for (i = 0; i < tamanho; i++) {
    for (j = 0; j < tamanho - 1; j++) {
      if (vetor[j] > vetor[j + 1]) {
        aux = vetor[j];
        vetor[j] = vetor[j + 1];
        vetor[j + 1] = aux;
      }
    }
  }
}