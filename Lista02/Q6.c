/*Escreva um programa em C que ordene uma matriz bidimensional (uma matriz de inteiros, por exemplo) usando o algoritmo de ordenação por inserção.
*/
#include <stdio.h>

#define ROWS 3
#define COLS 4

void insertionSort(int arr[][COLS], int row) {
    for (int i = 1; i < COLS; i++) {
        int key = arr[row][i];
        int j = i - 1;

        while (j >= 0 && arr[row][j] > key) {
            arr[row][j + 1] = arr[row][j];
            j--;
        }

        arr[row][j + 1] = key;
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

    // Sort each row using Insertion Sort
    for (int i = 0; i < ROWS; i++) {
        insertionSort(matrix, i);
    }

    printf("\nMatrix after Insertion Sort:\n");
    printMatrix(matrix);

    return 0;
}
