#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function prototypes
void printarr(int arr[], int n);
int minindex(int arr[], int pos, int n);
void swap(int *a, int *b);
void selectionsort(int arr[], int n, int k);
int check(FILE *f, int num);

// Function to print the array
void printarr(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Function to find the index of the minimum element in the array
int minindex(int arr[], int pos, int n) {
    int minI = pos;
    for (int i = pos + 1; i < n; i++) {
        if (arr[i] < arr[minI]) {
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
void selectionsort(int arr[], int n, int k) {
    for (int i = 0; i < n && i < k; i++) {
        int minI = minindex(arr, i, n);
        if (arr[minI] < arr[i]) {
            swap(&arr[minI], &arr[i]);
        }
    }
}

// Function to check if the number is already present in the file
int check(FILE *f, int num) {
    rewind(f);
    int temp;
    while (fscanf(f, "%d", &temp) == 1) {
        if (temp == num) {
            return 1;
        }
    }
    return 0;
}

int main() {
    int n;
    printf("Enter the value of n: ");
    scanf("%d", &n);

    int min, max;
    printf("Enter the min and max value of the array: ");
    scanf("%d %d", &min, &max);
    
    if (n > (max - min + 1)) {
        printf("Error: Not enough unique numbers in the given range.\n");
        return 1;
    }
    
    FILE *f = fopen("num.txt", "a+");
    if (!f) {
        printf("Error opening file!\n");
        return 1;
    }
    
    int num, i = 0;
    int arr[n];
    while (i < n) {
        num = min + rand() % (max - min + 1);
        if (!check(f, num)) {
            fprintf(f, "%d ", num);
            arr[i++] = num;
        }
    }
    fclose(f);
    
    printf("The original array: ");
    printarr(arr, n);

    int k;
    printf("Enter the number of passes for selection sort: ");
    scanf("%d", &k);
    
    selectionsort(arr, n, k);
    printf("The sorted array after %d passes: ", k);
    printarr(arr, n);

    selectionsort(arr, n, n);
    printf("The fully sorted array: ");
    printarr(arr, n);

    return 0;
}