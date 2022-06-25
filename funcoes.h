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




void Abrir_Arquivo(char nome[100], No_Patricia **no,hashTable *tabela,int Numero_Arquivos);
char *Transformar_Palavra(char palavra[100]);
void flush_in();
void Retorna_Peso(Lista_Encadeada **lista,  int Numero_Arquivos, int contador, float **peso);



#endif
