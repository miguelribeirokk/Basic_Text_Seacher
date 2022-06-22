//Implementado por:
//Miguel Antonio Ribeiro e Silva - 4680
//Alan Gabriel Martins Silva - 4663
//Vinicius Alves Gontijo - 4708
//Gabriel Ryan -
#ifndef PATRICIA_H
#define PATRICIA_H

#include "linked_list.h"

typedef enum { interno, externo } TipoNo;


typedef struct No_Patricia{
  TipoNo TipoNo;
  union {
    struct {
      char caractere;
      int posicao;
      struct No_Patricia *esq;
      struct No_Patricia *dir;
    } interno;
    struct {
      char *palavra;
      Lista_Encadeada *lista;
    } externo;
  }No;
} No_Patricia;

int Inicializa(No_Patricia **no);
int Externo(No_Patricia **no);
int Confere(No_Patricia **no, char *palavra);
int Cria_No_Externo(No_Patricia **no, char *palavra, int arquivo);
int Cria_No_Interno(No_Patricia **no, char caractere, int posicao, No_Patricia **esq, No_Patricia **dir);
int No_Diferente(No_Patricia **no, char *palavra);
char Retornar_Caractere(No_Patricia **no, int posicao);
int Retornar_Posicao(No_Patricia **no);
int Insere_Entre(No_Patricia **no, char *palavra, int posicao, char caractere, int filename);
int Incrementa_Ocorrencias(No_Patricia **no, int filename);
int Insere_Palavra(No_Patricia **no, char *palavra, int filename);
int Printar_Palavra(No_Patricia **no);
int Printar_Ocorrencias(No_Patricia **no);
Lista_Encadeada *Buscar_Palavra(No_Patricia **no, char *palavra);
int Free_Patricia(No_Patricia **no);

#endif 