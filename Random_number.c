#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main()
{
    int number;
    srand(time(NULL));
    number = rand()%10+1; //generate random number between 1 to 100
    printf("The Random number is %d \n", number);

    return 0;
}

