#include <stdio.h>

int main()
{
  int arr[10];
  int n;
  printf("Enter a value for n: ");
  scanf("%d", &n);
  for (int i = 0; i < 10; i++)
  {
    arr[i] = n * (i+1);
    printf("n X %d = %d\n", i+1, arr[i]);
  }
  // for (int i = 0; i < 10; i++)
  //{
  //   printf("n X %d = %d\n", i + 1, arr[i]);
  // }
  return 0;
}