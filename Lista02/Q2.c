/*Questão 2 - Compare o desempenho do algoritmo de ordenação por bolha com algoritmo de ordenação o quicksort e o mergesort, usando arrays de tamanhos diferentes. Meça o tempo de execução e compare os resultado.*/

// conclusao: O metodo quicksort e bubble sort, a nivel de usuario, levam o mesmo tempo de execucao, apesar de o metodo quicksort ser um pouco mais recursivo.

#include <stdio.h>
#include <stdlib.h>
#define MAX 5

void quick_sort(int *a, int left, int right);
void print_values(int *a, int count);
void quick_sort_main();
void bubble_sort_main();

int main(){

    // quick_sort_main();
    bubble_sort_main();

}


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

void quick_sort_main(){
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

void bubble_sort_main(){
    int i, aux, array[MAX], n;

    for(i = 0; i < MAX; i++){
        printf("%d. Type in the number: ", i+1);
        scanf("%d", &array[i]);
    }

    system("clear");
    printf("\n");
 
    for(i = 0; i < MAX; i++){
        printf("%d\t", array[i]);
    }
    printf("\n");

    for(i = 0; i < MAX; i++){
        for(n = 0; n < MAX - 1; n++){
        if (array[n] > array[n + 1]){
            aux = array[n];
            array[n] = array[n + 1];
            array[n + 1] = aux;
        }
        }
    }

    for(i = 0; i < MAX; i++){
        printf("%d\t", array[i]);
    }

}
