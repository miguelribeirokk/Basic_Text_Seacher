#ifndef linked_list_h
#define linked_list_h

typedef struct Lista_Encadeada{
    unsigned int ocorrencias;
    int nome_arquivo;
    struct Lista_Encadeada *prox;
}Lista_Encadeada;

int Inicializa_Lista(Lista_Encadeada **lista);
int LE_Criar_No(Lista_Encadeada **lista, int arquivo);
int LE_Incrementa_Ocorrencias(Lista_Encadeada **lista);
int LE_Insere_No(Lista_Encadeada **lista, int arquivo);
int LE_Printa_Lista(Lista_Encadeada **lista);
int Free_Lista(Lista_Encadeada **lista);

#endif


