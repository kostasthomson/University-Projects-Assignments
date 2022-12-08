#include <stdio.h>
#include "genlib.h"
#include "simpio.h"

int main(){
    int n, x;
    float sum;
    printf("Dwse orio:");
    n = GetInteger();
    sum = 0;
    for(x = 1; x <= n; x++ ){
        sum += (float)1/x;
    }
    printf("To athroisma einai %4.2f", sum);
    return 0;
}
