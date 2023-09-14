#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void sort(char array[], int tam){
    int i, j;
    char aux;

    for (i = 0; i < tam; ++i){
        for(j=tam - 1; j > i; --j){
        if (array[j - 1] > array[j]){
            aux = array[j - 1];
            array[j - 1] = array[j];
            array[j] = aux;
        }
        }
    }
}

int main(){
    char array[25];

    printf("Type in the string: ");
    scanf(" %s", array);

    sort(array, strlen(array));

    printf("%s", array);
}