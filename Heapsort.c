// Citation: https://codingzap.com/how-to-build-max-heap-from-an-array-using-c/
#include <stdio.h>
#include <stdlib.h>

void swap (int *x, int *y){
    int tmp = *y;
    *y = *x;
    *x = tmp;
}

void heapify (int array[], int n, int p){
    int biggest;
    int left; 
    int right;
    biggest = p;
    left = 2*p + 1;
    right = 2*p + 2;
    
    if (left < n && array[left] > array[biggest]){
        biggest = left;
    }
    if (right < n && array[right] > array[biggest]){
        biggest = right;
    }
    if (biggest != p){
        swap(&array[p], &array[biggest]);
        heapify (array, n, biggest);
    }
    
}

void makeheap (int array[], int n){
    int lastnode = (n/2) - 1;
    for (int j = lastnode; j>=0; j--){
        heapify (array, n, j);
    }
}

int main() {
    int n;
    printf("Enter the size of your array: \n");
    scanf("%d", &n);
    int array[n];
    printf("Enter your array: \n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &array[i]);
        
    }
    makeheap (array, n);
    printf("The max-heap is : \n");
    for (int h=0; h<n; h++){
        printf("%d\n", array[h]);
        
    }
    int newarr[n-1];
    int k = 0;
    for(int h=1; h<n; h++){
        newarr[k] = array[h];
        k++;
    }
    int m = sizeof(newarr)/sizeof(newarr[0]);
    makeheap (newarr, m);
    
    int newarr2[m-1];
    int l = 0;
    for(int o=1; o<m; o++){
        newarr2[l] = newarr[o];
        l++;
    }
    int mn = sizeof(newarr2)/sizeof(newarr2[0]);
    makeheap (newarr2, mn);
    
    int newarr3[mn-1];
    int ks = 0;
    for(int hi=1; hi<mn; hi++){
        newarr3[ks] = newarr2[hi];
        ks++;
    }
    int my = sizeof(newarr3)/sizeof(newarr3[0]);
    makeheap (newarr3, my);
    
    printf("The third largest element is: ");
    printf("%d", newarr3[0]);


    return 0;
}
