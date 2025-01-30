#include<stdio.h>
#include<stdlib.h>
#include<time.h>

// Function to print the array
void printarr(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Function to find the index of the minimum element in the array
int minindex(int arr[], int pos, int n) {
    int min = arr[pos];
    int minI = pos;
    for (int i = pos; i < n; i++) {
        if (arr[i] < min) {
            min = arr[i];
            minI = i;
        }
    }
    return minI;
}

// Function to swap two elements
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to perform selection sort up to k passes
void selectionsort(int arr[], int n) {
    int k;
    printf("Enter the No. of Passes: ");
    scanf("%d", &k);
    for (int i = 0; i < n; i++) {
        int minI = minindex(arr, i, n);
        if (arr[minI] < arr[i]) {
            swap(&arr[minI], &arr[i]);
        }
        if (i == k) {
            break;
        }
    }
}

// Function to perform complete selection sort
void selectionsort2(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        int minI = minindex(arr, i, n);
        if (arr[minI] < arr[i]) {
            swap(&arr[minI], &arr[i]);
        }
    }
}

int main() {
    int n;
    printf("Enter the value of n: ");
    scanf("%d", &n);

    FILE *f;
    f = fopen("num.txt", "w");
    srand(time(0));

    printf("The min and max value of the array: ");
    int min, max;
    scanf("%d %d", &min, &max);

    for (int i = 0; i < n; i++) {
        int num = min + rand() % (max - min + 1);
        fprintf(f, "%d\n", num);
    }
    fclose(f);

    f = fopen("num.txt", "r");
    int num;
    int arr[n];
    int i = 0;

    while (fscanf(f, "%d", &num) == 1) {
        arr[i++] = num;
    }
    fclose(f);

    printf("The original array:");
    printarr(arr, n);

    selectionsort(arr, n);
    printf("The sorted array on kth pass:");
    printarr(arr, n);

    selectionsort2(arr, n);
    printf("The Sorted array:");
    printarr(arr, n);

    return 0;
}
