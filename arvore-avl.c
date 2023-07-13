#include<stdio.h>
#include<stdlib.h>
struct dados{
  char nome[100];
};

struct no {
  int valor;
  //struct dados d;
  int alt;
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
  a->alt=0;
  a->esq = esq;
  a->dir = dir;
  return a;
}

int alt_no(arvore *a){
  if (esta_vazia(a)) return -1;
  else return a->alt;
}

int calc_altura(arvore *a){
  if (alt_no(a->esq) > alt_no(a->dir)) return alt_no(a->esq)+1;
  else return alt_no(a->dir)+1;
}

int calc_fb(arvore *a){
  return (alt_no(a->esq) - alt_no(a->dir));
}

void rot_ll(arvore **a){ //simples a direita
  printf("....LL....\n");
  arvore *b = (*a)->esq;
  (*a)->esq = b->dir;
  b->dir = (*a);
  (*a)->alt = calc_altura(*a);
  b->alt = calc_altura(b);
  (*a) = b;
}

void rot_rr(arvore **a){ //simples a esquerda
//TODO
}

void rot_lr(arvore **a){ // rot dir esq
//TODO
}

void rot_rl(arvore **a){ // rot esq dir 
//TODO
}

void balanc(arvore **a){
  int fb = calc_fb(*a);
  if(fb >= 2) { // esquerda desbalanceada
    if (calc_fb((*a)->esq) > 0) // neto esquerda desb.
      rot_ll(a);
    else // neto dir desb.
      rot_lr(a);
  }
  else if(fb<=-2){ // direita desbalanceada
    if (calc_fb((*a)->dir) < 0) // neto direita desb.
      rot_rr(a);
    else // neto esq desb.
      rot_rl(a);
  }
}

void insere(int valor, arvore **a){
  printf("Inserindo %d\n",valor);

  if (!esta_vazia(*a)){
    if (valor < (*a)->valor){
      if (esta_vazia((*a)->esq)) (*a)->esq = aloca_arvore(valor, arvore_vazia(), arvore_vazia());
      else insere(valor, &(*a)->esq);
    } else if (valor == (*a)->valor){
      printf("Valor duplicado");
      return;
    } else if (valor > (*a)->valor)
      if (esta_vazia((*a)->dir)) (*a)->dir = aloca_arvore(valor, arvore_vazia(), arvore_vazia());
      else insere(valor, &(*a)->dir);
  } else { // a arvore esta vazia
    (*a)=aloca_arvore(valor, arvore_vazia(), arvore_vazia());
  }

  (*a)->alt = calc_altura(*a);
  balanc(a);
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

void main(){
  arvore *arv = arvore_vazia();
  insere(1, &arv);
  insere(2, &arv);
  insere(3, &arv);
  insere(4, &arv);
  insere(5, &arv);
  imprime(arv);
}
