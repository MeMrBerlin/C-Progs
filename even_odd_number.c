#include<stdio.h>
int main(){
    int i,n;
    printf("enter the value of n");
    scanf("%d", &n);
    for(i=0;i<=n;i=i+=2)
    printf("Even numbers are %d\n", i);
    for(i=1;i<=n;i=i+=2)
    printf("Odd numbers are %d\n", i);
    return 0;
}