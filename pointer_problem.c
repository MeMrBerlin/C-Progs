#include <stdio.h>
int main()
{
    int arr[10];
    int *ptr = &arr[0];
    ptr = ptr + 2;
    if (ptr == &arr[2])
    {
        printf("This point to same location memory\n");
    }
    else
    {
        printf("This does not point to same location memory\n");
    }
}