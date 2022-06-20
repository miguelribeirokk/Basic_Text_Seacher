#include <stdio.h>
#include <stdlib.h>


typedef struct TipoNo *apontador;

typedef struct TipoAluno{
    char nome[50];
    int matricula;
    float nota;
}TipoAluno;

typedef struct TipoNo{
    TipoAluno aluno;
    apontador esq, dir;
}TipoNo;



void IniciaArvore(apontador *no);
void Insere(apontador *no, TipoAluno aluno);
void percorrer(apontador no);
void percorrer_inversa(apontador no);
void menor_nota(apontador no);
int contar_Aluno(apontador no);
float soma_das_notas(apontador *no, int contador);
float media_das_notas(float soma, int contador);
void maiores_que_media(apontador *no, float media);
