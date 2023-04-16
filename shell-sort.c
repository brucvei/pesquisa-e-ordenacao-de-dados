/*  começa selecionando um intervalo (gap) que será usado para dividir a lista em 
sub-listas menores. Em seguida, ele ordena cada sub-lista com o algoritmo de Insertion
Sort. Então, ele reduz o intervalo e repete o processo até que o intervalo seja igual a 1 */

#include <stdio.h>
#include <stdlib.h>

// shell sort
void shellSort(int *vetor, int tamanho) {
  int i, j, value;
  int gap = 1;

  while (gap < tamanho) {
    gap = 3 * gap + 1;
  }

  while (gap > 1) {
    gap /= 3;
    for (i = gap; i < tamanho; i++) {
      value = vetor[i];
      j = i - gap;
      while (j >= 0 && value < vetor[j]) {
        vetor[j + gap] = vetor[j];
        j -= gap;
      }
      vetor[j + gap] = value;
    }
  }
}