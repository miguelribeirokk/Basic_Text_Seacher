#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#include "abrir_arquivo.h"
#include "tads/patricia.h"


FILE* Ler_Arquivo(char arquivo[100]){
    FILE *arquivo1 = fopen(arquivo, "r");
    if(arquivo1 == NULL){
        printf("Erro ao abrir o arquivo!\n");
        return NULL;
    }
    return arquivo1;
    }

char *Transformar_Palavra(char palavra[100]){
    int i;
    for (i = 0; i < strlen(palavra); i++){
        if (palavra[i] >= 65 && palavra[i] <= 90) {
            palavra[i] += 32;
        }
    }
    return palavra;
}




void Abrir_Arquivo(char nome[100], No_Patricia **no, int Numero_Arquivos){
    //printf("%s", nome);
    char pasta[100] = "arquivos/";
    char palavra[100];
    char numero[100];
    FILE *arquivo2 = NULL;
    if (Numero_Arquivos == 0){
        return;
    }
    strcat(pasta, nome);
    int a = strlen(pasta);
    
    arquivo2 = fopen(pasta, "r");
    
    if(arquivo2 == NULL){
        printf("Erro ao abrir o arquivo");
        return;
    }
    sprintf(numero, "%d", Numero_Arquivos);
    while(!feof(arquivo2)){
        fscanf(arquivo2, "%s", palavra);
        printf("%s\n", palavra);
        char *palavra2 = Transformar_Palavra(palavra);
        Insere_Palavra(no, palavra, numero);
    }
    fclose(arquivo2);
    return;
}





