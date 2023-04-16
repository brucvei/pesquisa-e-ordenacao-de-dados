/*  começa construindo uma árvore de heap a partir da lista desordenada. 
Em seguida, ele remove o maior elemento da raiz da árvore de heap e o coloca 
no final da lista ordenada. Então, ele ajusta a árvore de heap para garantir que 
a propriedade de heap seja mantida, e repete o processo de remoção do maior 
elemento e ajuste da árvore até que toda a lista esteja ordenada. */

#include <stdio.h>
#include <stdlib.h>

// heap sort
void heapSort(int *vetor, int tamanho) {
  int i = tamanho / 2, pai, filho, t;

  while (1) {
    if (i > 0) {
      i--;
      t = vetor[i];
    } else {
      tamanho--;
      if (tamanho == 0) {
        return;
      }
      t = vetor[tamanho];
      vetor[tamanho] = vetor[0];
    }

    pai = i;
    filho = i * 2 + 1;
    while (filho < tamanho) {
      if ((filho + 1 < tamanho) && (vetor[filho + 1] > vetor[filho])) {
        filho++;
      }

      if (vetor[filho] > t) {
        vetor[pai] = vetor[filho];
        pai = filho;
        filho = pai * 2 + 1;
      } else {
        break;
      }
    }
    
    vetor[pai] = t;
  }
}