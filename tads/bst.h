//Implementado por:
//Miguel Antonio Ribeiro e Silva - 4680
//Alan Gabriel Martins Silva - 4663
//Vinicius Alves Gontijo - 4708
//Gabriel Ryan -


#ifndef BST_H
#define BST_H

typedef struct TipoNo_BST *apontador;

typedef struct TipoNo_BST{
    float valor;
    int idDoc;
    apontador esq, dir;
}TipoNo_BST;


void IniciaArvore_BST(apontador *no);
void Insere_BST(apontador *no, float valor, int idDoc);
void Ordem_BST(apontador no);
void Free_Arvore_BST(apontador *no);

#endif