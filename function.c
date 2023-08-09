#include <stdio.h>

int sum(int, int); // function prototype

int main()
{
    int a = 2, b = 74;

    printf("%d", sum(a, b));
    return 0;
}
int sum(int n1, int n2)
{
    return n1 + n2;
}
