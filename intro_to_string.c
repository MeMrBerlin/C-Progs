#include <stdio.h>

int main()
{
    //char str[] = {'N', 'I', 'S', 'H', 'U', '\0'};
    char str[]="NISHU";// ANOTHER METHOD
    char *ptr = str;
    while (*ptr != '\0')// '\0' IS A NULL CHARACTER
    {
        printf("%c", *ptr);
        ptr++;
    }

    return 0;
}