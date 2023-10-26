// C program to implement iterative Binary Search
#include <stdio.h>
#define MAX 5
 
// An iterative binary search function.
int binarySearch(int *arr, int l, int r, int x)
{
    while (l <= r) {
        int m = l + (r - l) / 2;
 
        // Check if x is present at mid
        if (arr[m] == x)
            return m;
 
        // If x greater, ignore left half
        if (arr[m] < x)
            l = m + 1;
        // If x is smaller, ignore right half
        else
            r = m - 1;
    }
 
    // If we reach here, then element was not present
    return -1;
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

// Driver code
int main(void)
{
    int arr[MAX];
    int n = sizeof(arr) / sizeof(arr[0]);
    int x;
    int result;

    for(int i = 0; i < MAX; i++){
        printf("%d. Type in the number: ", i+1);
        scanf("%d", &arr[i]);
    }

    printf("Type in the element to be searched: ");
    scanf("%d", &x);

    quick_sort(arr, 0, MAX - 1);

    printf("Ordered array:\n");
    for(int i = 0; i < MAX; i++){
        printf("%d\t", arr[i]);
    }
        printf("\n");

    result = binarySearch(arr, 0, n - 1, x);

    (result == -1) ? printf("Element is not present" " in array") : printf("Element is present at " "index %d", result);
    return 0;
}