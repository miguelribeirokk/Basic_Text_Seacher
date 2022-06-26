//Implementado por:
//Miguel Antonio Ribeiro e Silva - 4680
//Alan Gabriel Martins Silva - 4663
//Vinicius Alves Gontijo - 4708
//Gabriel Ryan -
#include "tads/hashAssets.h"
#include "funcoes.h"
#include "tads/bst.h"
#define TAM 17



int main(void){
    No_Patricia *no;
    Lista_Encadeada *lista_pat, *lista_aux_pat;
    Lista_Encadeada **lista_hash, **lista_aux_hash;
    hashTable *ht;
    ht = iniciaTabela(TAM); 
    Inicializa_Patricia(&no);
    int palavras, contador = 0, Numero_Arquivos = 0, opcao = 0, numero = 0;
    float soma;
    char *nome_arquivo = (char *)malloc(sizeof(char));
    char *palavra = (char*)malloc(sizeof(char));
    char *nome = (char *)malloc(sizeof(char));
    system("clear");
    Green(); printf("BEM VINDO AO NOSSO ALGORITMO DE BUSCA!\n");
    White(); printf("Pressione ENTER para continuar...\n");
    getchar();
    while (opcao != 5){
        if (opcao == 0){
            system("clear"); 
            White();
            printf("\n1 - Abrir arquivo e inserir palavras\n");
            printf("2 - Imprimir todas as palavras em ordem alfabetica\n");
            printf("3 - Imprimir indice invertido\n");
            printf("4 - Buscar palavra e retornar a relevancia\n");
            printf("5 - Sair\n");
            Pink(); printf("\nDigite a opcao desejada: ");
            White(); scanf("%d", &opcao);
            flush_in();
            continue;
        }
        if (opcao == 1){
            FILE *arquivo = NULL;
            if(Numero_Arquivos != 0) {
                Red(); printf("Voce ja abriu um arquivo!\n\n");
                Pink(); printf("Para abrir outro arquivo, encerre o programa e execute novamente.\n");
                White(); printf("Digite outra opcao ou 5 para encerrar: ");
                scanf("%d", &opcao);
                flush_in();
                continue;
            }
            printf("Digite o nome do arquivo: ");
            scanf("%s", nome_arquivo);
            flush_in();
            arquivo = fopen(nome_arquivo, "r");
            if (arquivo == NULL){
                Red(); printf("\nErro ao abrir o arquivo\n");
                Pink(); printf("\nDigite 1 para abrir um arquivo ou 0 pra voltar ao menu: ");
                White(); scanf("%d", &opcao);
                flush_in();
                continue;
            }
            Green(); printf("\nArquivo aberto com sucesso\n");
            White(); fscanf(arquivo, "%d", &Numero_Arquivos);
            for (int i = 0; i < Numero_Arquivos; i++) {
                fscanf(arquivo, "%s", nome);
                numero += 1;
                printf("%s\n", nome);
                Abrir_Arquivo(nome, &no, ht, numero);
            }
                fclose(arquivo);
                Green(); printf("Palavras inseridas com sucesso\n\n");
                Pink(); printf("Digite uma nova opcao ou 0 pra voltar ao menu: ");
                White(); scanf("%d", &opcao);
                flush_in();
                continue;
        }
        if (opcao == 2){
            if (Numero_Arquivos == 0){
                Red(); printf("\nNao ha arquivos abertos\n\n");
                Pink(); printf("Digite 1 para abrir um arquivo ou 0 pra voltar ao menu: ");
                White(); scanf("%d", &opcao);
                flush_in();
                continue;
            }
            printf("Da Patricia ou da Hash?\n");
            printf("1 - Patricia\n");
            printf("2 - Hash\n");
            scanf("%d", &opcao);
            flush_in();
            if (opcao == 1) Printar_Palavra(&no);
            if (opcao == 2) printaPalavras_Hash(ht); 
            if (opcao != 1 && opcao != 2){
                    Red();
                    printf("Opcao invalida\n");
                    White();
            }
            Pink(); printf("Pressione enter para continuar");
            getchar();
            printf("\nDigite uma nova opcao ou 0 pra voltar ao menu: ");
            White(); scanf("%d", &opcao);
            flush_in();
            continue;

        }
        if (opcao == 3){
            if (Numero_Arquivos == 0){
                Red();  printf("\nNao ha arquivos abertos\n\n");
                Pink(); printf("Digite 1 para abrir um arquivo ou 0 pra voltar ao menu: ");
                White(); scanf("%d", &opcao);
                flush_in();
                continue;
            }
            printf("Da Patricia ou da Hash?\n");
            printf("1 - Patricia\n");
            printf("2 - Hash\n");
            scanf("%d", &opcao);
            flush_in();
            if (opcao == 1) Printar_Ocorrencias(&no);
            if (opcao == 2) printaTabela(ht);
            if (opcao != 1 && opcao != 2){
                    Red(); printf("Opcao invalida\n"); White();
            }
            Pink(); printf("Pressione enter para continuar"); 
            getchar();
            printf("\nDigite uma nova opcao ou 0 pra voltar ao menu: "); White();
            scanf("%d", &opcao);
            flush_in();
            continue;
        }
        
        if (opcao == 4){
            if (Numero_Arquivos == 0){
                Red(); printf("\nNao ha arquivos abertos\n\n");
                Pink(); printf("Digite 1 para abrir um arquivo ou 0 pra voltar ao menu: ");
                White(); scanf("%d", &opcao);
                flush_in();
                continue;
            }
            Pink(); printf("\nDeseja pesquisar quantas palavras? ");
            White(); scanf ("%d", &palavras);
            printf("Na Patricia ou na Hash? \n");
            printf("1 - Patricia\n");
            printf("2 - Hash\n");
            scanf("%d", &opcao);
            flush_in();

            //Alocando espaços para o calculo da relevancia
            //*****************************************************************//
            float ** mat = malloc((sizeof (float *) * palavras));
            float *buf = malloc((sizeof (float) * palavras * Numero_Arquivos));
            int *quantidade = malloc((sizeof (int) * Numero_Arquivos));
            float *relevancia = malloc((sizeof (float) * Numero_Arquivos));
            float *ordenado = malloc((sizeof (int) * Numero_Arquivos));
            for (int i = 0; i < palavras; i++) mat[i] = &buf[i*Numero_Arquivos];
            for (int i = 0; i < palavras; i++){
                for (int j = 0; j < Numero_Arquivos; j++){
                    mat[i][j] = 0;
                }
            }
            //******************************************************************//
            
            if(opcao == 1){
                contador = 0;
                for (int i = 0; i < palavras; i++) {
                    printf("\nDigite a palavra %d: ", i+1);
                    scanf("%s", palavra); 
                    flush_in();
                    lista_pat = Buscar_Palavra(&no, palavra); 
                    lista_aux_pat = lista_pat;
                    if (lista_pat== NULL){
                        Red(); printf("Palavra nao encontrada!\n"); White();
                    }
                    else{
                        Green(); printf("Palavra encontrada!\n"); White();
                        //Retorna o peso de cada arquivo
                        Retorna_Peso(&lista_aux_pat, Numero_Arquivos, contador, mat);
                    }
                    contador+=1; 
                }
            }
            if(opcao == 2){
                contador = 0;
                for (int i = 0; i < palavras; i++){
                    printf("\nDigite a palavra %d: ", i+1);
                    scanf("%s", palavra);
                    flush_in();
                    lista_hash = procurarNaTabela(ht, palavra); //Busca a palavra na Hash
                    lista_aux_hash = lista_hash;
                    if (lista_hash== NULL){
                        Red(); printf("Palavra nao encontrada!\n"); White();
                    }
                    else{
                        Green(); printf("Palavra encontrada!\n"); White();
                         //Retorna o peso de cada arquivo
                        Retorna_Peso(lista_aux_hash, Numero_Arquivos, contador, mat); 
                    }
                    contador+=1;
                }
            }
            if (opcao != 1 && opcao != 2){
                    Red(); printf("Opcao invalida\n"); White();
            }
            quantidade = Quantidade_Palavras_Hash(quantidade, Numero_Arquivos, ht);
            printf ("\nQuantidade de palavras por arquivo:\n");
            for (int i = 0; i < Numero_Arquivos; i++){
                printf("Arquivo %d: %d\n", i+1, quantidade[i]);
            }
            
            /*quantidade = Quantidade_Palavras_PAT(quantidade, Numero_Arquivos, &no);
            printf ("\nQuantidade de palavras por arquivo:\n");
            for (int i = 0; i < Numero_Arquivos; i++){
                printf("Arquivo %d: %d\n", i+1, quantidade[i]);
            }*/

            relevancia = Relevancia(relevancia, Numero_Arquivos, palavras, mat, quantidade);
            Pink(); printf("\nArquivos ordenados pela relevancia:\n"); White();
            printf("Pressione Enter para ver a lista\n"); getchar();
            Printar_Ordenado(relevancia, Numero_Arquivos); 
            Pink(); printf("\nPressione enter para continuar"); getchar(); 
            White(); printf("Digite uma nova opcao ou 0 pra voltar ao menu: ");
            scanf("%d", &opcao);
            flush_in();
            free(mat); free(buf);
            free(quantidade); free(relevancia); free(ordenado); 
            continue;
        }
        else{
            Red(); printf("\nOpcao invalida\n");
            Pink(); printf("Digite uma nova opcao ou 0 pra voltar ao menu: ");
            White(); scanf("%d", &opcao);
            flush_in();
            continue;
        }
    }
    Green(); printf("\n\nSaindo do programa\n");
    printf("Obrigado por usar o programa!\n\n\n");
    Free_Patricia(&no); 
    Free_Table(ht);
    return 0;
}