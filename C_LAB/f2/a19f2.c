#include <stdio.h>
#include "genlib.h"
#include "simpio.h"

int main() {
    int co;
    float telh;

    printf("Dwse gram CO2/khm: ");
    co = GetInteger();

    if (co  <=  120) {
        telh = co * 0.9;
    } else if (co  <=  140) {
        telh = co * 1.1;
    } else {
        telh = co * 1.7;
    }
    printf("To poso pliromis einai: %g", telh);
    return 0;
}
