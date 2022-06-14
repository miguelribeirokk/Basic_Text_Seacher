#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "conio.h"

#include "tads/patricia.h"
#include "tads/lista_patricia.h"
#include "abrir_arquivo.h"
#include "cores/cores.h"





int main(void){

    No_Patricia *no;
    Lista_Encadeada *lista;
    FILE* valor;
    int valor_2 = 0;
    int Numero_Arquivos = 0;
    char numero[100];
    char nome[100];
    char arquivo[100];
    int opcao = 0;
    int opcao2;
    
    while (opcao != 5){
        if (opcao == 0){
            Pink();
            printf("\n\nBem vindo ao nosso algoritmo de pesquisa!\n");
            White();
            Green();
            printf("Digite a opcao desejada:\n");
            White();
            printf("   1 - Ler arquivo e inicializar as estruturas\n");
            printf("   2 - Construir o indice invertido\n");
            printf("   3 - Imprimir o indice invertido\n");
            printf("   4 - Pesquisar palavras\n");
            printf("   5 - Sair\n");
            scanf("%d", &opcao);
            setbuf(stdin, NULL);
        }
        else if (opcao == 1){
            Green();
            printf("Digite o nome do arquivo:\n");
            White();
            scanf("%s", nome);
            setbuf(stdin, NULL);
            valor = Ler_Arquivo(nome);
            
            if (valor == NULL){
                Red();
                printf("Erro!\n\n");
                White();
                printf("Digite novamente a opcao 1 ou 0 para voltar ao menu.\n");
                scanf("%d", &opcao);
                setbuf(stdin, NULL);    
            }
            else{
                Pink();
                printf("Arquivo aberto com sucesso!\n\n");
                Green();
                printf ("Pressione Enter para continuar.\n");
                White();
                getchar();
                printf("Digite a opcao desejada ou 0 para voltar ao menu.\n");
                scanf("%d", &opcao);
                setbuf(stdin, NULL);
            }
        }  
        else if (opcao == 2){
            if(valor == NULL){
                Red();
                printf("Erro! Arquivo ainda nao foi aberto!\n\n");
                White();
                printf("Digite a opcao desejada ou 0 para voltar ao menu.\n");
                scanf("%d", &opcao);
                setbuf(stdin, NULL);
            }

            else{
                Pink();
                printf("Construindo o indice invertido...\n");
                White();
                fgets(numero, 2, valor);
                printf ("%s\n", numero);
                
                

                /*Green();
                printf("Indice construido!");
                printf("\n\nPressione Enter para continuar.\n");
                getchar();
                printf("Digite a opcao desejada ou 0 para voltar ao menu.\n");
                scanf("%d", &opcao);*/
        }
        /*else if (opcao == 3){
            if(valor == 0 || valor_2 == 0){
                Red();
                printf("Erro! Arquivo ainda nao foi aberto ou indice nao construido!\n\n");
                White();
                printf("Digite a opcao desejada ou 0 para voltar ao menu.\n");
                scanf("%d", &opcao);
                setbuf(stdin, NULL);
            }
            else{
                Pink();
                printf("Imprimindo o indice invertido...\n");
                Printar_Palavra(&no);
                Printar_Ocorrencias(&no);
                Green();
                printf("Indice impresso!");
                printf("\n\nPressione Enter para continuar.\n");
                getchar();
                printf("Digite a opcao desejada ou 0 para voltar ao menu.\n");
                scanf("%d", &opcao);
            }*/

        
        
        
        
        
        else{
            Red();
            printf("Opcao invalida\n");
            Green();
            printf("Digite a opcao desejada ou 0 para voltar ao menu.\n");
            scanf("%d", &opcao);
            setbuf(stdin, NULL);
        }

            
            

            
}}


