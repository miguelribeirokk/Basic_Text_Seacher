//Implementado por:
//Miguel Antonio Ribeiro e Silva - 4680
//Alan Gabriel Martins Silva - 4663
//Vinicius Alves Gontijo - 4708
//Gabriel Ryan -


#include "hashAssets.h"

//Aleatorizar os numeros para gerar indices melhores
unsigned int hash(const char *key,int tamanho) {
    unsigned long int hashValue = 0;
    unsigned int i = 0;
    unsigned int tamString = strlen(key);
    for (; i < tamString; ++i){
        hashValue = hashValue * 37 + key[i];
    }
    hashValue = hashValue % tamanho;
    return hashValue;
}

//Cria um novo item na tabela
tipoItem *criaItem(const char *key, int indiceDoArq){ 
    //Aloca espaço para o item
    tipoItem *entry = malloc(sizeof(tipoItem) * 1);
    entry->key = malloc(strlen(key) + 1);
    entry->lista = malloc(sizeof(Lista_Encadeada));
    entry->lista = NULL;
    strcpy(entry->key, key);
    // Ponteiro para o proximo começa como nulo
    entry->next = NULL;
    LE_Insere_No(&(entry->lista), indiceDoArq);
    return entry;
}

hashTable *iniciaTabela(int tamanho) {
    //Aloca espaço para a prox tabela
    hashTable *hashtable = malloc(sizeof(hashTable) * 1);

    //Aloca e seta os campos da tabela
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
    //Utiliza a funçao hash para entrar com os valores em um indice
    tipoItem *entry = hashtable->entries[slot];
    //Se o indice encontrado for nulo, insere direto
    if (entry == NULL) {
        hashtable->entries[slot] = criaItem(key, idDoArquivo);
        hashtable->countItens++;
        return; // Retorna apos inserir
    }
    tipoItem *prev;
    //Se o indice não for nulo, procura pelo fim da lista
    while(entry != NULL){
        if(strcmp(entry->key,key)==0){    
            //Se achou, insere na lista de indices invertidos
                LE_Insere_No(&(entry->lista),idDoArquivo);
                hashtable->countItens++;
                return;
        }
        prev = entry;
        entry = prev->next;

    }
    prev->next = criaItem(key, idDoArquivo);
}
//Procura na tabela pela lista de indices invertidos
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

//Libera a tabela
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
    tipoItem *prev;
    int idx = 0;
    free(hashtable->entries);
    free(hashtable);
}

//Imprime a tabela
void printaTabela(hashTable *tabela){
    for(int i = 0; i < tabela->tamanho; i++) {
        tipoItem *entry = tabela->entries[i];
        if(entry == NULL){
            continue;
        }
        for(;;) {
            printf("%s", entry->key);
            LE_Printa_Lista(&(entry->lista));
            printf("\n");
            if (entry->next == NULL){
                break;
            }
            entry = entry->next;
        }
    }
}
//Imprime as palavras da tabela
void printaPalavras_Hash(hashTable *tabela){
    for(int i = 0; i < tabela->tamanho; i++) {
        tipoItem *entry = tabela->entries[i];
        if(entry == NULL){
            continue;
        }
        for(;;) {
            printf("%s\n", entry->key);
            if (entry->next == NULL){
                break;
            }
            entry = entry->next;
        }
        printf("\n");
    }
}

//Calula o numero de palavras diferentes em cada arquivo
//Usando a lista de indices invertidos de cada palavra
int calcPalavras(hashTable *tabela,int idDoArq){
    int cont = 0;
    for(int i = 0; i < tabela->tamanho; ++i) {
    tipoItem *entry = tabela->entries[i];
    if(entry == NULL){
        continue;
    }
    for(;;){
        if(entry->lista->nome_arquivo == idDoArq){
            cont++;
        }
        else{
            Lista_Encadeada *aux = entry->lista;
            while(aux != NULL){
                if(aux->nome_arquivo == idDoArq){
                    cont++;
                }
                aux = aux->prox;
            }
            free(aux);
        }
        if (entry->next == NULL){
            break;
        }
        entry = entry->next;
        }
    }
    
    return cont;
}
