#include "hashAssets.h"


unsigned int hash(const char *key,int tamanho) {
    unsigned long int hashValue = 0;
    unsigned int i = 0;
    unsigned int tamString = strlen(key);
    // aleatorizar os numeros para gerar indices melhores
    for (; i < tamString; ++i){
        hashValue = hashValue * 37 + key[i];
    }
    hashValue = hashValue % tamanho;
    return hashValue;
}

tipoItem *criaItem(const char *key, int indiceDoArq){ 
    //aloca espaço para o item
    tipoItem *entry = malloc(sizeof(tipoItem) * 1);
    entry->key = malloc(strlen(key) + 1);
    entry->lista = malloc(sizeof(Lista_Encadeada));
    entry->lista = NULL;
    strcpy(entry->key, key);
    entry->next = NULL; // ponteiro para o proximo começa como nulo
    LE_Insere_No(&(entry->lista), indiceDoArq);
    return entry;
}

hashTable *iniciaTabela(int tamanho) {
    // aloca espaço para a prox tabela
    hashTable *hashtable = malloc(sizeof(hashTable) * 1);

    // aloca e seta os campos da tabela
    hashtable->entries = malloc(sizeof(tipoItem*) * tamanho);
    hashtable->tamanho = tamanho;
    hashtable->countItens =0;

    // Seta tds os valores da tabela para nulo inicialmente
    int i = 0;
    for(; i < tamanho; ++i){
        hashtable->entries[i] = NULL;
    }
    return hashtable;
}

void inserirNaTabela(hashTable *hashtable, const char *key, int idDoArquivo){
    unsigned int slot = hash(key,hashtable->tamanho);
    // utiliza a funçao hash para entrar com os valores em um indice
    tipoItem *entry = hashtable->entries[slot];
    // se o indice encontrado for nulo, insere direto
    if (entry == NULL) {
        hashtable->entries[slot] = criaItem(key, idDoArquivo);
        hashtable->countItens++;
        
        return; // retorna apos inserir
    }
    tipoItem *prev;
    while(entry != NULL){
        if(strcmp(entry->key,key)==0){    
                LE_Insere_No(&(entry->lista),idDoArquivo);
                hashtable->countItens++;
                return;
        }
        prev = entry;
        entry = prev->next;

    }
    prev->next = criaItem(key, idDoArquivo);
}

Lista_Encadeada **procurarNaTabela(hashTable *hashtable, const char *key) {
    unsigned int slot = hash(key,hashtable->tamanho);
    tipoItem *entry = hashtable->entries[slot];
    if (entry == NULL) {
        return NULL;
    }
    while (entry != NULL) {
        if(strcmp(entry->key, key) == 0){{
                return &(entry->lista); 
                }
            }
            entry = entry->next;
    }
    return NULL;
}

void Free_Table(hashTable *hashtable){
    int i = 0;
    for(; i < hashtable->tamanho; ++i){
        tipoItem *entry = hashtable->entries[i];
        while(entry != NULL){
            tipoItem *temp = entry;
            entry = entry->next;
            free(temp->key);
            free(temp->lista);
            free(temp);
        }
    }
    free(hashtable->entries);
    free(hashtable);
}

void printaTabela(hashTable *tabela){
    for(int i = 0; i < tabela->tamanho; ++i) {
        tipoItem *entry = tabela->entries[i];
        if(entry == NULL) {
            continue;
        }
        for(;;) {
            printf("\n%s", entry->key);
            LE_Printa_Lista(&(entry->lista));
            if (entry->next == NULL) {
                break;
            }
            entry = entry->next;
        }
        printf("\n");
    }
}

void printaPalavras_Hash(hashTable *tabela){
    for(int i = 0; i < tabela->tamanho; ++i) {
        tipoItem *entry = tabela->entries[i];
        if(entry == NULL) {
            continue;
        }
        for(;;) {
            printf("\n%s", entry->key);
            if (entry->next == NULL) {
                break;
            }
            entry = entry->next;
        }
        printf("\n");
    }
}

/*int calcPalavras(hashTable *tabela,int idArq){
    int contPalavras = 0;
     tipoItem *aux;
     for(int i = 0; i < tabela->tamanho; i++){
        tipoItem *entry = tabela->entries[i];
         if(entry == NULL){
            continue;
         }
         else if(entry-> == idArq){
             contPalavras++;
         }
         aux = entry->next;
         while(aux != NULL){
           if(strcmp(entry->key,aux->key) == 0){
                ;
            }
           if(aux->idArq == idArq){
                 contPalavras++;
             }
             aux = aux->next;
        }*/