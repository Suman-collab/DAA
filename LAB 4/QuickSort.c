#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int check(FILE *f, int temp){
    int num;
    f=fopen("num.txt","r");
    while(fscanf(f,"%d",&num)==1){
        if(num==temp){
            return 0;
        }
    }
    return 1;
}

void printarr(int a[],int n){
    for(int i=0;i<n;i++){
        printf("%d ",a[i]);
    }
    printf("\n");
}

int partition(int a[],int left,int right){
    int pivot = a[right];
    int i = (left - 1);
    for (int j = left; j < right; j++){
        if (a[j] <= pivot){
            i++;
            int temp=a[i];
            a[i]=a[j];
            a[j]=temp;
        }
    }
    int temp = a[i + 1];
    a[i + 1] = a[right];
    a[right] = temp;
    return (i + 1);
}

void quicksort(int a[],int left,int right){
    if(left<right){
        int pivot=partition(a,left,right);
        quicksort(a,left,pivot-1);
        quicksort(a,pivot+1,right);
    }
}

int main(){
    int n;
    printf("Enter the number of Element:");
    scanf("%d",&n);
    FILE *f=fopen("num.txt", "w");
    srand(time(0));
    int min=20,max=50;
    for(int i=0;i<n;i++){
        int num=min+rand()%(max-min)+1;
        if(check(f,num)){
            fprintf(f,"%d\n",num);
        }
    }
    fclose(f);
    f=fopen("num.txt", "r");
    int a[n];
    int num;
    int i=0;
    while(fscanf(f,"%d",&num)==1){
        a[i++]=num;
    }
    fclose(f);
    printf("Original number:");
    printarr(a,n);
    quicksort(a,0,n-1);
    printf("Sorted number:");
    printarr(a,n);
    return 0;
}