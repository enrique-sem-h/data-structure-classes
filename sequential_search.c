#include <stdio.h>
#include <stdlib.h>

void search(int n, int *arr);

int main(){
    int i, n;
    int arr[10] = {-12,4,3,2,112,-12,0,23,47,-343};

    printf("Search for: ");
    scanf("%d", &n);

    search(n, arr);
    
    return 0;
}

void search(int n, int *arr){
    char valid = 'f';

    for (int i = 0; i < 10; i++){
        if(n == arr[i]){
        printf("%d found in arr[%d] position\n", n, i );
        valid = 't';
    }
    }
    if (valid == 'f') {
        printf("Value not found\n");
    }
}