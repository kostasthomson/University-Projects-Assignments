#include <stdio.h>
#include "genlib.h"
#include "simpio.h"

int main(){
    int age;
    double weigth, height, BMR;
    BMR = 655;
    //input
    printf("dwse baros se kila: ");
    weigth = GetReal();
    printf("dwse ypsos se cm: ");
    height = GetReal();
    printf("dwse hlikia se xronia: ");
    age = GetInteger();
    //operations
    BMR += (9.6 * weigth) + (1.8 * height) - (4.7 * age);
    //output
    printf("To BMR einai: %g", BMR);
    return 0;
}
