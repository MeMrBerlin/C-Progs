#include <stdio.h>
int main()
{
    float price[4];
    //float gtotal;
    printf("ENTER THE VALUE OF 1ST ITEM:");
    scanf("%f", &price[0]);
    printf("ENTER THE VALUE OF 2ST ITEM:");
    scanf("%f", &price[1]);
    printf("ENTER THE VALUE OF 3ST ITEM:");
    scanf("%f", &price[2]);
    printf("ENTER THE VALUE OF 4ST ITEM:");
    scanf("%f", &price[3]);
    printf("The price with gst will be: %.3f %.3f %.3f and %.3f\n", price[0] + price[0] * .18, price[1] + price[1] * .18, price[2] + price[2] * .18, price[3] + price[3] * .18, price[4] + price[4] * .18);
    //  gtotal = gtotal + price[4];
    printf("The grand total value of all item will be %.3f \n", price[0] + price[1] + price[3] + price[4]);
    return 0;
}