#include <stdio.h>
#include <stdlib.h>

// Definição da estrutura do nó
typedef struct Node {
  int data;
  char color; // 'R' para vermelho, 'B' para preto
  struct Node *parent;
  struct Node *left;
  struct Node *right;
} Node;

// Função auxiliar para criar um novo nó
Node *createNode(int data) {
  Node *newNode = (Node *)malloc(sizeof(Node));
  newNode->data = data;
  newNode->color = 'R'; // Novos nós são sempre vermelhos por padrão
  newNode->parent = NULL;
  newNode->left = NULL;
  newNode->right = NULL;
  return newNode;
}

// Função auxiliar para trocar as cores de dois nós
void swapColors(Node **a, Node **b) {
  char temp = (*a)->color;
  (*a)->color = (*b)->color;
  (*b)->color = temp;
}

// Função auxiliar para rotacionar o nó para a esquerda
void rotateLeft(Node **root, Node *node) {
  Node *rightChild = node->right;
  node->right = rightChild->left;

  if (rightChild->left != NULL)
    rightChild->left->parent = node;

  rightChild->parent = node->parent;

  if (node->parent == NULL)
    (*root) = rightChild;
  else if (node == node->parent->left)
    node->parent->left = rightChild;
  else
    node->parent->right = rightChild;

  rightChild->left = node;
  node->parent = rightChild;
}

// Função auxiliar para rotacionar o nó para a direita
void rotateRight(Node **root, Node *node) {
  Node *leftChild = node->left;
  node->left = leftChild->right;

  if (leftChild->right != NULL)
    leftChild->right->parent = node;

  leftChild->parent = node->parent;

  if (node->parent == NULL)
    (*root) = leftChild;
  else if (node == node->parent->left)
    node->parent->left = leftChild;
  else
    node->parent->right = leftChild;

  leftChild->right = node;
  node->parent = leftChild;
}

// Função auxiliar para reequilibrar a árvore após a inserção
void fixInsertion(Node **root, Node *node) {
  while (node != (*root) && node->parent->color == 'R') {
    Node *grandparent = node->parent->parent;
    Node *uncle;

    if (node->parent == grandparent->left) {
      uncle = grandparent->right;

      if (uncle != NULL && uncle->color == 'R') {
        node->parent->color = 'B';
        uncle->color = 'B';
        grandparent->color = 'R';
        node = grandparent;
      }
      else {
        if (node == node->parent->right) {
          node = node->parent;
          rotateLeft(root, node);
        }

        node->parent->color = 'B';
        grandparent->color = 'R';
        rotateRight(root, grandparent);
      }
    }
    else {
      uncle = grandparent->left;

      if (uncle != NULL && uncle->color == 'R') {
        node->parent->color = 'B';
        uncle->color = 'B';
        grandparent->color = 'R';
        node = grandparent;
      }
      else {
        if (node == node->parent->left) {
          node = node->parent;
          rotateRight(root, node);
        }

        node->parent->color = 'B';
        grandparent->color = 'R';
        rotateLeft(root, grandparent);
      }
    }
  }

  (*root)->color = 'B';
}

// Função auxiliar para inserir um novo nó na árvore Red-Black
void insertNode(Node **root, int data) {
  Node *newNode = createNode(data);

  // Inserção do nó como em uma árvore binária de busca
  Node *current = (*root);
  Node *parent = NULL;

  while (current != NULL) {
    parent = current;

    if (data < current->data)
      current = current->left;
    else if (data > current->data)
      current = current->right;
    else {
      printf("Duplicado! Não é possível inserir o mesmo valor.\n");
      free(newNode);
      return;
    }
  }

  newNode->parent = parent;

  if (parent == NULL)
    (*root) = newNode;
  else if (data < parent->data)
    parent->left = newNode;
  else
    parent->right = newNode;

  // Reequilibrar a árvore após a inserção
  fixInsertion(root, newNode);
}

// Função auxiliar para imprimir a árvore em ordem
void inorderTraversal(Node *node) {
  if (node != NULL) {
    inorderTraversal(node->left);
    printf("%d ", node->data);
    inorderTraversal(node->right);
  }
}

// Função principal
int main() {
  Node *root = NULL;

  // Exemplo de inserção de nós na árvore
  insertNode(&root, 10);
  insertNode(&root, 20);
  insertNode(&root, 30);
  insertNode(&root, 40);
  insertNode(&root, 50);
  insertNode(&root, 60);
  insertNode(&root, 70);

  // Exemplo de impressão da árvore em ordem
  printf("Árvore Red-Black em ordem: ");
  inorderTraversal(root);
  printf("\n");

  return 0;
}