#include <stdio.h>
#include <stdlib.h>
int main(){
    float x;
    int y=0.1;
    for( x=0.1; x<10; x=x+y){
        printf("%f", x);
        y=0.1/10;
    }}
