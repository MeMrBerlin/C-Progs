#include<stdio.h>
int main(){
    int i=40;
    int *ptr=&i;
    printf("The value of prt before %u \n", ptr);
    ptr++;
    printf("The value of prt after %u \n", ptr);
}