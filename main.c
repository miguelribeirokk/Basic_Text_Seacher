//Implementado por:
//Miguel Antonio Ribeiro e Silva - 4680
//Alan Gabriel Martins Silva - 4663
//Vinicius Alves Gontijo - 4708
//Gabriel Ryan -
#include "stdio.h"
#include "stdlib.h"
#include "string.h"

#include "tads/patricia.h"
#include "tads/linked_list.h"
#include "funcoes.h"
#include "cores/cores.h"


int main(void){
    No_Patricia *no;
    Lista_Encadeada *lista, *lista_aux;
    int fim, palavras, contador = 0, Numero_Arquivos = 0, opcao = 0;
    char *nome_arquivo = (char *)malloc(sizeof(char));
    char *palavra = (char*)malloc(sizeof(char));
    char nome[100];
    system("clear");
    printf("BEM VINDO AO NOSSO ALGORITMO DE BUSCA!\n");
    printf("Pressione ENTER para continuar...\n");
    getchar();
    while (opcao != 5){
        if (opcao == 0){
            system("clear");
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
            FILE *arquivo = NULL; 
            Numero_Arquivos = 0;
            Free_Patricia(&no); //Limpa a memoria
            printf("Digite o nome do arquivo: ");
            scanf("%s", nome_arquivo);
            flush_in();
            arquivo = fopen(nome_arquivo, "r");
            if (arquivo == NULL){
                printf("\nErro ao abrir o arquivo\n");
                printf("\nDigite 1 para abrir um arquivo ou 0 pra voltar ao menu: ");
                scanf("%d", &opcao);
                flush_in();
                continue;
            }
            printf("\nArquivo aberto com sucesso\n");
            Inicializa(&no); //Inicializa a arvore
            Inicializa_Lista(&lista); //Inicializa a lista
            while(!feof(arquivo)){
                fim = fscanf(arquivo, "%s", nome); //Le os nomes dos arquivos
                if (fim == EOF){
                    break;
                }
                Abrir_Arquivo(nome, &no, Numero_Arquivos); //Abre os arquivos e insere as palavras na arvore e na tabela hash
                Numero_Arquivos++;
            }
                fclose(arquivo);
                printf("Palavras inseridas com sucesso\n\n");
                printf("Digite uma nova opcao ou 0 pra voltar ao menu: ");
                scanf("%d", &opcao);
                flush_in();
                continue;
        }
        if (opcao == 2){
            if (Numero_Arquivos == 0){
                printf("Nao ha arquivos abertos\n");
                printf("Digite 1 para abrir um arquivo ou 0 pra voltar ao menu: ");
                scanf("%d", &opcao);
                flush_in();
                continue;
            }
            Printar_Palavra(&no); //Imprime as palavras da arvore em ordem alfabetica
            printf("Pressione enter para continuar");
            getchar();
            printf("\nDigite uma nova opcao ou 0 pra voltar ao menu: ");
            scanf("%d", &opcao);
            flush_in();
            continue;
            
        }
        if (opcao == 3){
            if (Numero_Arquivos == 0){
                printf("Nao ha arquivos abertos\n");
                printf("Digite 1 para abrir um arquivo ou 0 pra voltar ao menu: ");
                scanf("%d", &opcao);
                flush_in();
                continue;
            }
            Printar_Ocorrencias(&no); //Imprime o indice invertido da arvore Patricia
            printf("Pressione enter para continuar\n");
            getchar();
            printf("Digite uma nova opcao ou 0 pra voltar ao menu: ");
            scanf("%d", &opcao);
            flush_in();
            continue;
        }
        if (opcao == 4){
            if (Numero_Arquivos == 0){
                printf("Nao ha arquivos abertos\n");
                printf("Digite 1 para abrir um arquivo ou 0 pra voltar ao menu: ");
                scanf("%d", &opcao);
                flush_in();
                continue;
            }
            printf("\nDeseja pesquisar quantas palavras? ");
            scanf ("%d", &palavras);
            float ** matriz = Fazer_Matriz(Numero_Arquivos, palavras); //Cria a matriz de pesos
            flush_in();
            contador = 0;
            for (int i = 0; i < palavras; i++){
                printf("\nDigite a palavra %d: ", i+1);
                scanf("%s", palavra);
                flush_in();
                lista = Buscar_Palavra(&no, palavra); //Busca a palavra na arvore Patricia, retornando sua lista de indices
                lista_aux = lista;
                if (lista == NULL) printf("\tPalavra nao encontrada!\n");
                else printf("Palavra encontrada!\n");
                Retorna_Peso(&lista_aux,  Numero_Arquivos, contador, matriz); //Calcula o peso de cada palavra em cada arquivo e coloca na matriz
                contador+=1;
             }
             printf("\nMatriz de pesos:\n");
            for (int i = 0; i < palavras; i++){
                for (int j = 0; j < Numero_Arquivos-1; j++){
                    printf("%2f ", matriz[i][j]);
                }
                printf("\n");
            }
            free(matriz); 
            printf("\nPressione enter para continuar"); 
            getchar();  
            printf("Digite uma nova opcao ou 0 pra voltar ao menu: ");
            scanf("%d", &opcao);
            flush_in();
            continue;
        }
        else{
            printf("\nOpcao invalida\n");
            printf("Digite uma nova opcao ou 0 pra voltar ao menu: ");
            scanf("%d", &opcao);
            flush_in();
            continue;
        }
    }
    printf("Saindo do programa\n");
    printf("Obrigado por usar o programa!\n");
    Free_Patricia(&no); //Limpa a memoria
    return 0;
}
