//recursive way to print a pattern
#include<stdio.h>
int row=0;
int printstar(int n,int row){
    if(n==0||row==n){
        return 0;
    }
    else{
        for(int i=0;i<(n+row)-row;i++){
            printf(" ");
        }
        for(int i=0;i<=row;i++){
            printf("*");
        }
        printf("\n");
    }
}
int triangle(int n){
    if(n==0){
        return 0;
    }
    else{
        printstar(n,row++);
        triangle(n-1);
    }
}
int main(){
    triangle(5);
    return 0;
}