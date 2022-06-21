/*#include <stdio.h>  
#include <stdlib.h>
#include <string.h>
#include "abrir_arquivo.h"
#include "tads/patricia.h"




int main(){
    No_Patricia *no;
    Lista_Encadeada *lista;
    FILE *arquivo = fopen("arquivos.txt", "r");
    char nome[100];
    int Numero_Arquivos = 0;
    while(!feof(arquivo)){
        fscanf(arquivo, "%s", nome);
        printf("%s", nome);
        Abrir_Arquivo(nome, &no, Numero_Arquivos);
        Numero_Arquivos++;
    }
   Printar_Ocorrencias(&no);
   return 0;

    
}*/

/*#include <stdio.h>  
#include <stdlib.h>
#include <string.h>
#include <math.h>


int **Fazer_Matriz(int num_arquivos, int palavras){
    int **matriz = (int **)malloc(num_arquivos * sizeof(int *));
    for (int i = 0; i < num_arquivos; i++){
        matriz[i] = (int *)malloc(palavras * sizeof(int));
    }
    for (int i = 0; i < num_arquivos; i++){
        for (int j = 0; j < palavras; j++){
            matriz[i][j] = 0;
        }
    }
    return matriz;
    
}

int main(){
    int num_arquivos = 5;
    int palavras = 2;
    puts("Digite o numero de arquivos: ");
    int **matriz = Fazer_Matriz(num_arquivos, palavras);
    for (int i = 0; i < num_arquivos; i++){
        for (int j = 0; j < palavras; j++){
            //pointer to object
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
    

}*/

