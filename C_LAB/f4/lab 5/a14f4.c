#include <stdio.h>
#include "genlib.h"
#include "simpio.h"

int max(int a, int b);
int gr(int a, int b, int c);

int main(){
    int a,b,c;
    double y;

    printf("Dwse a: ");
    a = GetInteger();
    printf("Dwse b: ");
    b = GetInteger();
    printf("Dwse c: ");
    c = GetInteger();
    y = (float)(2*max(a,b) + 3*gr(a,b,c)) / 4;
    printf("%.2f", y);
    return 0;
}


int max(int a, int b){
    if(a > b)
        return a;
    return b;
}


int gr(int a, int b, int c){
    if(a >= b && a >= c) return a;
    else if(b >= a && b >= c) return b;
    else if(c >= b && c >= a) return c;
}
