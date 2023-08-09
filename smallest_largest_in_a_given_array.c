#include <stdio.h>

int main() {
  int arr[10] = { 120, -12, 30, 56, 0, -4, 100, 20, 45, -170 };
  int largest = arr[0], smallest = arr[0];

  for(int i=0;i<10;i++) {
    if(largest < arr[i]) {
      largest = arr[i];
    }
    if (smallest > arr[i]) {
      smallest = arr[i];
    }
  }

  printf("Smallest: %d\n", smallest);
  printf("Largest: %d\n", largest);

  return 0;
}
