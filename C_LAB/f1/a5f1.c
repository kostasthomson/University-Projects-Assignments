#include <stdio.h>
#include "genlib.h"
#include "simpio.h"

int main(){
    int hours;
    long antimis;
    double per, aka_apod, pos_krat, kath_apod;
    //inputs
    printf("dwse ores ergasias: ");
    hours = GetInteger();
    printf("dwse oriaia antimisthia: ");
    antimis = GetLong();
    printf("dwse pososto kratiseon: ");
    per = GetReal();
    //operations
    kath_apod = (double)hours * antimis;
    pos_krat = kath_apod * per;
    aka_apod = kath_apod + pos_krat;
    //output
    printf("oi akatharistes apodoxes einai: %g \n", aka_apod);
    printf("to poso krathseon einai: %g \n", pos_krat);
    printf("oi kathares apodoxes einai: %g \n", kath_apod);
    return 0;
}
