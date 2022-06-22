#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tads/linked_list.h"



typedef struct tipoItem {
    char *key;
    struct tipoItem *next;
    Lista_Encadeada *lista;
} tipoItem;


typedef struct {
    int countItens;
    int tamanho;
    tipoItem **entries;
} hashTable;

unsigned int hash(const char *key,int tamanho);
tipoItem *criaItem(const char *key, int indiceDoArq);
hashTable *iniciaTabela(int tamanho);
void inserirNaTabela(hashTable *hashtable, const char *key, int idDoArquivo);
Lista_Encadeada **procurarNaTabela(hashTable *hashtable, const char *key);
void removerDaTabela(hashTable *hashtable, const char *key);
void printaTabela(hashTable *tabela);
// int calcPalavras(hashTable *tabela,int idArq);
