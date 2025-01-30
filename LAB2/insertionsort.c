#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void printarr(int arr[],int n){
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
}
void insertionsort(int arr[],int n,int k){
    for(int i=1;i<n;i++){
        int key=arr[i];
        int j=i-1;
        while(j>=0&&arr[j]>key){
            arr[j+1]=arr[j];
            j=j-1;
        }
        arr[j+1]=key;
        if(i==k-1){
            break;
        }
    }
}
void insertionsort2(int arr[],int n){
    for(int i=0;i<n;i++){
        int key=arr[i];
        int j=i-1;
        while(j>=0&&arr[j]>key){
            arr[j+1]=arr[j];
            j=j-1;
        }
        arr[j+1]=key;
    }
}
int main(){
    int n;
    printf("Enter the no. of elements: ");
    scanf("%d",&n);
    int arr[n];
    srand(time(0));
    printf("Enter the min and max value of the array: ");
    int min,max;
    scanf("%d %d",&min,&max);
    for(int i=0;i<n;i++){
        arr[i]=min+rand()%(max-min)+1;
    }
    printf("The original Array:");
    printarr(arr,n);
    int k;
    printf("Enter the pass:");
    scanf("%d",&k);
    insertionsort(arr,n,k);
    printf("The sorted array for kth pass:");
    printarr(arr,n);
    printf("The Sorted array:");
    insertionsort2(arr,n);
    printarr(arr,n);
    return 0;
}