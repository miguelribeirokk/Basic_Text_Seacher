#ifndef lista_patricia_h
#define lista_patricia_h

typedef struct Lista_Encadeada{
    unsigned int ocorrencias;
    char nome_arquivo[30];
    struct Lista_Encadeada *prox;
}Lista_Encadeada;

int Inicializa_Lista(Lista_Encadeada **lista);
int LE_Criar_No(Lista_Encadeada **lista, char *nome_arquivo);
int LE_Incrementa_Ocorrencias(Lista_Encadeada **lista);
int LE_Insere_No(Lista_Encadeada **lista, char *nome_arquivo);
int LE_Printa_Lista(Lista_Encadeada **lista);
int LE_Remove_No(Lista_Encadeada **lista);

#endif


