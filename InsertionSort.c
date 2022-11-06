#include <stdio.h>
#include <stdlib.h>
void insertionsort(int array[], int n) {
  for (int i = 1; i < n; i++) {
    int key = array[i];
    int j = i - 1;
    while (key < array[j] && j >= 0) {
      array[j + 1] = array[j];
      --j;
    }
    array[j + 1] = key;
  }

int main(){
    int n;
    printf("Enter the size of your array: \n");
    scanf("%d", n);
    int array[n], i;
    printf("Enter your array: \n");
    for (i = 0; i < n; i++){
        scanf("%d", &array[i]);
    insertionsort(array[], n)
    for(i = 0; i < n; i++){
        printf("%d\n", a[i]);
        return 0; }

    }
