#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>



typedef struct tipoItem {
    char *key;
    struct tipoItem *next;
    int idArq;// nome do docPai
    int numDeRepeticoes;// n de rep
} tipoItem;

typedef struct {
    int countItens;
    int tamanho;
    tipoItem **entries;
} hashTable;
