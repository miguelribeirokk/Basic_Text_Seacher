//Implementado por:
//Miguel Antonio Ribeiro e Silva - 4680
//Alan Gabriel Martins Silva - 4663
//Vinicius Alves Gontijo - 4708
//Gabriel Ryan -
#ifndef  ABRIR_ARQUIVO_H
#define ABRIR_ARQUIVO_H
#include "tads/linked_list.h"
#include "tads/patricia.h"
#include "cores/cores.h"





void Abrir_Arquivo_PAT(char nome[100], No_Patricia **no,  int Numero_Arquivos);
void Abrir_Arquivo_HASH(char nome[100],hashTable *tabela,int Numero_Arquivos);
char *Transformar_Palavra(char palavra[100]);
void flush_in();
void Retorna_Peso(Lista_Encadeada **lista,  int Numero_Arquivos, int contador, float **peso);
int *Quantidade_Palavras_Hash(int *quantidade, int Numero_Arquivos, hashTable *tabela);
int *Quantidade_Palavras_PAT(int *quantidade, int Numero_Arquivos, No_Patricia **no);
float *Relevancia(float *relevancia, int Numero_Arquivos, int palavras, float **peso, int *quantidade);
void Printar_Ordenado(float *relevancia, int Numero_Arquivos);



#endif
