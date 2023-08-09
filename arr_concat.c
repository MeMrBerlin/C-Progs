#include <stdio.h>

int main() {
  int arr1[3] = {1, 2, 3}, arr2[4] = {4, 5, 6, 7};
  int arr3[7];

  for (int i = 0; i < 3; i++) {
    *(arr3 + i) = *(arr1 + i);
  }

  for (int j = 0; j < 4; j++) {
    *(arr3 + 3 + j) = *(arr2 + j);
  }

  for (int i = 0; i < 7; i++) {
    printf("%d\t", *(arr3 + i));
  }

  return 0;
}
