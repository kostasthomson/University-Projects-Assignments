#include <stdio.h>
#include "genlib.h"
#include "simpio.h"

typedef struct{
    int width;
    int height;
    int depth;
    int area;
    int volume;
}box;


void get_data(box* shape);
void get_area(box* shape);
void get_vol(box* shape);

int main(){
    box shape;

    get_data(&shape);
    get_area(&shape);
    get_vol(&shape);

    printf("To emvadon tou koutiou einai %d cm2\n", shape.area);
    printf("O ogos tou koutiou einai %d cm3", shape.volume);
    return 0;
}

void get_data(box* shape){
    printf("Dose to mikos tou koutiou se cm: ");
    (*shape).width = GetReal();

    printf("Dose to ypsos tou koutiou se cm: ");
    (*shape).height = GetReal();

    printf("Dose to vathos toy koutiou se cm: ");
    (*shape).depth = GetReal();
}

void get_area(box* shape){
    int down, front, side;

    down = (*shape).width * (*shape).depth;
    front = (*shape).width * (*shape).height;
    side = (*shape).depth * (*shape).height;

    (*shape).area = 2 * (down + front + side);
}

void get_vol(box* shape){
    (*shape).volume = (*shape).width * (*shape).height * (*shape).depth;
}
