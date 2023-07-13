//Início do código em C de uma árvore Trie. Implemente as funções de inserção e pesquisa.

#define TAM_ALFABETO 26
#define FALSO 0
#define VERDADEIRO 1

struct no_trie {
  struct no_trie *filhos[TAM_ALFABETO];
  int existe; // se verdadeiro, a palavra existe
};

struct no_trie *cria_no(void) {
  int i;
  struct no_trie *no = malloc(sizeof(struct no_trie));
  
	for (i = 0; i < TAM_ALFABETO; i++){
    no->filhos[i] = NULL;
  }
  
	no->existe = FALSO;
  return no;
}

//função auxiliar que converte um caracter para a posicao do indice no vetor de ponteiros
int cparai(char c){
  return (int)(c-'a');
}
