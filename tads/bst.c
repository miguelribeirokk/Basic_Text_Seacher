#include "bst.h"
#include <stdio.h>
#include <stdlib.h>



void IniciaArvore_BST(apontador *no){
    *no = NULL;
    
}

void Insere_BST(apontador *no, float valor, int idDoc){
    
    if(*no == NULL){
        *no = (apontador )malloc(sizeof(TipoNo_BST));
        (*no)->valor = valor;
        (*no)->idDoc = idDoc;
        (*no)->esq = NULL;
        (*no)->dir = NULL;
    }
     
    else{
        if(valor < (*no)->valor){
            
            Insere_BST(&(*no)->esq, valor, idDoc);
            
        }
        else if(valor > (*no)->valor){
            Insere_BST(&(*no)->dir, valor, idDoc);
        }
    }

}
void Ordem_BST(apontador no){
    if(no != NULL){
        Ordem_BST(no->dir);
        printf("arquivo%d.txt\n", no->idDoc);
        Ordem_BST(no->esq);
    }
}

void Free_Arvore_BST(apontador *no){
    if(*no != NULL){
        Free_Arvore_BST(&(*no)->esq);
        Free_Arvore_BST(&(*no)->dir);
        free(*no);
        *no = NULL;
    }
}