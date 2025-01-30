// #include<stdio.h>
// #include<string.h>
// #include<stdlib.h>
// int main()
// {
//     FILE *f;
//     f=fopen("abc.txt","w+");
//     if(f==NULL){
//         printf("file not found");
//         return 1;
//     }
//     char c='s';
//     // fputc(c,f);
//     char str[]="Suman";
//     // fputs(str,f);
//     int a=10;
//     fprintf(f,"%d\n%c\n%s",a,c,str);
//     fclose(f);
//     return 0;
// }
#include <stdio.h>

int main() {
    FILE *fp;
    char ch='x';
    int characters = 0, words = 0, lines = 0;

    fp = fopen("abc.txt", "r");
    fputc(ch,fp);
    if (fp == NULL) {
        printf("Error opening file.\n");
        return 1;
    }
    while ((ch = fgetc(fp)) != EOF) {
        characters++;
        if (ch == ' ' || ch == '\n') words++;
        if (ch == '\n') lines++;
    }
    fclose(fp);
    printf("Characters: %d\n", characters);
    printf("Words: %d\n", words);
    printf("Lines: %d\n", lines);
    return 0;
}
