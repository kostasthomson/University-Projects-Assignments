#include <stdio.h>
#include "genlib.h"
#include "simpio.h"
#include <math.h>

int cube(int);
int sum_cube(int);
bool IsArmstrong(int);


int main(){
    for(int i = 1; i <= 999; i++){
        if(IsArmstrong(i)){
            printf("%d\n", i);
        }
    }
    return 0;
}

int cube(num){
    return pow(num, 3);
}

int sum_cube(num){
    int dig3, dig2, dig1;

    dig3 = num / 100;
    dig2 = (num % 100) / 10;
    dig1 = num % 10;

    return(cube(dig1)+cube(dig2)+cube(dig3));
}

bool IsArmstrong(num){
    return(num == sum_cube(num));
}
