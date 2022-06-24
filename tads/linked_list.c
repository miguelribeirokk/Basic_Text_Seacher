//Implementado por:
//Miguel Antonio Ribeiro e Silva - 4680
//Alan Gabriel Martins Silva - 4663
//Vinicius Alves Gontijo - 4708
//Gabriel Ryan -
#include "linked_list.h"

int Inicializa_Lista(Lista_Encadeada **no) { //Inicializa a lista
  (*no) = NULL;
  return 1;
}

int LE_Criar_No(Lista_Encadeada **no, int arquivo) { //Cria nó da lista
    
    (*no) = malloc(sizeof(Lista_Encadeada)); //Cria nó da lista
    if ((*no) == NULL) {
        return 0;
    }
    (**no).ocorrencias = 1;
    (**no).nome_arquivo = arquivo; //Copia o nome do arquivo para o nó
    (**no).prox = NULL;
    return 1;
}

int LE_Incrementa_Ocorrencias(Lista_Encadeada **no) {
    (**no).ocorrencias++; //Incrementa ocorrencias
    return 1;
}

int LE_Insere_No(Lista_Encadeada **no, int arquivo) { //Insere nó na lista
    if ((*no) == NULL) { 
        return LE_Criar_No(no, arquivo); //Cria nó
    }
    if (arquivo == (**no).nome_arquivo) { //Verifica se o arquivo é igual ao nó
        LE_Incrementa_Ocorrencias(no); //Incrementa ocorrencias
        return 1;
    }
    return LE_Insere_No(&((**no).prox), arquivo); //Insere no no final da lista
}

int LE_Printa_Lista(Lista_Encadeada **no) { 
    if ((*no) == NULL) { //Verifica se a lista está vazia
        return 1;
    }
    if (((**no).prox) == NULL){ //Verifica se o nó é o último da lista
        printf("<%d-%d> ", (**no).ocorrencias, (**no).nome_arquivo); //Printa as ocorrencias e o nome do arquivo
        return  1;
    }
    printf("<%d-%d> ", (**no).ocorrencias, (**no).nome_arquivo); //Printa as ocorrencias e o nome do arquivo
    return LE_Printa_Lista(&((**no).prox));
}

int Free_Lista(Lista_Encadeada **no){ //Esvazia a lista
    if ((*no) != NULL){
        Free_Lista(&((**no).prox));
        free(*no);
        (*no) = NULL;
    }
    return 0;
}
