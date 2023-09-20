/*Implemente uma versão do algoritmo de ordenação por inserção que ordene em ordem decrescente em vez de crescente.*/
#include <stdio.h>
#include <stdlib.h>

#define MAX 4

void insertionSort(int *a);

int main(){
    int i, v[MAX];

    for(i = 0; i < MAX; i++){
        printf("Type: ");
        scanf("%d", &v[i]);
    }

    insertionSort(v);

    printf("\tSorted Values (in descending order)\n");
    for(i = 0; i < MAX; i++){
        printf("%d \t", v[i]);
    }

    return 0;
}

void insertionSort(int *a){
    int i, j, tmp;

    for(i = 1; i < MAX; i++){
        tmp = a[i];
        for(j = i - 1; j >= 0 && tmp > a[j]; j--){
            a[j+1] = a[j];
        }
        a[j+1] = tmp;
    }
}
