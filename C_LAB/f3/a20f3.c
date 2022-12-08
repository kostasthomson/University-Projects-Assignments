#include <stdio.h>
#include "genlib.h"
#include "simpio.h"

int main(){
    int age, min, max;
    printf("Dwse ilikia: ");
    age = GetInteger();
    min = age;
    max = age;
    while(age != -1){
        if(age > max){
            max = age;
        }
        if(age < min){
            min = age;
        }
        printf("Dwse ilikia: ");
        age = GetInteger();
    }
    printf("H megalyteri ilikia einai %d\n", max);
    printf("H mikroteri ilikia einai %d\n", min);
    return 0;
}
