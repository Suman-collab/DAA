#include<stdio.h>
#include<stdlib.h>
#include<time.h>

// Corrected check function
int check(FILE *f,int num){
    int temp;
    f=fopen("num.txt","r");
    while(fscanf(f,"%d",&temp)==1){
        if(temp==num){
            fclose(f);
            return 1;
        }
    }
    fclose(f);
    return 0;
}

void printarr(int a[],int n){
    for(int i=0;i<n;i++){
        printf("%d ",a[i]);
    }
    printf("\n");
}

int minIndex(int a[],int n,int i){
    int minI=i;
    for(int j=i+1;j<n;j++){
        if(a[j]<a[minI]){
            minI=j;
        }
    }
    return minI;
}

void swap(int *a,int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
}

void selection_sort(int a[],int n){
    int k;
    printf("Enter the Pass:");
    scanf("%d",&k);
    for(int i=0;i<n;i++){
        int minI=minIndex(a,n,i);
        if(a[i]>a[minI]){
            swap(&a[i],&a[minI]);
        }
        if(i==k){
            break;
        }
    }
}

void selection_sort2(int a[],int n){
    for(int i=0;i<n;i++){
        int minI=minIndex(a,n,i);
        if(a[i]>a[minI]){
            swap(&a[i],&a[minI]);
        }
    }
}

int main(){
    int n=10;
    srand(time(0));
    int a[10];
    int max,min;
    printf("Enter the Max and Min Value:");
    scanf("%d %d",&max,&min);
    FILE *f;
    f=fopen("num.txt","w");
    int num;
    for(int i=0;i<n;i++){
        if(i==0){
            num=min+rand()%(max-min)+1;
            fprintf(f,"%d\n",num);
        }
        else{
            num=min+rand()%(max-min)+1;
            while(check(f,num)){
                num=min+rand()%(max-min)+1;
            }
            fprintf(f,"%d\n",num);
        }
    }
    fclose(f);

    f=fopen("num.txt","r");
    int i=0;
    while(fscanf(f,"%d",&num)==1){
        a[i]=num;
        i++;
    }
    fclose(f);

    printf("Original Array:");
    printarr(a,n);
    selection_sort(a,n);
    printf("Sorted array After Kth Pass:");
    printarr(a,n);
    selection_sort2(a,n);
    printf("Sorted array:");
    printarr(a,n);
    
    return 0;
}
