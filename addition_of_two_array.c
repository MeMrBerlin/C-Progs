#include <stdio.h>

#define arr1_size 3
#define arr2_size 4
#define arr3_size 7

int main() {
  int arr1[arr1_size] = {1, 2, 3}, arr2[arr2_size] = {4, 5, 6, 7};
  int arr3[arr3_size];

  for (int i = 0; i < arr1_size; i++) {
    *(arr3 + i) = *(arr1 + i);
  }

  for (int j = 0; j < arr2_size; j++) {
    *(arr3 + arr1_size + j) = *(arr2 + j);
  }

  for (int i = 0; i < arr3_size; i++) {
    printf("%d\t", *(arr3 + i));
  }

  return 0;
}