#include <stdio.h>
#include "genlib.h"
#include "simpio.h"

long encode(long);
bool check(long);


int main(){
    long lower, upper, EN, i;

    printf("Lower Limit:");
    lower = GetLong();
    printf("Upper Limit:");
    upper = GetLong();

    for(i = lower; i <= upper; i++){
        EN = encode(i);
        printf("Code: %ld Encoding: %ld isValid:%s\n", i, EN, check(EN)? "yes":"no");
    }
    return 0;
}


long encode(long number){
    long new_number;
    int digits;

    new_number = number * 100;
    digits = (98-(number*100)%97)%97;

    return (new_number+digits);
}


bool check(long EN){
    return(EN % 97 == 1);
}
