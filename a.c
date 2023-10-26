#include <stdio.h>
#define MAX 10

void insert(int *a, int *size, int ele){
    int i, j;

    if(*size >= MAX){
        printf("error");
        return;
    }

    for(i = 0; i < *size; i++){
        if (a[i] > ele){
            for(j = *size; j > i; j--){
                a[j] = a[j - 1];
            }
            break;
        }
    }
        a[i] = ele;
        (*size)++;
}

int main(){
    int arr[MAX];
    int size = 0;

    insert(arr, &size, 1);
    insert(arr, &size, 0);

printf("Ordered List: ");
    for(int i = 0; i < size; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");

}