#include "stdio.h"
#include "stdlib.h"
#include "string.h"






#include "tads/patricia.h"
#include "tads/lista_patricia.h"
#include "funcoes.h"
#include "cores/cores.h"


int main(void){

    No_Patricia *no;
    Lista_Encadeada *lista, *lista_aux;
    int fim, palavras, numero_docs, contador = 0;
    unsigned int ocorrencias;
    char *nome_arquivo = (char *)malloc(sizeof(char));
    char *palavra = (char*)malloc(sizeof(char));
    char nome[100];
    float peso[100][100];
    int Numero_Arquivos = 0;
    printf("Digite o nome do arquivo: ");
    scanf("%s", nome_arquivo);
    flush_in();
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
    printf("\nDeseja pesquisar quantas palavras? ");
    scanf ("%d", &palavras);
    float ** matriz = Fazer_Matriz(Numero_Arquivos, palavras);
    flush_in();
    for (int i = 0; i < palavras; i++){
        printf("\nDigite a palavra %d: ", i+1);
        scanf("%s", palavra);
        flush_in();
        lista = Buscar_Palavra(&no, palavra);
        lista_aux = lista;
        if (lista == NULL) printf("Palavra nao encontrada!\n");
        else printf("Palavra encontrada!\n");
        Retorna_Peso(&lista_aux,  Numero_Arquivos, contador, palavras, matriz);
        contador+=1;
    }
    printf("\nMatriz de pesos:\n");
    for (int i = 0; i < palavras; i++){
        for (int j = 0; j < Numero_Arquivos-1; j++){
            printf("%2f ", matriz[i][j]);
        }
        printf("\n");
    }

    return 0;
    
}
