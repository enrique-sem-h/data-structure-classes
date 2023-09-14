#include <stdio.h>
#include <stdlib.h>

#define MAX 4

void insetionSort(int *a);

int main(){
    int i, v[MAX];

    for(i = 0; i < MAX; i++){
        printf("Type: ");
        scanf("%d", &v[i]);u
    }

    insetionSort(v);

    printf("\tValores ordenados\n");
    for(i = 0; i < MAX; i++){
        printf("%d \t", v[i]);
    }

}

void insetionSort(int *a){
    int i, j, tmp;

    for(i = 1; i < MAX; i++){
        tmp = a[i];
        for(j = i - 1; j >= 0 && tmp < a[j]; j--){
            a[j+1] = a[j];
        }
        a[j+1] = tmp;
    }
}