#include <stdio.h>
#include <stdlib.h>
#define MAX 4


void quick_sort(int *a, int left, int right){
    int i, j, x, y;

    i = left;
    j = right;
    x = a[(left + right) / 2];

    if(i <= j){
        while (a[i] < x && i < right){
            i++;
        }
        while (a[j] > x && j > left){
            j--;
        }
        if (i <= j){
            y = a[i];
            a[i] = a[j];
            a[j] = y;
            i++;
            j--;
        }
    }

    if(j > left){
        quick_sort(a, left, j);
    }
    if (i < right){
        quick_sort(a, i, right);
    }

}

void print_values(int *a, int count){
printf("Values: ");
    for (int i = 0; i < count; i++){
    printf("%d\t", a[i]);
    }
    printf("\n");
}

int main(){
    int i, arr[MAX];

    for (i = 0; i < MAX; i++){
        printf("Type a value: ");
        scanf("%d", &arr[i]);
    }
    system("clear");
    print_values(arr, MAX);

    quick_sort(arr, 0, MAX - 1);

    print_values(arr, MAX);


}