//Implementado por:
//Miguel Antonio Ribeiro e Silva - 4680
//Alan Gabriel Martins Silva - 4663
//Vinicius Alves Gontijo - 4708
//Gabriel Ryan -


#include "tads/hashAssets.h"
#include "funcoes.h"
#include "cores/cores.h"

char *Transformar_Palavra(char palavra[100]){
    long unsigned int i;
    for (i = 0; i < strlen(palavra); i++){
        if (palavra[i] >= 65 && palavra[i] <= 90) {
            palavra[i] += 32;
        }
    }
    return palavra;
}

void Abrir_Arquivo(char nome[100], No_Patricia **no, hashTable *tabela,  int Numero_Arquivos){
    char pasta[100] = "arquivos/"; //Caminho da pasta
    char palavra[100];
    FILE *arquivo2 = NULL;
    int fim;
    if (Numero_Arquivos == 0){
        return;
    }
    strcat(pasta, nome); //Concatena o caminho da pasta com o nome do arquivo
    arquivo2 = fopen(pasta, "r");
    if(arquivo2 == NULL){
        printf("Erro ao abrir o arquivo");
        return;
    }
    while(!feof(arquivo2)){
        fim = fscanf(arquivo2, "%s", palavra); //Lê cada palavra do arquivo
        if (fim == EOF){
            break;
        }
        Transformar_Palavra(palavra); //Transforma a palavra em minúsculo
        Insere_Palavra(no, palavra, Numero_Arquivos); //Insere a palavra na arvore patricia
        inserirNaTabela(tabela, palavra, Numero_Arquivos); //Insere a palavra na tabela hash
    }
    fclose(arquivo2);
    return;
}

void flush_in() { //Limpa o buffer de entrada
    int ch;
    do {
        ch = fgetc(stdin);
    } while (ch != EOF && ch != '\n');
}

void Retorna_Peso(Lista_Encadeada **lista, int Numero_Arquivos, int contador, float **peso){
    //Calcula os pesos e os insere na matriz
    int ocorrencias = 0, numero_docs = 0;
    Lista_Encadeada *lista2 = *lista;
    Lista_Encadeada *lista3 = *lista;
    Numero_Arquivos += 1;
    for (int i = 1; i < Numero_Arquivos; i++){
        if (lista3!= NULL){
            if (lista3->nome_arquivo == i){
                numero_docs++;
                lista3 = lista3->prox;
            }
        }
    }
    free(lista3);
    for (int i = 1; i < Numero_Arquivos; i++){
        if (lista2!= NULL){
            if (lista2->nome_arquivo == i){
                    ocorrencias = lista2->ocorrencias;
                    lista2 = lista2->prox;
                    peso[contador][i-1] = (ocorrencias*(log(Numero_Arquivos-1)/numero_docs));
            }
            else{
            }
        }
        else{
        }
    }
    free(lista2);
    return;
}
        
        
    





