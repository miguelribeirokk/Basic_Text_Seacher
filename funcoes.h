#ifndef  ABRIR_ARQUIVO_H
#define ABRIR_ARQUIVO_H

#include "tads/patricia.h"


FILE *Ler_Arquivo(char arquivo[100]);
void Abrir_Arquivo(char nome[100], No_Patricia **no, int Numero_Arquivos);
char *Transformar_Palavra(char palavra[100]);
void flush_in();
void Retorna_Peso(Lista_Encadeada **lista,  int Numero_Arquivos, int contador, float **peso);
float **Fazer_Matriz(int num_arquivos, int palavras);



#endif
