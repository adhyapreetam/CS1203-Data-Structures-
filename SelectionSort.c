#include <stdio.h>
#include <stdlib.h>
int main(){
    int n;
    printf("Enter the size of your array: \n");
    scanf("%d", n);
    int array[n], i, j, pointr;
    printf("Enter your array: \n");
    for (i = 0; i < n; i++){
        scanf("%d", &array[i]);
    }
    for (i = 0, i <  n-1, i++){
        pointr = i;
        for (j=i+1, j<n, j++){
            if (array[pointr] < array[j])
            pointr = j;
            if (pointr != i)
            {swap=array[i];
            array[i]=array[pointr];
            array[pointr=swap;}
            printf("Sorted Array:n");
    for(i = 0; i < n; i++){
    printf("%dn", a[i]);
    return 0; }
    }


}
