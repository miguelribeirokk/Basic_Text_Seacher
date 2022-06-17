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
    int fim;
    int a;

    char *nome_arquivo = (char *)malloc(sizeof(char));
    char *palavra = (char*)malloc(sizeof(char));
    char nome[100];
    int Numero_Arquivos = 0;
    printf("Digite o nome do arquivo: ");
    scanf("%s", nome_arquivo);
    setbuf(stdin, NULL);
    FILE *arquivo = fopen(nome_arquivo, "r");
    if(arquivo == NULL){
        printf("Arquivo nao encontrado!\n");
        return 0;
    }
    
    while(!feof(arquivo)){
        fim = fscanf(arquivo, "%s", nome);

        if (fim == EOF){
            break;
        }
        Abrir_Arquivo(nome, &no, Numero_Arquivos);
        Numero_Arquivos++;
    }
    fclose(arquivo);
    Printar_Palavra(&no);
    Printar_Ocorrencias(&no);
    printf("\nPesquisar palavra: ");
    scanf("%s", palavra);
    lista = Buscar_Palavra(&no, palavra);
    if (lista == NULL) printf("Palavra não encontrada!\n");
    else{
        printf("Palavra encontrada!\n");
        do{
            
            printf("<%d-%s> ", lista->ocorrencias, lista->nome_arquivo);
            lista = lista->prox;
    }
    while(lista != NULL); 
    printf("\n");
    return 0;
    
}
}