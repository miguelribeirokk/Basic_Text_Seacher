#include "lista_patricia.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int Inicializa_Lista(Lista_Encadeada **no) { //Inicializa a lista
  (*no) = NULL;
  return 1;
}

int LE_Criar_No(Lista_Encadeada **no, char *arquivo) { //Cria nó da lista
    
    (*no) = malloc(sizeof(Lista_Encadeada)); //Cria nó da lista
    if ((*no) == NULL) {
        return 0;
    }
    (**no).ocorrencias = 1;
    strcpy((**no).nome_arquivo, arquivo); //Copia o nome do arquivo para o nó
    (**no).prox = NULL;
    return 1;
}

int LE_Incrementa_Ocorrencias(Lista_Encadeada **no) { //Incrementa ocorrencias
    (**no).ocorrencias++; //Incrementa ocorrencias
    return 1;
}

int LE_Insere_No(Lista_Encadeada **no, char *arquivo) { //Insere nó na lista

    
    if ((*no) == NULL) { 
        return LE_Criar_No(no, arquivo); //Cria nó
    }
    if (strcmp((**no).nome_arquivo, arquivo) == 0) { //Verifica se o arquivo já existe na lista
        return LE_Incrementa_Ocorrencias(no); //Incrementa ocorrencias
    }
    return LE_Insere_No(&((**no).prox), arquivo); //Insere no no final da lista
}

int LE_Printa_Lista(Lista_Encadeada **no) { 
    if ((*no) == NULL) { //Verifica se a lista está vazia
        return 1;
    }
    if (((**no).prox) == NULL){ //Verifica se o nó é o último da lista
        printf("<%d-%s> ", (**no).ocorrencias, (**no).nome_arquivo); //Printa as ocorrencias e o nome do arquivo
        return  1;
    }
    printf("<%d-%s> ", (**no).ocorrencias, (**no).nome_arquivo); //Printa as ocorrencias e o nome do arquivo
    return LE_Printa_Lista(&((**no).prox));
}

int LE_Remove_No(Lista_Encadeada **no){ //Esvazia a lista
    if ((*no) != NULL){
        LE_Remove_No(&((**no).prox));
        free(*no);
        (*no) = NULL;
    }
    return 0;
}
