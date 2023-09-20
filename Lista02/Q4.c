/*Escreva um programa em C que ordene uma matriz bidimensional (uma matriz de inteiros, por exemplo) usando o algoritmo de quicksor.
*/
#include <stdio.h>

#define ROWS 3
#define COLS 4

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[][COLS], int low, int high) {
    int pivot = arr[low][0];
    int i = low, j;

    for (j = low + 1; j <= high; j++) {
        if (arr[j][0] > pivot) {
            i++;
            for (int k = 0; k < COLS; k++) {
                swap(&arr[i][k], &arr[j][k]);
            }
        }
    }
    for (int k = 0; k < COLS; k++) {
        swap(&arr[low][k], &arr[i][k]);
    }
    return i;
}

void quickSort(int arr[][COLS], int low, int high) {
    if (low < high) {
        int pivotIndex = partition(arr, low, high);
        quickSort(arr, low, pivotIndex - 1);
        quickSort(arr, pivotIndex + 1, high);
    }
}

void printMatrix(int arr[][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int matrix[ROWS][COLS] = {
        {5, 2, 9, 1},
        {6, 4, 8, 3},
        {7, 3, 7, 2}
    };

    printf("Original Matrix:\n");
    printMatrix(matrix);

    // Sort each row using QuickSort
    for (int i = 0; i < ROWS; i++) {
        quickSort(matrix, 0, COLS - 1);
    }

    printf("\nMatrix after QuickSort:\n");
    printMatrix(matrix);

    return 0;
}
