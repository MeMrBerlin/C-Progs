#include <stdio.h>
int main()
{
    int age = 22;
    int *ptr = &age;
    int _age = *ptr;
    printf("The value of age %d\n", age);
    printf("The value of address %u\n", ptr);
    printf("The value of ptr %d\n", _age);
}