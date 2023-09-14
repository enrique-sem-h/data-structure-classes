#include <stdio.h>
#include <stdlib.h>

int main(){
    int i, aux, array[5], n;

    for(i = 0; i < 5; i++){
        printf("%d. Type in the number: ", i+1);
        scanf("%d", &array[i]);
    }

    system("clear");
    printf("\n");
 
    for(i = 0; i < 5; i++){
        printf("%d\t", array[i]);
    }
    printf("\n");

    for(i = 0; i < 5; i++){
        for(n = 0; n < 4; n++){
        if (array[n] > array[n + 1]){
            aux = array[n];
            array[n] = array[n + 1];
            array[n + 1] = aux;
        }
        }
    }

    for(i = 0; i < 5; i++){
        printf("%d\t", array[i]);
    }

}