#include "stdio.h"
#include "stdlib.h"
#include "string.h"

#include "tads/patricia.h"
#include "tads/lista_patricia.h"
#include "abrir_arquivo.h"
#include "cores/cores.h"

int main(void){

    No_Patricia *no;
    Lista_Encadeada *lista;
    FILE *arquivo = fopen("arquivos.txt", "r");
    char nome[100];
    int Numero_Arquivos = 0;
    while(!feof(arquivo)){
        fscanf(arquivo, "%s", nome);
        //printf("%s", nome);
        Abrir_Arquivo(nome, &no, Numero_Arquivos);
        Numero_Arquivos++;
    }
    fclose(arquivo);
    Printar_Palavra(&no);
    Printar_Ocorrencias(&no);
    return 0;
}
