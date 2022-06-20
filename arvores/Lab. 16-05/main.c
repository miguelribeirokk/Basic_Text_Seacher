#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tad.h"


int main(){
    apontador no;
    IniciaArvore(&no);
    FILE *arquivo;
    char linha[100];
    arquivo = fopen("alunos.txt", "r");
    while(fgets(linha, 100, arquivo) != NULL){
        char *p;
        p = strtok(linha, "-");
        TipoAluno aluno;
        strcpy(aluno.nome, p);
        p = strtok(NULL, "-");
        aluno.matricula = atoi(p);
        p = strtok(NULL, "-");
        aluno.nota = atof(p);
        Insere(&no, aluno);
    }
    puts("\nNome - Matricula - Nota");
    puts("\nPercorrendo em ordem:");
    percorrer(no);
    puts("\nPercorrendo inversa:");
    percorrer_inversa(no);
    int h = contar_Aluno(no);  
    printf("\n");
    printf("\nQuantidade de alunos: %d\n", h);
    menor_nota(no);
    
    
    float soma = soma_das_notas(&no, h);
    printf("\nSoma das notas: %.2f\n", soma);
    float media = media_das_notas(soma, h);
    printf("\nMedia das notas: %.2f\n", media);
    printf("\nAlunos com nota maior que a media: \n");
    maiores_que_media(&no, media);
    fclose(arquivo);
    
    return 0;
}
    