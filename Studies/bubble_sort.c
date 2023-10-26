#include <stdio.h>
#define COUNT 8

void bubbleSort(int *list){
    int i, j, aux;

    for(i = 0; i < COUNT; i++){
        for(j = 0; j < COUNT - 1; j++){
            if(list[j] > list[j+1]){
                aux = list[j];
                list[j] = list[j+1];
                list[j + 1] = aux;
            }
        }
    }
}

int main(){
    int list[COUNT] = {8,7,6,5,4,3,2,1}, i;

    // for(i = 0; i < COUNT; i++){
    //     printf("Item %d: ", i + 1);
    //     scanf("%d", &list[i]);
    // }

    bubbleSort(list);

    for(i = 0; i < COUNT; i++){
        printf("\nSorted Item %d: %d", i+1,list[i]);
    }

}