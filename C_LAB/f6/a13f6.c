#include <stdio.h>
#include "genlib.h"
#include "simpio.h"
#include <math.h>

void decompose(long n, int* dig, float* avg, int* max);

int main(){
    long number;
    int max, dig;
    float avg;

    printf("Please insert non-negative number:");
    number = GetLong();
    decompose(number, &dig, &avg, &max);
    printf("Digits: %d\n", dig);
    printf("Average: %.3f\n", avg);
    printf("Max: %d\n", max);
    return 0;
}

void decompose(long n, int* dig, float* avg, int* max){
     int i, x, sum;

     *dig = 0;
     x = 1;
     do{
        (*dig)++;
        x *= 10;
     }while(n / x != 0);

    int digits[*dig];

    sum = 0;
    *max = 0;
    for(i = 0; i < *dig; i++){
        x /= 10;
        digits[i] = n / x;
        sum += digits[i];
        if(digits[i] > *max){
            *max = digits[i];
        }
        n %= x;
    }
    *avg = (float)sum / (*dig);
}
