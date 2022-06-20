// C program to demonstrate Ternary Search Tree (TST) insert, traverse
// and search operations
#include <stdio.h>
#include <stdlib.h>
#define MAX 50

typedef struct TipoNo *apontador;

typedef struct TipoNo{
    char data;
    int flag;
    apontador esq, eq, dir;
}TipoNo;


void IniciaArvore(apontador *no){
    *no = NULL;

}
// A utility function to create a new ternary search tree node
TipoNo* newNode(char data, int flag)
{
    TipoNo* temp = (TipoNo*) malloc(sizeof( TipoNo ));
    temp->data = data;
    temp-> flag = flag;
    temp->esq = temp->eq = temp->dir = NULL;
    return temp;
}

void insere(apontador *raiz, char *word, int flag)
{
    
    if (!(*raiz))
        *raiz = newNode(*word, 0);

    
    if ((*word) < (*raiz)->data)
        insere(&((*raiz)->esq), word, flag);

    
    else if ((*word) > (*raiz)->data)
        insere(&((*raiz)->dir), word, flag);

    
    else
    {
        if (*(word+1))
            insere(&((*raiz)->eq), word+1, flag);

        
        else
            (*raiz)->flag = flag;
    }
}

void percorre( apontador raiz, char *buffer, int depth )
{
    if (raiz)
    {
        
        percorre(raiz->esq, buffer, depth);

        
        buffer[depth] = raiz->data;
        if (raiz->flag)
        {
            buffer[depth+1] = '\0';
            printf( "%s\n", buffer);
        }

        
        percorre(raiz->eq, buffer, depth + 1);

        
        percorre(raiz->dir, buffer, depth);
    }
}

void percorre_TST(apontador raiz)
{
    char buffer[MAX];
    percorre(raiz, buffer, 0);
}

int procura(apontador raiz, char *word)
{
    if (!raiz)
        return 0;

    if (*word < (raiz)->data)
        return procura(raiz->esq, word);

    else if (*word > (raiz)->data)
        return procura(raiz->dir, word);

    else
    {
        if (*(word+1) == '\0')
            return raiz->flag;

        return procura(raiz->eq, word+1);
    }

}
 
 //apenas apague o flag
 void remover_palavra(apontador *raiz, char *word)
 {
    if (!(*raiz))
        return;

    if (*word < (*raiz)->data)
        remover_palavra(&((*raiz)->esq), word);

    else if (*word > (*raiz)->data)
        remover_palavra(&((*raiz)->dir), word);

    else
    {
        if (*(word+1) == '\0')
            (*raiz)->flag = 0;

        else
            remover_palavra(&((*raiz)->eq), word+1);
    }
 }

int main(){
    apontador raiz;
       
    IniciaArvore(&raiz);
    insere(&raiz, "leao", 1);
    insere(&raiz, "elefante", 2);
    insere(&raiz, "zebra", 3);
    insere(&raiz, "pato", 4);
    insere(&raiz, "gato", 5);
    insere(&raiz, "cachorro", 6);
    insere(&raiz, "vaca", 7);
    insere(&raiz, "cavalo", 8);
    insere(&raiz, "tigre", 9);
    insere(&raiz, "macaco", 10);
    insere(&raiz, "loro", 11);
    printf("\nPercorrendo a arvore:\n\n");
    percorre_TST(raiz);
    printf("\n\nDeseja procurar alguma palavra? S|N\n");
    char resp;
    scanf(" %c", &resp);
    if(resp == 'S'){
        char palavra[MAX];
        printf("Digite a palavra:\n");
        scanf(" %s", palavra);
        if(procura(raiz, palavra))
            printf("A palavra %s foi encontrada\n", palavra);
        else
            printf("A palavra %s nao foi encontrada\n", palavra);
    }
    getchar();
    printf("\n\nDeseja remover alguma palavra? S|N\n");
    scanf(" %c", &resp);
    if(resp == 'S'){
        char palavra[MAX];
        printf("Digite a palavra:\n");
        scanf(" %s", palavra);
        if (procura(raiz, palavra)){
            remover_palavra(&raiz, palavra);
            printf("A palavra %s foi removida\n", palavra);
        }
        else
            printf("A palavra %s nao foi encontrada\n", palavra);
    }
    puts ("\nPercorrendo a arvore:\n\n");
    percorre_TST(raiz);
    return 0;
}



