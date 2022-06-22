#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tads/linked_list.h"



typedef struct tipoItem {
    char *key;
    struct tipoItem *next;
    int idArq;// nome do docPai
    int numDeRepeticoes;// n de rep
    Lista_Encadeada *lista;
} tipoItem;


typedef struct {
    int countItens;
    int tamanho;
    tipoItem **entries;
} hashTable;