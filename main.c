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
    int fim, palavras, contador = 0, Numero_Arquivos = 0, opcao = 0;
    char *nome_arquivo = (char *)malloc(sizeof(char));
    char *palavra = (char*)malloc(sizeof(char));
    char nome[100];
    while (opcao != 5){
        if (opcao == 0){
            printf("\n");
            printf("1 - Abrir arquivo e inserir palavras\n");
            printf("2 - Imprimir palavras \n");
            printf("3 - Imprimir indice invertido\n");
            printf("4 - Buscar palavra\n");
            printf("5 - Sair\n");
            printf("\n");
            printf("Digite a opcao desejada: ");
            scanf("%d", &opcao);
            flush_in();
            continue;
        }
        if (opcao == 1){
            if (Numero_Arquivos != 0){
                printf("\tVoce ja abriu um arquivo\n");
                printf("Digite uma nova opcao ou 0 para voltar: ");
                scanf("%d", &opcao);
                flush_in();
                continue;
                
            }
            printf("Digite o nome do arquivo: ");
            scanf("%s", nome_arquivo);
            flush_in();
            FILE *arquivo = fopen(nome_arquivo, "r");
            if (arquivo == NULL){
                printf("\tErro ao abrir o arquivo");
                printf("\nDigite uma nova opcao ou 0 pra voltar ao menu: ");
                scanf("%d", &opcao);
                flush_in();
                continue;
            }
            printf("\tArquivo aberto com sucesso\n");
            while(!feof(arquivo)){
                fim = fscanf(arquivo, "%s", nome);
                if (fim == EOF){
                    break;
                }
                Abrir_Arquivo(nome, &no, Numero_Arquivos);
                Numero_Arquivos++;
            }
                fclose(arquivo);
                printf("\tPalavras inseridas com sucesso\n");
                printf("Digite uma nova opcao ou 0 pra voltar ao menu: ");
                scanf("%d", &opcao);
                flush_in();
                continue;
        }
        if (opcao == 2){
            if (Numero_Arquivos == 0){
                printf("\tNao ha arquivos abertos\n");
                printf("Digite uma nova opcao ou 0pra voltar ao menu: ");
                scanf("%d", &opcao);
                flush_in();
                continue;
            }
            Printar_Palavra(&no);
            printf("\tPressione enter para continuar");
            getchar();
            printf("Digite uma nova opcao ou 0 pra voltar ao menu: ");
            scanf("%d", &opcao);
            flush_in();
            continue;
            
        }
        if (opcao == 3){
            if (Numero_Arquivos == 0){
                printf("\tNao ha arquivos abertos\n");
                printf("Digite uma nova opcao ou 0pra voltar ao menu: ");
                scanf("%d", &opcao);
                flush_in();
                continue;
            }
            Printar_Ocorrencias(&no);
            printf("\tPressione enter para continuar\n");
            getchar();
            printf("Digite uma nova opcao ou 0 pra voltar ao menu: ");
            scanf("%d", &opcao);
            flush_in();
            continue;
        }
        if (opcao == 4){
            if (Numero_Arquivos == 0){
                printf("\tNao ha arquivos abertos\n");
                printf("Digite uma nova opcao ou 0 pra voltar ao menu: ");
                scanf("%d", &opcao);
                flush_in();
                continue;
            }
            printf("\nDeseja pesquisar quantas palavras? ");
            scanf ("%d", &palavras);
            float ** matriz = Fazer_Matriz(Numero_Arquivos, palavras);
            flush_in();
            contador = 0;
            for (int i = 0; i < palavras; i++){
                printf("\n\tDigite a palavra %d: ", i+1);
                scanf("%s", palavra);
                flush_in();
                lista = Buscar_Palavra(&no, palavra);
                lista_aux = lista;
                if (lista == NULL) printf("\tPalavra nao encontrada!\n");
                else printf("\tPalavra encontrada!\n");
                Retorna_Peso(&lista_aux,  Numero_Arquivos, contador, matriz);
                contador+=1;
             }
             printf("\nMatriz de pesos:\n");
            for (int i = 0; i < palavras; i++){
                for (int j = 0; j < Numero_Arquivos-1; j++){
                    printf("%2f ", matriz[i][j]);
                }
                printf("\n");
            }
             
            printf("\n\tPressione enter para continuar"); 
            getchar();  
            printf("Digite uma nova opcao ou 0 pra voltar ao menu: ");
            scanf("%d", &opcao);
            flush_in();
            continue;
        }
        if (opcao == 5){
            printf("Saindo do programa\n");
            break;
        }
        else{
            printf("\tOpcao invalida\n");
            printf("Digite uma nova opcao ou 0 pra voltar ao menu: ");
            scanf("%d", &opcao);
            flush_in();
            continue;
        }
    }
    return 0;
}
