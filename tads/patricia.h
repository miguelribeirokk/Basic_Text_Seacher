#ifndef PATRICIA_H
#define PATRICIA_H

#include "lista_patricia.h"

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
int Cria_No_Externo(No_Patricia **no, char *palavra, char *arquivo);
int Cria_No_Interno(No_Patricia **no, char caractere, int posicao, No_Patricia **esq, No_Patricia **dir);
int No_Diferente(No_Patricia **no, char *palavra);
char Retornar_Caractere(No_Patricia **no, int posicao);
int Retornar_Posicao(No_Patricia **no);
int Insere_Entre(No_Patricia **no, char *palavra, int posicao, char caractere, char *filename);
int Incrementa_Ocorrencias(No_Patricia **no, char *filename);
int Insere_Palavra(No_Patricia **no, char *palavra, char *filename);
int Printar_Palavra(No_Patricia **no);
int Printar_Ocorrencias(No_Patricia **no);
Lista_Encadeada *Buscar_Palavra(No_Patricia **no, char *palavra);
//int Remove_No(No_Patricia **no);

#endif 