#include <stdio.h>
#include <stdlib.h>
void swap(int *x, int *y) {
  int tmp = *x;
  *x = *y;
  *y = tmp;
}

void sort(int array[], int n) {
  for (int i = 0; i < n - 1; i++) {
    int max = i;
    for (int j = i + 1; j < n; j++) {
      if (array[j] > array[max])
        max = j;
    }
    swap(&array[max], &array[i]);
  }
}

void printarr(int array[], int n) {
  for (int i = 0; i < n; ++i) {
    printf("%d ", array[i]);
  }
  printf("\n");
}
int main(){
    int n;
    printf("Enter the size of your array: \n");
    scanf("%d", n);
    int array[n], i, j, pointr;
    printf("Enter your array: \n");
    for (i = 0; i < n; i++){
        scanf("%d", &array[i]);
    }
    sort(array, n);
}
