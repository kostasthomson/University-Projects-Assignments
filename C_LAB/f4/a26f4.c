#include <stdio.h>
#include "genlib.h"
#include "simpio.h"

int f(int);
int g(int, int);

int main(){
    int x, y;

    printf("Enter x: ");
    x = GetInteger();
    printf("Enter y: ");
    y = GetInteger();

    printf("f(x) = f(%d) = %d\n", x, f(x));
    printf("g(x,y) = g(%d,%d) = %d\n", x, y, g(x,y));
    printf("f(g(x,y)) = f(g(%d,%d)) = %d\n", x, y, f(g(x,y)));

    return 0;
}


int f(x){
    if(x > 0){
        return x+2;
    }else{
        return -1*3*x + 7;
    }
}

int g(x,y){
    if(x > 0 && y > 0){
        return x - y;
    }else{
        return 7*x - 5;
    }
}
