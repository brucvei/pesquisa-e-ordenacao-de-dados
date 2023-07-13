#include<stdio.h>
#include<stdlib.h>
struct dados{
  char nome[100];
};

struct no {
  int valor;
  //struct dados d;
  struct no *esq;
  struct no *dir;
};

typedef struct no arvore;

arvore *arvore_vazia(){
  return NULL;
}

int esta_vazia(arvore *a){
  return a == arvore_vazia();
}

arvore *aloca_arvore(int valor, arvore *esq, arvore *dir){
  arvore *a = malloc(sizeof(arvore));
  a->valor = valor;
  a->esq = esq;
  a->dir = dir;
  
	return a;
}

void imprime2d(arvore* a, int esp){
  if (esta_vazia(a)) return;

  esp += 7;
  imprime2d(a->dir, esp);
  printf("\n");

  for (int i=0; i<esp; i++)
    printf(" ");

  printf("%d\n", a->valor);
  imprime2d(a->esq, esp);
}

void imprime(arvore *a){
  imprime2d(a,0);
  printf("-----------------------------------------------\n");
}

void insere(int valor, arvore **a){
  // TODO:

}

void main(){
  arvore *arv=arvore_vazia();
  insere(10, &arv);
  imprime(arv);
  insere(5,  &arv);
  imprime(arv);
  insere(13, &arv);
  imprime(arv);
  insere(1,  &arv);
  imprime(arv);
  insere(2,  &arv);
  imprime(arv);
}
