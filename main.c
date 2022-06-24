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
#include "tads/hashAssets.h"
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
    Green();
    printf("BEM VINDO AO NOSSO ALGORITMO DE BUSCA!\n");
    White();
    printf("Pressione ENTER para continuar...\n");
    getchar();
    while (opcao != 5){
        if (opcao == 0){
            system("clear");
            printf("\n");
            White();
            printf("1 - Abrir arquivo e inserir palavras\n");
            printf("2 - Imprimir palavras \n");
            printf("3 - Imprimir indice invertido\n");
            printf("4 - Buscar palavra\n");
            printf("5 - Sair\n");
            printf("\n");
            Pink();
            printf("Digite a opcao desejada: ");
            White();
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
                Red();
                printf("\nErro ao abrir o arquivo\n");
                Pink();
                printf("\nDigite 1 para abrir um arquivo ou 0 pra voltar ao menu: ");
                White();
                scanf("%d", &opcao);
                flush_in();
                continue;
            }
            Green();
            printf("\nArquivo aberto com sucesso\n");
            White();
            Inicializa(&no); //Inicializa a arvore
            Inicializa_Lista(&lista); //Inicializa a lista
            hashTable *ht = iniciaTabela(17);
            while(!feof(arquivo)){
                fim = fscanf(arquivo, "%s", nome); //Le os nomes dos arquivos
                if (fim == EOF){
                    break;
                }
               Abrir_Arquivo(nome, &no, Numero_Arquivos); //Abre os arquivos
                Numero_Arquivos++;
            }
                fclose(arquivo);
                Green();
                printf("Palavras inseridas com sucesso\n\n");
                Pink();
                printf("Digite uma nova opcao ou 0 pra voltar ao menu: ");
                White();
                scanf("%d", &opcao);
                flush_in();
                continue;
        }
        if (opcao == 2){
            if (Numero_Arquivos == 0){
                Red();
                printf("\nNao ha arquivos abertos\n\n");
                Pink();
                printf("Digite 1 para abrir um arquivo ou 0 pra voltar ao menu: ");
                scanf("%d", &opcao);
                flush_in();
                continue;
            }
            Printar_Palavra(&no); //Imprime as palavras da arvore em ordem alfabetica
            Pink();
            printf("Pressione enter para continuar");
            getchar();
            Pink();
            printf("\nDigite uma nova opcao ou 0 pra voltar ao menu: ");
            White();
            scanf("%d", &opcao);
            flush_in();
            continue;
            
        }
        if (opcao == 3){
            if (Numero_Arquivos == 0){
                Red();
                printf("\nNao ha arquivos abertos\n\n");
                Pink();
                printf("Digite 1 para abrir um arquivo ou 0 pra voltar ao menu: ");
                White();
                scanf("%d", &opcao);
                flush_in();
                continue;
            }
            Printar_Ocorrencias(&no); //Imprime o indice invertido da arvore Patricia
            Pink();
            printf("Pressione enter para continuar\n");
            getchar();
            Pink();
            printf("Digite uma nova opcao ou 0 pra voltar ao menu: ");
            White();
            scanf("%d", &opcao);
            flush_in();
            continue;
        }
        if (opcao == 4){
            if (Numero_Arquivos == 0){
                Red();
                printf("\nNao ha arquivos abertos\n\n");
                Pink();
                printf("Digite 1 para abrir um arquivo ou 0 pra voltar ao menu: ");
                White();
                scanf("%d", &opcao);
                flush_in();
                continue;
            }
            Pink();
            printf("\nDeseja pesquisar quantas palavras? ");
            White();
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
                if (lista == NULL){
                    Red();
                    printf("Palavra nao encontrada!\n");
                    White();
                }
                else{
                    Green();
                    printf("Palavra encontrada!\n");
                    White();
                }
                Retorna_Peso(&lista_aux,  Numero_Arquivos, contador, matriz); //Calcula o peso de cada palavra em cada arquivo e coloca na matriz
                contador+=1;
             }
             printf("\nMatriz de pesos:\n");
            for (int i = 0; i < palavras; i++){
                for (int j = 0; j < Numero_Arquivos-1; j++){
                    printf("%.2f ", matriz[i][j]);
                }
                printf("\n");
            }
            Pink();
            printf("\nPressione enter para continuar"); 
            getchar(); 
            White(); 
            printf("Digite uma nova opcao ou 0 pra voltar ao menu: ");
            scanf("%d", &opcao);
            flush_in();
            continue;
        }
        else{
            Red();
            printf("\nOpcao invalida\n");
            Pink();
            printf("Digite uma nova opcao ou 0 pra voltar ao menu: ");
            scanf("%d", &opcao);
            flush_in();
            continue;
        }
    }
    Green();
    printf("\n\nSaindo do programa\n");
    printf("Obrigado por usar o programa!\n\n\n");
    White();
    Free_Patricia(&no); //Limpa a memoria da patricia e das listas
    return 0;
}
