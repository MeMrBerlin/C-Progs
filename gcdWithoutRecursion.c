#include <stdio.h>

int main()
{
    int a, b;
    printf("ENTER TWO NUMBER: ");
    scanf("%d %d", &a, &b);

    while (a != b)
    {
        if (a > b)
        {
            a = a - b;
        }
        else
        {
            b = b - a;
        }
    }
    
    printf("THE GCD IS: %d", a);

    return 0;
}