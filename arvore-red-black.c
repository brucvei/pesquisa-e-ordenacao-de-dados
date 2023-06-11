// Bruna Caetano e Fischer Matielo - SI - Pesquisa e Ordenacao de dados
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
  int valor;
  char cor; // 'R' para vermelho, 'B' para preto
  struct Node *pai;
  struct Node *esquerda;
  struct Node *direita;
} Node;

Node *criaNode(int dado) {
  Node *novoNo = (Node *)malloc(sizeof(Node));
  novoNo->valor = dado;
  novoNo->cor = 'R'; 
  novoNo->pai = NULL;
  novoNo->esquerda = NULL;
  novoNo->direita = NULL;
  return novoNo;
}

void trocaCor(Node **a, Node **b) {
  char temp = (*a)->cor;
  (*a)->cor = (*b)->cor;
  (*b)->cor = temp;
}

void rotacionaEsquerda(Node **root, Node *node) {
  Node *filhoDireito = node->direita;
  node->direita = filhoDireito->esquerda;

  if (filhoDireito->esquerda != NULL)
    filhoDireito->esquerda->pai = node;

  filhoDireito->pai = node->pai;

  if (node->pai == NULL) (*root) = filhoDireito;
  else if (node == node->pai->esquerda) node->pai->esquerda = filhoDireito;
  else node->pai->direita = filhoDireito;

  filhoDireito->esquerda = node;
  node->pai = filhoDireito;
}

void rotacionaDireita(Node **root, Node *node) {
  Node *filhoEsquerdo = node->esquerda;
  node->esquerda = filhoEsquerdo->direita;

  if (filhoEsquerdo->direita != NULL) filhoEsquerdo->direita->pai = node;

  filhoEsquerdo->pai = node->pai;

  if (node->pai == NULL) (*root) = filhoEsquerdo;
  else if (node == node->pai->esquerda) node->pai->esquerda = filhoEsquerdo;
  else node->pai->direita = filhoEsquerdo;

  filhoEsquerdo->direita = node;
  node->pai = filhoEsquerdo;
}

void fixInsertion(Node **root, Node *node) {
  while (node != (*root) && node->pai->cor == 'R') {
    Node *avo = node->pai->pai;
    Node *tio;

    if (node->pai == avo->esquerda) {
      tio = avo->direita;

      if (tio != NULL && tio->cor == 'R') {
        node->pai->cor = 'B';
        tio->cor = 'B';
        avo->cor = 'R';
        node = avo;
      } else {
        if (node == node->pai->direita) {
          node = node->pai;
          rotacionaEsquerda(root, node);
        }

        node->pai->cor = 'B';
        avo->cor = 'R';
        rotacionaDireita(root, avo);
      }
    } else {
      tio = avo->esquerda;

      if (tio != NULL && tio->cor == 'R') {
        node->pai->cor = 'B';
        tio->cor = 'B';
        avo->cor = 'R';
        node = avo;
      } else {
        if (node == node->pai->esquerda) {
          node = node->pai;
          rotacionaDireita(root, node);
        }

        node->pai->cor = 'B';
        avo->cor = 'R';
        rotacionaEsquerda(root, avo);
      }
    }
  }

  (*root)->cor = 'B';
}

void insertNode(Node **root, int data) {
  Node *novo = criaNode(data);

  Node *atual = (*root);
  Node *pai = NULL;

  while (atual != NULL) {
    pai = atual;

    if (data < atual->valor) atual = atual->esquerda;
    else if (data > atual->valor) atual = atual->direita;
    else {
      printf("Duplicado! Não é possível inserir o mesmo valor.\n");
      free(novo);
      return;
    }
  }

  novo->pai = pai;

  if (pai == NULL) (*root) = novo;
  else if (data < pai->valor) pai->esquerda = novo;
  else pai->direita = novo;

  fixInsertion(root, novo);
}

void printarArvore(Node *no) {
  if (no != NULL) {
    printarArvore(no->esquerda);
    printf("%d ", no->valor);
    printarArvore(no->direita);
  }
}

Node *buscarNo(Node *root, int data) {
  if (root == NULL || root->valor == data) return root;
  if (data < root->valor) return buscarNo(root->esquerda, data);
  return buscarNo(root->direita, data);
}

Node *proximoNo(Node *node) {
  node = node->direita;
  while (node->esquerda != NULL) node = node->esquerda;
  return node;
}

void ajustarRemocao(Node **root, Node *node, Node *parent) {
  Node *irmao;

  while ((node == NULL || node->cor == 'B') && node != (*root)) {
    if (node == parent->esquerda) {
      irmao = parent->direita;

      if (irmao->cor == 'R') {
        irmao->cor = 'B';
        parent->cor = 'R';
        rotacionaEsquerda(root, parent);
        irmao = parent->direita;
      }

      if ((irmao->esquerda == NULL || irmao->esquerda->cor == 'B') && (irmao->direita == NULL || irmao->direita->cor == 'B')) {
        irmao->cor = 'R';
        node = parent;
        parent = node->pai;
      } else {
        if (irmao->direita == NULL || irmao->direita->cor == 'B') {
          irmao->esquerda->cor = 'B';
          irmao->cor = 'R';
          rotacionaDireita(root, irmao);
          irmao = parent->direita;
        }

        irmao->cor = parent->cor;
        parent->cor = 'B';
        irmao->direita->cor = 'B';
        rotacionaEsquerda(root, parent);
        node = *root;
        break;
      }
    } else {
      irmao = parent->esquerda;

      if (irmao->cor == 'R') {
        irmao->cor = 'B';
        parent->cor = 'R';
        rotacionaDireita(root, parent);
        irmao = parent->esquerda;
      }

      if ((irmao->direita == NULL || irmao->direita->cor == 'B') && (irmao->esquerda == NULL || irmao->esquerda->cor == 'B')){
        irmao->cor = 'R';
        node = parent;
        parent = node->pai;
      } else {
        if (irmao->esquerda == NULL || irmao->esquerda->cor == 'B') {
          irmao->direita->cor = 'B';
          irmao->cor = 'R';
          rotacionaEsquerda(root, irmao);
          irmao = parent->esquerda;
        }

        irmao->cor = parent->cor;
        parent->cor = 'B';
        irmao->esquerda->cor = 'B';
        rotacionaDireita(root, parent);
        node = *root;
        break;
      }
    }
  }

  if (node != NULL) node->cor = 'B';
}

void substitui(Node **root, Node *pTrocar, Node *substituto) {
  if (pTrocar->pai == NULL)
    *root = substituto;
  else if (pTrocar == pTrocar->pai->esquerda)
    pTrocar->pai->esquerda = substituto;
  else
    pTrocar->pai->direita = substituto;

  if (substituto != NULL)
    substituto->pai = pTrocar->pai;
}

void removeNo(Node **root, int data) {
  Node *no = buscarNo(*root, data);

  if (no == NULL){
    printf("Valor %d não encontrado na árvore.\n", data);
    return;
  }

  Node *pai = no->pai;
  Node *filho = NULL;
  char corAnterior = no->cor;

  if (no->esquerda == NULL) {
    filho = no->direita;
    substitui(root, no, no->direita);
  } else if (no->direita == NULL) {
    filho = no->esquerda;
    substitui(root, no, no->esquerda);
  } else {
    Node *successor = proximoNo(no);
    corAnterior = successor->cor;
    filho = successor->direita;

    if (successor->pai == no) pai = successor;
    else {
      substitui(root, successor, successor->direita);
      successor->direita = no->direita;
      successor->direita->pai = successor;
    }

    substitui(root, no, successor);
    successor->esquerda = no->esquerda;
    successor->esquerda->pai = successor;
    successor->cor = no->cor;
  }

  free(no);

  if (corAnterior == 'B') ajustarRemocao(root, filho, pai);
}

int main() {
  Node *root = NULL;

  insertNode(&root, 10);
  insertNode(&root, 20);
  insertNode(&root, 30);
  insertNode(&root, 40);
  insertNode(&root, 50);
  insertNode(&root, 60);
  insertNode(&root, 70);

  printf("Árvore Red-Black em ordem: ");
  printarArvore(root);
  printf("\n");

  int value = 30;
  Node *result = buscarNo(root, value);
  if (result != NULL) printf("Valor %d encontrado na árvore!\n", value);
  else printf("Valor %d não encontrado na árvore.\n", value);

  removeNo(&root, value);
  printf("Árvore Red-Black em ordem: ");
  printarArvore(root);
  printf("\n");

  return 0;
}
