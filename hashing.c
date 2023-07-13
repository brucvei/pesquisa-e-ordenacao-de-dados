#define TAMANHO 1000

typedef struct no {
    int chave;
    int valor;
    struct no* proximo;
} No;

typedef struct hashtable {
    No** tabela;
} TabelaHash;

int hash(int chave) {
    return chave % TAMANHO;
}

No* criar_no(int chave, int valor) {
    No* novo_no = (No*) malloc(sizeof(No));
    novo_no->chave = chave;
    novo_no->valor = valor;
    novo_no->proximo = NULL;
    return novo_no;
}

TabelaHash* criar_tabela_hash() {
    TabelaHash* tabela_hash = (TabelaHash*) malloc(sizeof(TabelaHash));
    tabela_hash->tabela = (No**) calloc(TAMANHO, sizeof(No*));
    return tabela_hash;
}

void inserir(TabelaHash* tabela_hash, int chave, int valor) {
    int indice = hash(chave);
    No* novo_no = criar_no(chave, valor);
    if (tabela_hash->tabela[indice] == NULL) {
        tabela_hash->tabela[indice] = novo_no;
    } else {
        No* no_atual = tabela_hash->tabela[indice];
        while (no_atual->proximo != NULL) {
            no_atual = no_atual->proximo;
        }
        no_atual->proximo = novo_no;
    }
}

int buscar(TabelaHash* tabela_hash, int chave) {
    int indice = hash(chave);
    No* no_atual = tabela_hash->tabela[indice];
    while (no_atual != NULL) {
        if (no_atual->chave == chave) {
            return no_atual->valor;
        }
        no_atual = no_atual->proximo;
    }
    return -1;
}

void remover_no(TabelaHash* tabela_hash, int chave) {
    int indice = hash(chave);
    No* no_atual = tabela_hash->tabela[indice];
    No* no_anterior = NULL;
    while (no_atual != NULL) {
        if (no_atual->chave == chave) {
            if (no_anterior == NULL) {
                tabela_hash->tabela[indice] = no_atual->proximo;
            } else {
                no_anterior->proximo = no_atual->proximo;
            }
            free(no_atual);
            return;
        }
        no_anterior = no_atual;
        no_atual = no_atual->proximo;
    }
}
