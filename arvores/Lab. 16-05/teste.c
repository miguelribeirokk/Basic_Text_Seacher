#include <stdio.h>
#include <stdlib.h>


int main(){
    //criar arquivo com x nomes-matricula-nota aleatorias
    FILE *arquivo;
    arquivo = fopen("alunos.txt", "w");
    int i;
    //nota entre 0 e 10
    for(i = 0; i < 10; i++){
        
        fprintf(arquivo, "nome%d-%d-%.2f\n", i, i, (float)rand()/RAND_MAX*10);
    }
    fclose(arquivo);
}
