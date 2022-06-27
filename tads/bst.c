//Implementado por:
//Miguel Antonio Ribeiro e Silva - 4680
//Alan Gabriel Martins Silva - 4663
//Vinicius Alves Gontijo - 4708
//Gabriel Ryan Dos Santos Oliveira- 4688



#include "bst.h"
#include <stdio.h>
#include <stdlib.h>


//Inicia a arvore BST
void IniciaArvore_BST(apontador *no){
    *no = NULL;
    
}

//Insere um novo no na arvore BST
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

//Imprime a arvore BST em ordem decrescente
void Ordem_BST(apontador no){
    if(no != NULL){
        Ordem_BST(no->dir);
        printf("arquivo%d.txt\n", no->idDoc);
        Ordem_BST(no->esq);
    }
}

//Libera a arvore BST
void Free_Arvore_BST(apontador *no){
    if(*no != NULL){
        Free_Arvore_BST(&(*no)->esq);
        Free_Arvore_BST(&(*no)->dir);
        free(*no);
        *no = NULL;
    }
}