#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tad.h"

void IniciaArvore(apontador *no){
    *no = NULL;
    
}

void Insere(apontador *no, TipoAluno aluno){
    
    if(*no == NULL){
        *no = (apontador)malloc(sizeof(TipoNo));
        (*no)->aluno = aluno;
        (*no)->esq = NULL;
        (*no)->dir = NULL;
    }
     
    else{
        if(aluno.nota <= (*no)->aluno.nota){
            
            Insere(&(*no)->esq, aluno);
        }
        else if(aluno.nota > (*no)->aluno.nota){
            Insere(&(*no)->dir, aluno);
        }
            
        
    }
}
void percorrer(apontador no){
    if(no != NULL){
        percorrer(no->esq);
        printf("%s %d %.2f\n", no->aluno.nome, no->aluno.matricula, no->aluno.nota);
        percorrer(no->dir);
    }
}
void percorrer_inversa(apontador no){
    if(no != NULL){
        percorrer_inversa(no->dir);
        printf("%s %d %.2f\n", no->aluno.nome, no->aluno.matricula, no->aluno.nota);
        percorrer_inversa(no->esq);
    }
}
int contar_Aluno(apontador no){
    int contador = 0; //começa com o nó raiz
    if(no != NULL){
        contador++;
        contador += contar_Aluno(no->esq);
        contador += contar_Aluno(no->dir);
        
    }
    return contador;
    
}
 void menor_nota(apontador no){
    if(no->esq != NULL){
        menor_nota(no->esq);
    }
    else{
        printf("Menor nota- %s - %d - %.2f\n", no->aluno.nome, no->aluno.matricula, no->aluno.nota);
    }
}

float soma_das_notas(apontador *no, int contador){   
    float soma = 0;
    if(*no != NULL){
        soma += (*no)->aluno.nota;
        soma += soma_das_notas(&(*no)->esq, contador);
        soma += soma_das_notas(&(*no)->dir, contador);
    }
    return soma;
}
float media_das_notas(float soma, int contador){
    float media = soma/contador;
    return media;
}

void maiores_que_media(apontador *no, float media){
    if(*no != NULL){
        if((*no)->aluno.nota > media){
            printf(" %s - %d - %.2f\n", (*no)->aluno.nome, (*no)->aluno.matricula, (*no)->aluno.nota);
        }
        maiores_que_media(&(*no)->esq, media);
        maiores_que_media(&(*no)->dir, media);
    }
}


