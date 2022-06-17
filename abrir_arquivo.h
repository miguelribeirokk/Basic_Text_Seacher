#ifndef  ABRIRA_ARQUIVO_H
#define ABRIRA_ARQUIVO_H

#include "tads/patricia.h"


FILE *Ler_Arquivo(char arquivo[100]);
void Abrir_Arquivo(char nome[100], No_Patricia **no, int Numero_Arquivos);
char *Transformar_Palavra(char palavra[100]);




#endif
