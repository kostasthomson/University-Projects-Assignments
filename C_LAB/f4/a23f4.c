#include <stdio.h>
#include "genlib.h"
#include "simpio.h"

bool Valid_Time(int, int, int);

int main(){
    int hours, mins, secs;
    printf("Dwse tis ores: ");
    hours = GetInteger();

    printf("Dwse ta lepta: ");
    mins = GetInteger();

    printf("Dwse ta defterolepta: ");
    secs = GetInteger();

    if(Valid_Time(hours,mins, secs)){
        printf("WRA EGKYRH");
    }else{
        printf("WRA MH EGKYRH");
    }
    return 0;
}


bool Valid_Time(hours, mins, secs){
    return((hours>=0&&hours<=23)&&(mins>=0&&mins<=59)&&(secs>=0&&secs<=59));
}
