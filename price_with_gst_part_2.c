#include <stdio.h>

int main() {
  int price[5];
  float total[5], gtotal = 0;

  for (int i = 0; i < 5; i++) {
    printf("Enter the value of object_%d : ", i+1);
    scanf("%d", &price[i]);

    total[i] = price[i] * 1.18;
    gtotal = gtotal + total[i];
  }

  for (int i = 0; i < 5; i++) {
    printf("The value of the object_%d : %.2f\n", i+1, total[i]);
  }

  printf("Net value with GST of the 10 items : %.3f\n", gtotal);
  return 0;
}