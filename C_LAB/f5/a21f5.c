#include <stdio.h>
#include "genlib.h"
#include "simpio.h"
#include <math.h>

#define n   5

int main(){
    double numbers[n], dif[n-1];
    int i;
/*Input*/
    for(i=0; i<n; i++){
        printf("Enter number (%d): ", i);
        numbers[i] = GetReal();
    }
/*Process*/
    for(i=0; i<n-2; i++){
        dif[i] = fabs(numbers[i+1] - numbers[i]);
    }
/*Output*/
    for(i=0; i<n; i++){
        printf("%.2f ", numbers[i]);
    }
    printf("\n");
    for(i=0; i<n-1; i++){
        printf("%.2f ", dif[i]);
    }
    return 0;
}
