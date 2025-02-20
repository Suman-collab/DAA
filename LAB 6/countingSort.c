#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void printarr(int a[],int n){
    for(int i=0;i<n;i++){
        printf("%d ",a[i]);
    }
    printf("\n");
}
void countingSort(int arr[], int n) {
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (max < arr[i]) {
            max = arr[i];
        }
    }
    int save[max + 1]; // Fix array size
    for (int i = 0; i <= max; i++) {
        save[i] = 0; // Initialize the array
    }
    for (int i = 0; i < n; i++) {
        save[arr[i]]++;
    }
    for (int i = 1; i <= max; i++) {
        save[i] += save[i - 1];
    }
    int output[n];
    for (int i = n - 1; i >= 0; i--) {
        output[save[arr[i]] - 1] = arr[i];
        save[arr[i]]--;
    }
    for (int i = 0; i < n; i++) {
        arr[i] = output[i];
    }
}
int main()
{
    int n;
    printf("Enter the number of elements: ");
    scanf("%d",&n);
    int arr[n];
    srand(time(0));
    int min=1;
    int max=7;
    for(int i=0;i<n;i++){
        arr[i]=min+rand()%(max-min)+1;
    }
    printf("Array before sorting: ");
    printarr(arr,n);
    countingSort(arr, n);
    printf("Array after sorting: ");
    printarr(arr, n);
    return 0;
}