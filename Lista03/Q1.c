/*Escreva um programa em C que solicite o tamanho da lista e possua um método de Inserir Lista Ordenada,
que cria a lista de forma ordenada.*/
#include <stdio.h>
#define MAXSIZE 100


void orderedInsert(int *list, int *size, int element){
    int i, j;

    if (*size >= MAXSIZE){
        printf("Error: List limit reached\n");
        return;
    }

    for(i = 0; i < *size; i++){
        if (element < list[i]){
            for(j = *size; j > i; j--){
                list[j] = list[j - 1];
            }
            break;
        }
    }
    list[i] = element;
    (*size)++;
}

int main(){
    int list[MAXSIZE];
    int size;

    printf("Type in the list's size: ");
    scanf("%d", &size);

    orderedInsert(list, &size, 2);
    orderedInsert(list, &size, 0);
    orderedInsert(list, &size, 1);

    printf("Ordered List: ");
    for(int i = 0; i < size; i++){
        printf("%d ", list[i]);
    }
    printf("\n");

    return 0;
}