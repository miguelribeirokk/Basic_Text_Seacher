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
    //Declaração de variáveis
    No_Patricia *no;
    Lista_Encadeada *lista_pat, *lista_aux_pat;
    Lista_Encadeada **lista_hash, **lista_aux_hash;
    hashTable *ht;
    int palavras, contador = 0, Numero_Arquivos = 0, opcao = 0, numero, patricia = 0, hash = 0;
    char *nome_arquivo = (char *)malloc(sizeof(char));
    char *palavra = (char*)malloc(sizeof(char));
    char *nome = (char *)malloc(sizeof(char));
    system("clear");

    Green(); printf("BEM VINDO AO NOSSO ALGORITMO DE BUSCA!\n");
    White(); printf("Pressione ENTER para continuar...\n");
    getchar();
    while (opcao != 6){
        if (opcao == 0){
            system("clear"); 
            White();
            printf("\n1 - Inserir palavras na Patricia\n");
            printf("2 - Inserir palavras na Hash\n");
            printf("3 - Imprimir todas as palavras\n");
            printf("4 - Imprimir indice invertido\n");
            printf("5 - Buscar palavra\n");
            printf("6 - Sair\n");
            Pink(); printf("\nDigite a opcao desejada: ");
            White(); scanf("%d", &opcao);
            flush_in();
            continue;
        }

        //********************************************************************************//

        if (opcao == 1){
            FILE *arquivo = NULL;
            numero = 0;
            if(patricia != 0){
                system("clear");
                Pink(); printf("\nPatricia ja foi criada!\n");
                White(); printf("Pressione ENTER para continuar...\n");
                getchar();
                opcao = 0;
                continue;
            }
            //Criação da Patricia
            Inicializa_Patricia(&no);
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

            //Percorre cada arquivo e insere na Patricia as palavras
            for (int i = 0; i < Numero_Arquivos; i++){
                fscanf(arquivo, "%s", nome); 
                numero += 1;
                Abrir_Arquivo_PAT(nome, &no, numero);
            } patricia = 1;
            fclose(arquivo);
            Pink(); printf("Palavras inseridas com sucesso!\n");
            White(); printf("\nDigite uma nova opcao ou 0 para voltar ao menu: ");
            scanf("%d", &opcao);
            flush_in();
            continue;
        }

        //********************************************************************************//

        if (opcao == 2){
            FILE *arquivo = NULL;
            numero = 0;
            if(hash != 0){
                system("clear");
                Pink(); printf("\nHash ja foi criada!\n");
                White(); printf("Pressione ENTER para continuar...\n");
                getchar();
                opcao = 0;
                continue;
            }
            //Criação da Hash
            ht = iniciaTabela(TAM);
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
            //Percorre cada arquivo e insere na Hash as palavras
            Green(); printf("\nArquivo aberto com sucesso\n");
            White(); fscanf(arquivo, "%d", &Numero_Arquivos);
            for (int i = 0; i < Numero_Arquivos; i++){
                fscanf(arquivo, "%s", nome);
                numero += 1;
                Abrir_Arquivo_HASH(nome, ht, numero);
            } hash = 1;
            fclose(arquivo);
            Pink(); printf("Palavras inseridas com sucesso!\n");
            White(); printf("\nDigite uma nova opcao ou 0 para voltar ao menu: ");
            scanf("%d", &opcao);
            flush_in();
            continue;
        }

        //********************************************************************************//

        if (opcao == 3){ 
            //Imprime todas as palavras da Patricia ou Hash inseridas em ordem alfabetica
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
            if (opcao == 1){
                if (patricia == 0){
                    Red(); printf("\nInicialize a Patricia primeiro!\n\n");
                    Pink(); printf("Digite 1 para inicializa-la ou 0 pra voltar ao menu: ");
                    White(); scanf("%d", &opcao);
                    flush_in();
                    continue;
                }
                //Imprime todas as palavras da Patricia
                Printar_Palavra(&no);
            }
            if (opcao == 2){
                if (hash == 0){
                    Red(); printf("\nInicialize a Hash primeiro!\n\n");
                    Pink(); printf("Digite 2 para inicializa-la ou 0 pra voltar ao menu: ");
                    White(); scanf("%d", &opcao);
                    flush_in();
                    continue;
                }
                //Imprime todas as palavras da Hash
                printaPalavras_Hash(ht); 
            }
            if (opcao != 1 && opcao != 2){
                    Red(); printf("Opcao invalida\n"); White();
            }
            Pink(); printf("Pressione enter para continuar");
            getchar();
            printf("\nDigite uma nova opcao ou 0 pra voltar ao menu: ");
            White(); scanf("%d", &opcao);
            flush_in();
            continue;

        }

        //********************************************************************************//

        if (opcao == 4){
            //Imprime todas o indice incertido da Patricia ou Hash
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
            if (opcao == 1){
                if (patricia == 0){
                    Red(); printf("\nInicialize a Patricia primeiro!\n\n");
                    Pink(); printf("Digite 1 para inicializa-la ou 0 pra voltar ao menu: ");
                    White(); scanf("%d", &opcao);
                    flush_in();
                    continue;
                }
                //Imprime o indice incertido da Patricia
                Printar_Ocorrencias(&no);
            }
            if (opcao == 2){
                if (hash == 0){
                    Red(); printf("\nInicialize a Hash primeiro!\n\n");
                    Pink(); printf("Digite 2 para inicializa-la ou 0 pra voltar ao menu: ");
                    White(); scanf("%d", &opcao);
                    flush_in();
                    continue;
                }
                //Imprime o indice incertido da Hash
                printaTabela(ht);
            }
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
        
        //********************************************************************************//

        if (opcao == 5){
            //Busca por termos, retornando a relevancia, dos arquivos que contenham os termos
            //Ordenados em ordem decrescente de relevancia
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
             
            //Declaração de variáveis que serão utilizadas para armazenar os pesos e relevancia
            float ** mat = malloc((sizeof (float *) * palavras));
            float *buf = malloc((sizeof (float) * palavras * Numero_Arquivos));
            int *quantidade = malloc((sizeof (int) * Numero_Arquivos));
            float *relevancia = malloc((sizeof (float) * Numero_Arquivos));
            for (int i = 0; i < palavras; i++) mat[i] = &buf[i*Numero_Arquivos];

            //Inicialiação da matriz pesos termosxNumero_Arquivos
            for (int i = 0; i < palavras; i++){
                for (int j = 0; j < Numero_Arquivos; j++){
                    mat[i][j] = 0;
                }
            }
            
            if(opcao == 1){
                if (patricia == 0){
                    Red(); printf("\nInicialize a Patricia primeiro!\n\n");
                    Pink(); printf("Digite 1 para inicializa-la ou 0 pra voltar ao menu: ");
                    White(); scanf("%d", &opcao);
                    flush_in();
                    continue;
                }
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
                        //Retorna o peso de cada arquivo e calcula a quantidade de palavras diferentes
                        //Pesos inseridos na matriz e palavras dif. caluladas usando Patricia
                        Retorna_Peso(&lista_aux_pat, Numero_Arquivos, contador, mat);
                        quantidade = Quantidade_Palavras_PAT(quantidade, Numero_Arquivos, &no);
                    }
                    contador+=1; 
                }
            }

            if(opcao == 2){
                if (hash == 0){
                    Red(); printf("\nInicialize a Hash primeiro!\n\n");
                    Pink(); printf("Digite 2 para inicializa-la ou 0 pra voltar ao menu: ");
                    White(); scanf("%d", &opcao);
                    flush_in();
                    continue;
                }
                contador = 0;
                for (int i = 0; i < palavras; i++){
                    printf("\nDigite a palavra %d: ", i+1);
                    scanf("%s", palavra);
                    flush_in();
                    lista_hash = procurarNaTabela(ht, palavra);
                    lista_aux_hash = lista_hash;
                    if (lista_hash== NULL){
                        Red(); printf("Palavra nao encontrada!\n"); White();
                    }
                    else{
                        Green(); printf("Palavra encontrada!\n"); White();
                         //Retorna o peso de cada arquivo e calcula a quantidade de palavras diferentes
                        //Pesos inseridos na matriz e palavras dif. calculadas usando a Hash
                        Retorna_Peso(lista_aux_hash, Numero_Arquivos, contador, mat);
                        quantidade = Quantidade_Palavras_Hash(quantidade, Numero_Arquivos, ht);             
                    }
                    contador+=1;
                }
            }
            if (opcao != 1 && opcao != 2){
                    Red(); printf("Opcao invalida\n"); White();
            }
            //Calcula a relevancia de cada arquivo
            relevancia = Relevancia(relevancia, Numero_Arquivos, palavras, mat, quantidade);
            Pink(); printf("\nArquivos ordenados pela relevancia:\n"); White();
            printf("Pressione Enter para ver a lista\n"); getchar();

            //Ordena usando uma árvore de busca binária e imprime os arquivos ordenados
            Printar_Ordenado(relevancia, Numero_Arquivos); 
            Pink(); printf("\nPressione enter para continuar"); getchar(); 
            White(); printf("Digite uma nova opcao ou 0 pra voltar ao menu: ");
            scanf("%d", &opcao);
            flush_in();

            //Liberação de memória alocada
            free(mat); free(buf);
            free(quantidade); free(relevancia); 
            continue;
        }

        //********************************************************************************//

        else{
            Red(); printf("\nOpcao invalida\n");
            Pink(); printf("Digite uma nova opcao ou 0 pra voltar ao menu: ");
            White(); scanf("%d", &opcao);
            flush_in();
            continue;
        }
    }

    //********************************************************************************//

    Green(); printf("\n\nSaindo do programa\n");
    printf("Obrigado por usar o programa!\n\n\n");
    //Liberação de memória alocada para Patricia e Hash
    if (patricia == 1) Free_Patricia(&no); 
    if (hash == 1) Free_Table(ht);
    return 0;
}