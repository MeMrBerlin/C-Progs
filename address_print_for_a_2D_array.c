#include <stdio.h>

int main()
{
    int arr[1][2];
    for (int i = 0; i < 1; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            printf("The address of [%d][%d] is %u\n", i, j, &arr[i][j]);
        }
    }

    return 0;
}