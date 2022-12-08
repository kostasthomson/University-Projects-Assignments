#include <stdio.h>
#include "genlib.h"
#include "simpio.h"

#define n   5

int main(){
    int numbers[n];
    int i, temp, last;
/*Input*/
    for(i=0; i<n; i++){
        printf("Enter number: ");
        numbers[i] = GetInteger();
    }
/*Process*/
    last = numbers[n-1];
    for(i=n-1; i>=0; i--){
        numbers[i] = numbers[i-1];
    }
    numbers[0] = last;
/*Output*/
    for(i=0; i<n; i++){
        printf("%d ", numbers[i]);
    }
    return 0;
}
