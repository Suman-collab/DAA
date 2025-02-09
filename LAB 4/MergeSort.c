#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void printarr(int a[],int n){
    for(int i=0;i<n;i++){
        printf("%d ",a[i]);
    }
    printf("\n");
}
int check(int a[],int n,int num){
    for(int i=0;i<n;i++){
        if(a[i]==num){
            return 1;
        }
    }
    return 0;
}
void merge(int a[],int left,int mid,int right){
    int n1=mid-left+1;
    int n2=right-mid;
    int L[n1],R[n2];
    for(int i=0;i<n1;i++){
        L[i]=a[left+i];
    }
    for(int i=0;i<n2;i++){
        R[i]=a[mid+1+i];
    }
    int i=0,j=0,k=left;
    while(i<n1 && j<n2){
        if(L[i]<=R[j]){
            a[k++]=L[i++];
        }
        else{
            a[k++]=R[j++];
        }
    }
    while(i<n1){
        a[k++]=L[i++];
    }
    while(j<n2){
        a[k++]=R[j++];
    }
}
void mergesort(int a[],int left,int right){
    if(left<right){
        int mid=left+(right-left)/2;
        mergesort(a,left,mid);
        mergesort(a,mid+1,right);
        merge(a,left,mid,right);
    }
}
int main(){
    int n;
    printf("Enter the number of elements:");
    scanf("%d",&n);
    int arr[n];
    srand(time(0));
    int min=20,max=50;
    for(int i=0;i<n;i++){
        int num=min+rand()%(max-min)+1;
        if(!check(arr,i,num)){
            arr[i]=num;
        }
    }
    printf("Original Arrray:");
    printarr(arr,n);
    mergesort(arr,0,n-1);
    printf("Sorted Array:");
    printarr(arr,n);
    return 0;
}