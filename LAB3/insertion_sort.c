#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int check(int a[],int n,int num){
    for(int i=0;i<n;i++){
        if(a[i]==num){
            return 1;
        }
    }
    return 0;
}
void printarr(int a[],int n){
    for(int i=0;i<n;i++){
        printf("%d ",a[i]);
    }
    printf("\n");
}
void insertion_sort(int a[],int n){
    int k;
    printf("Enter the Pass:");
    scanf("%d",&k);
    for(int i=1;i<n;i++){
        int key=a[i];
        int j=i-1;
        while(j>=0 && a[j]>key){
            a[j+1]=a[j];
            j=j-1;
        }
        a[j+1]=key;
        if(i==k+1)
        break;
    }
}
void insertion_sort2(int a[],int n){
    for(int i=1;i<n;i++){
        int key=a[i];
        int j=i-1;
        while(j>=0 && a[j]>key){
            a[j+1]=a[j];
            j=j-1;
        }
        a[j+1]=key;
    }
}
int main(){
    int n=10;
    srand(time(0));
    int a[10];
    int max,min;
    printf("Enter the Max and Min Value:");
    scanf("%d %d",&max,&min);
    int num;
    for(int i=0;i<n;i++){
        if(i==0){
            a[i]=rand()%(max-min+1)+min;
        }
        else{
            num=rand()%(max-min+1)+min;
            while(check(a,n,num)){
                num=min+rand()%(max-min)+1;
            }
            a[i]=num;
        }
    }
    printf("Original Array:");
    printarr(a,n);
    insertion_sort(a,n);
    printf("Sorted array After Kth Pass:");
    printarr(a,n);
    insertion_sort2(a,n);
    printf("Sorted array:");
    printarr(a,n);
    return 0;
}