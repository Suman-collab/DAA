#include<stdio.h>
#include<stdlib.h>
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
}
int main(){
    int n;
    printf("Enter the Value of n:");
    scanf("%d",&n);
    int a[n];
    int min,max;
    printf("Enter the min and max value:");
    scanf("%d %d",&min,&max);
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
    printarr(a,n);
    return 0;
}