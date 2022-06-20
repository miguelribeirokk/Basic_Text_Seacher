#include "hashAssets.h"
unsigned int hash(const char *key,int tamanho) {
    unsigned long int hashValue = 0;
    unsigned int i = 0;
    unsigned int tamString = strlen(key);
    // aleatorizar os numeros para gerar indices melhores
    for(; i < tamString; ++i){
        hashValue = hashValue * 37 + key[i];
    }
    hashValue = hashValue % tamanho;
    return hashValue;
}

tipoItem *criaItem(const char *key, int indiceDoArq){ 
    //aloca espaço para o item
    tipoItem *entry = malloc(sizeof(tipoItem) * 1);
    entry->key = malloc(strlen(key) + 1);
    // copy the key and value in place
    strcpy(entry->key, key);
    entry->idArq = indiceDoArq;
    entry->numDeRepeticoes = 1;
    // ponteiro para o proximo começa como nulo
    entry->next = NULL;
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
        printf("\nCHAVE:%s | ID:%d inserida na posicao[%d]\n",key,idDoArquivo,slot);
        return; // retorna apos inserir
    }
    tipoItem *prev;
    while(entry != NULL){
        if(strcmp(entry->key,key)==0){
            if(entry->idArq == idDoArquivo){
                entry->numDeRepeticoes++;
                hashtable->countItens++;
                printf("\nCHAVE:%s | ID:%d inserida na posicao[%d]\n",key,idDoArquivo,slot);    
                return;
            }
            // else if(entry->idArq != idDoArquivo){
            //     entry->next = criaItem(key,idDoArquivo);    
            //     printf("\nCHAVE:%s | ID:%d inserida na posicao[%d]\n",key,idDoArquivo,slot);
            //     hashtable->countItens++;
            //     return;
            // }               
        }
        // caminha para a proxima instancia da lista encadeada
        prev = entry;
        entry = prev->next;
    }    
    // end of chain reached without a match, add new
    prev->next = criaItem(key, idDoArquivo);
}

tipoItem *procurarNaTabela(hashTable *hashtable, const char *key,int idDoArq) {
    unsigned int slot = hash(key,hashtable->tamanho);
    // try to find a valid slot
    tipoItem *entry = hashtable->entries[slot];
    // no slot means no entry
    if (entry == NULL) {
        return NULL;
    }

    // walk through each entry in the slot, which could just be a single thing
    while (entry != NULL) {
        // return value if found
        if(strcmp(entry->key, key) == 0){
            if (entry->idArq == idDoArq ){
                return entry; 
                }
            }
            entry = entry->next;
    }
    // reaching here means there were >= 1 entries but no key match
    return NULL;
}

void removerDaTabela(hashTable *hashtable, const char *key){
    unsigned int bucket = hash(key,hashtable->tamanho);
    // try to find a valid bucket
    tipoItem *entry = hashtable->entries[bucket];

    // no bucket means no entry
    if (entry == NULL){
        return;
    }

    tipoItem *prev;
    int idx = 0;

    // walk through each entry until either the end is reached or a matching key is found
    while (entry != NULL) {
        // check key
        if (strcmp(entry->key, key) == 0) {
            // first item and no next entry
            if (entry->next == NULL && idx == 0) {
                hashtable->entries[bucket] = NULL;
            }
            // first item with a next entry
            if (entry->next != NULL && idx == 0) {
                hashtable->entries[bucket] = entry->next;
            }
            // last item
            if (entry->next == NULL && idx != 0) {
                prev->next = NULL;
            }
            // middle item
            if (entry->next != NULL && idx != 0) {
                prev->next = entry->next;
            }
            // free the deleted entry
            free(entry->key);
            
            free(entry);
            return;
        }
        // walk to next
        prev = entry;
        entry = prev->next;
        ++idx;
    }
}

void printaTabela(hashTable *hashtable) {
    for(int i = 0; i < hashtable->tamanho; ++i) {
        tipoItem *entry = hashtable->entries[i];
        if(entry == NULL) {
            continue;
        }
        printf("indice[%d]: ", i);
        for(;;) {
            printf("%s: <%d,%d>", entry->key, entry->idArq,entry->numDeRepeticoes);
            if (entry->next == NULL) {
                break;
            }
            entry = entry->next;
        }
        printf("\n");
    }
}




int main(){
    hashTable *ht = iniciaTabela(15); //add tamanho
    inserirNaTabela(ht, "vinicius", 3);
    inserirNaTabela(ht, "joao", 3);
    inserirNaTabela(ht, "allan", 1);
    inserirNaTabela(ht, "matheus", 1);
    inserirNaTabela(ht, "iury", 1);
    inserirNaTabela(ht, "miguel", 2);
    inserirNaTabela(ht, "teste", 2);
    inserirNaTabela(ht, "aaaaaaaaaa", 2);
    inserirNaTabela(ht, "aaaaaaaaaa", 3);
    inserirNaTabela(ht, "aaaaaaaaaa", 2);
    inserirNaTabela(ht, "aaaaaaaaaa", 2);
    inserirNaTabela(ht, "aaaaaaaaaa", 2);
    inserirNaTabela(ht, "aaaaaaaaaa", 3);
    inserirNaTabela(ht, "aaaaaaaaaa", 3);
    inserirNaTabela(ht, "aaaaaaaaaa", 3);
    printaTabela(ht);
    // imprimeOrdenado(ht);
    return 0;
}