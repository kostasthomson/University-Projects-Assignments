#include <stdio.h>
#include "genlib.h"
#include "simpio.h"

int main(){
    double a, b, c, m;

    printf("Dwse vathmo A Triminou: ");
    a = GetReal();
    printf("Dwse vathmo B Triminou: ");
    b = GetReal();
    printf("Dwse vathmo C Triminou: ");
    c = GetReal();

    printf("O mesos oros tou mathiti einai %g", (a+b+c)/3);

    return 0;
}
