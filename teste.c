#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int *Muda_Vetor(int *vetor, int tamanho){
    for(int i = 0; i < tamanho; i++){
        vetor[i] = i;
    }
    return vetor;
}





int main(){
    int numero = 5;
    int *vetor = (int *)malloc(numero * sizeof(int));
    vetor = Muda_Vetor(vetor, numero);
    for(int i = 0; i < numero; i++){
        printf("%d\n", vetor[i]);
    }
}