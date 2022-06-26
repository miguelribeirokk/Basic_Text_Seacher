//Implementado por:
//Miguel Antonio Ribeiro e Silva - 4680
//Alan Gabriel Martins Silva - 4663
//Vinicius Alves Gontijo - 4708
//Gabriel Ryan -


#include "tads/hashAssets.h"
#include "funcoes.h"
#include "tads/bst.h"
#include "cores/cores.h"


//Transforma letras maiusculas em minusculas
char *Transformar_Palavra(char palavra[100]){
    long unsigned int i;
    for (i = 0; i < strlen(palavra); i++){
        if (palavra[i] >= 65 && palavra[i] <= 90) {
            palavra[i] += 32;
        }
    }
    return palavra;
}

//Abre o arquivo e insre na Hash
void Abrir_Arquivo_HASH(char nome[100],hashTable *tabela,int Numero_Arquivos){
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
        inserirNaTabela(tabela, palavra, Numero_Arquivos); //Insere a palavra na arvore patricia
    }
    fclose(arquivo2);
    return;
}

//Abre o arquivo e insre na Patricia
void Abrir_Arquivo_PAT(char nome[100], No_Patricia **no,  int Numero_Arquivos){
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
    }
    fclose(arquivo2);
    return;
}

//Limpa o buffer de entrada
void flush_in() { 
    int ch;
    do {
        ch = fgetc(stdin);
    } while (ch != EOF && ch != '\n');
}

//Retorna o peso de cada palavra, inseridos na matriz de pesos
void Retorna_Peso(Lista_Encadeada **lista, int Numero_Arquivos, int contador, float **peso){
    //Calcula os pesos e os insere na matriz
    int ocorrencias = 0, numero_docs = 0;
    Lista_Encadeada *lista2 = *lista;
    Lista_Encadeada *lista3 = *lista;
    Numero_Arquivos += 1;
    //Percorre a lista de palavras, calculando o numero de docs que a palavra aparece
    for (int i = 1; i < Numero_Arquivos; i++){
        if (lista3!= NULL){
            if (lista3->nome_arquivo == i){
                numero_docs++;
                lista3 = lista3->prox;
            }
        }
    }
    free(lista3);

    //Calcula o peso, utilizando  a lista encadeada de ocorrencias
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
int *Quantidade_Palavras_PAT(int *quantidade, int Numero_Arquivos, No_Patricia **no){
    //Retorna o numero de palavras dif. na arvore patricia, inserindo-as em um vetor comum
    for(int i = 0; i < Numero_Arquivos; i++){
        quantidade[i] = Palavras_Diferentes_PAT(no, i+1);
    }
    return quantidade;
}

int *Quantidade_Palavras_Hash(int *quantidade, int Numero_Arquivos, hashTable *tabela){
    //Retorna o numero de palavras dif. na hash, inserindo-as em um vetor comum
    for(int i = 0; i < Numero_Arquivos; i++){
        quantidade[i] = calcPalavras(tabela, i+1);
    }
    return quantidade;
}

float *Relevancia(float *relevancia, int Numero_Arquivos, int palavras, float **peso, int *quantidade){
    //calcula a relevancia de cada arquivo, inserindo-a em um vetor comum
    //Usa o peso e a quantidade de palavras diferentes
    float soma;
    for (int i = 0; i < Numero_Arquivos; i++){
        soma = 0;
        for (int k = 0; k < palavras; k++){
            soma += peso[k][i];
        }
        relevancia[i] = soma/quantidade[i];
    }
    return relevancia;
}

void Printar_Ordenado(float *relevancia, int Numero_Arquivos){
    //Printa os arquivos ordenados por relevancia
    //Usando uma Arvore Binaria de Busca
    apontador no;
    IniciaArvore_BST(&no);
    for (int i = 0; i < Numero_Arquivos; i++){
        Insere_BST(&no, relevancia[i], i+1);
    }
    Ordem_BST(no);
    Free_Arvore_BST(&no);
}
    
        
    





