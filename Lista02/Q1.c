/*Questão 1 - Escreva um programa em C que ordena um array de inteiros usando o algoritmo de ordenação por bolha.*/
#include <stdio.h>
#include <stdlib.h>

#define MAX 5

int main(){
    int i, aux, array[MAX], n;

    for(i = 0; i < MAX; i++){
        printf("%d. Type in the number: ", i+1);
        scanf("%d", &array[i]);
    }

    system("clear");
    printf("\n");
 
    for(i = 0; i < MAX; i++){
        printf("%d\t", array[i]);
    }
    printf("\n");

    for(i = 0; i < MAX; i++){
        for(n = 0; n < 4; n++){
        if (array[n] > array[n + 1]){
            aux = array[n];
            array[n] = array[n + 1];
            array[n + 1] = aux;
        }
        }
    }

    for(i = 0; i < MAX; i++){
        printf("%d\t", array[i]);
    }

}