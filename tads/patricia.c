//Implementado por:
//Miguel Antonio Ribeiro e Silva - 4680
//Alan Gabriel Martins Silva - 4663
//Vinicius Alves Gontijo - 4708
//Gabriel Ryan -
#include "patricia.h"


int Inicializa(No_Patricia **no) { //Inicializa a arvore
  (*no) = NULL;
  return 1;
} 


int Externo(No_Patricia **no) { //Funcao que verifica se o nó é externo
  if ((**no).TipoNo == externo) return 1;
    return 0;
}


int Confere(No_Patricia **no, char *palavra){ //Confere se é maior ou menor
    if(strlen(palavra) < (**no).No.interno.posicao) return 0; //Verifica se a palavra é menor que o tamanho do no
    if (palavra[(**no).No.interno.posicao] >= (**no).No.interno.caractere) return 1; //Se for maior, retorna 1
  return 0;
} 


int Cria_No_Externo(No_Patricia **no, char *palavra, int arquivo) { //Cria nó externo
  int tamanho = 1;
  while ((palavra[tamanho]) != '\0') tamanho++;
  (*no) = malloc(sizeof(No_Patricia));
  if (*no == NULL) return 0;
  (**no).TipoNo = externo;
  (**no).No.externo.palavra = malloc(tamanho * sizeof(char));
  if ((**no).No.externo.palavra == NULL) return 0;
  strcpy((**no).No.externo.palavra, palavra); //Copia a palavra para o nó
  (**no).No.externo.lista = NULL;
  LE_Criar_No(&((**no).No.externo.lista), arquivo); //Cria nó na lista encadeada
  return 1;
} 

int Cria_No_Interno(No_Patricia **no, char caractere, int posicao, No_Patricia **esq, No_Patricia **dir) {
  (*no) = malloc(sizeof(No_Patricia)); //Cria nó interno
  if ((*no) == NULL) return 0;
  (**no).TipoNo = interno;
  (**no).No.interno.caractere = caractere;
  (**no).No.interno.posicao = posicao;
  (**no).No.interno.esq = *esq;
  (**no).No.interno.dir = *dir;
  return 1;
}

  int No_Diferente(No_Patricia **no, char *palavra){ 
    int posicao = 0;
    while((((**no).No.externo.palavra)[posicao]) == (palavra[posicao])){ 
      //Verifica quando a palavra se difere, comparando os caracteres
        if((((**no).No.externo.palavra)[posicao]) == '\0' && (palavra[posicao]) == '\0'){
            return -1;
        }
    posicao++;
    }
  return posicao; //Retorna a posicao onde se diferem
  }

int Retornar_Posicao(No_Patricia **no){ 
  //Retorna a posição do caractere
  if((**no).TipoNo == externo) return 0;
  return ((**no)).No.interno.posicao;
}
char Retornar_Caractere(No_Patricia **no, int posicao){
  //Retorna o caractere na posição
    if ((**no).TipoNo == externo) return (((**no).No.externo.palavra)[posicao]);
    return ((**no)).No.interno.caractere;
}

int Insere_Entre(No_Patricia **no, char *palavra, int posicao, char caractere, int filename){
  //Insere entre dois nós
    No_Patricia *No_Criado = NULL, *Troca = *no;
    char Palavra_No_Interno;
    if(Externo(no)){
      Cria_No_Externo(&No_Criado, palavra, filename); //Cria no externo
      Palavra_No_Interno = Retornar_Caractere(no, posicao); //Retorna caractere
      if(palavra[posicao] > Palavra_No_Interno){ 
          return Cria_No_Interno(no, palavra[posicao], posicao, &Troca, &No_Criado); //Se a palavra é maior, retorna no interno
      }
      else{
          return Cria_No_Interno(no, Palavra_No_Interno, posicao, &No_Criado, &Troca); //Se a palavra é menor, retorna no interno
      }
    }
  if(posicao < (**no).No.interno.posicao){ //
    Cria_No_Externo(&No_Criado, palavra, filename); 
    Palavra_No_Interno = Retornar_Caractere(no, posicao); 
    if (palavra[posicao] >= caractere) {
      return Cria_No_Interno(no, caractere, posicao, &Troca, &No_Criado); 
    }
    else{
      return Cria_No_Interno(no, caractere, posicao, &No_Criado, &Troca); 
    }
  }
   if (posicao == (**no).No.interno.posicao && palavra[posicao] > Retornar_Caractere(no, posicao)) { 
    //Posicao igual e palavra maior que o caractere da posicao
    Cria_No_Externo(&No_Criado, palavra, filename);  //Cria no externo
    Palavra_No_Interno = Retornar_Caractere(no, posicao); //Retorna caractere
  
    if (palavra[posicao] > Palavra_No_Interno) {
      return Cria_No_Interno(no, palavra[posicao], posicao, &Troca, &No_Criado); //Se a palavra é maior, retorna na cria no interno com a palavra[posicao]
    }
    else{
      return Cria_No_Interno(no, Palavra_No_Interno, posicao, &No_Criado, &Troca); //Se a palavra é menor, retorna cria no interno com Palavra_No_Interno
    }
   }
   if(Confere(no, palavra)){
    //Confere se é maior ou menor
    return Insere_Entre(&((**no).No.interno.dir), palavra, posicao, caractere, filename);
   }
   else{
    return Insere_Entre(&((**no).No.interno.esq), palavra, posicao, caractere, filename);
   }
   return 0;
}

int Incrementa_Ocorrencias(No_Patricia **no, int filename){
    if((**no).TipoNo == interno){
        return 0; //Se for interno, não incrementa ocorrencia
    }
    
    return LE_Insere_No(&((**no).No.externo.lista), filename);
     //Se for externo, incrementa ocorrencia, pois a palavra já existe
}

int Insere_Palavra(No_Patricia **no, char *palavra, int filename){
    int Posicao_Diferente;
    No_Patricia **No_Auxiliar = no;
    char caractere;
    if((*no) == NULL){
         return Cria_No_Externo(no, palavra, filename); //Cria no externo, se não existir nenhum nó
    }
    while (!Externo(No_Auxiliar)) { //Enquanto não for externo
      if(Confere(No_Auxiliar, palavra)){
        No_Auxiliar = &((**No_Auxiliar).No.interno.dir); //Se a palavra é maior, No auxiliar recebe o direito
      }
      else{
        No_Auxiliar = &((**No_Auxiliar).No.interno.esq); //Se a palavra é menor, No auxiliar recebe o esquerdo
      }
    }
    Posicao_Diferente = No_Diferente(No_Auxiliar, palavra); //Retorna a posicao onde se diferem
    if(Posicao_Diferente == -1){
        return Incrementa_Ocorrencias(No_Auxiliar, filename); //Se a palavra é igual, incrementa ocorrencia
    }
    if (palavra[Posicao_Diferente] > ((**No_Auxiliar).No.externo.palavra)[Posicao_Diferente]) {
      caractere = palavra[Posicao_Diferente];  //Se a palavra é maior, caractere recebe a palavra[Posicao_Diferente]
    }
    else{
      caractere = ((**No_Auxiliar).No.externo.palavra)[Posicao_Diferente]; //Pega o caractere da palavra
    }
    return Insere_Entre(no, palavra, Posicao_Diferente, caractere, filename); //Insere na posição correta, passando o caractere
}

int Printar_Palavra(No_Patricia **no){
  if ((**no).TipoNo == externo) {
    printf("%s\n", (**no).No.externo.palavra);
    return 1;
  }
  Printar_Palavra(&((**no).No.interno.esq));
  Printar_Palavra(&((**no).No.interno.dir));
  return 1;
}

int Printar_Ocorrencias(No_Patricia **no){
  if ((**no).TipoNo == externo) {
    printf("%s - ", (**no).No.externo.palavra);
    LE_Printa_Lista(&((**no).No.externo.lista));
    printf("\n");
    return 1;
  }
  Printar_Ocorrencias(&((**no).No.interno.esq));
  Printar_Ocorrencias(&((**no).No.interno.dir));
  return 1;
}

Lista_Encadeada *Buscar_Palavra(No_Patricia **no, char *palavra){
  if ((*no) != NULL) {
    if((**no).TipoNo == interno){
      if ((**no).No.interno.caractere <= palavra[(**no).No.interno.posicao]) {
        return Buscar_Palavra(&(**no).No.interno.dir, palavra); // Se a palavra é maior, busca na direita
      }
      else {
        return Buscar_Palavra(&(**no).No.interno.esq, palavra); // Se a palavra é menor, busca na esquerda
      }
    }
    else{
      if(!strcmp((**no).No.externo.palavra, palavra)){
        return ((**no).No.externo.lista); //Se a palavra é igual, retorna a lista
      }
    }
  }
  return NULL;
}

int Free_Patricia(No_Patricia **no){
  if(*no != NULL){
    if(Externo(no)){
      Free_Lista(&(**no).No.externo.lista); //Remove ocorrencia
    }
    else{
      Free_Patricia(&((**no).No.interno.esq)); //Remove da esquerda
      Free_Patricia(&((**no).No.interno.dir)); //Remove da direita 
    }
    free (*no);
    (*no) = NULL;
    return 0;
  }
}