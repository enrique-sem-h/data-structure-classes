#include <stdio.h>
#define COUNT 5

void insertionSort(int *list){
    int i, j, aux;
    
    for(i = 0; i < COUNT; i++){
        aux = list[i];
        for(j = i - 1; j >= 0 && aux > list[j]; j--){
        list[j + 1] = list[j];
        }
        list[j + 1] = aux;
    }
}

int main(){
    int list[COUNT], i;

    for(i = 0; i < COUNT; i++){
        printf("Item %d: ", i + 1);
        scanf("%d", &list[i]);
    }

    insertionSort(list);

    for(i = 0; i < COUNT; i++){
        printf("\nSorted Item %d: %d", i + 1, list[i]);
    }

}
