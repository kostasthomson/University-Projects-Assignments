#include <stdio.h>
#include <math.h>
#include "genlib.h"
#include "simpio.h"

#define Arithmo_Aytok   80000
#define Rythmos             0.07
#define Orio                    160000

int main(){
    long xronia, autokhnita;

    xronia = 0;
    autokhnita = Arithmo_Aytok;

    while (autokhnita < Orio){
        autokhnita = ceil(autokhnita*(1 + Rythmos));
        xronia++;
    }
    printf("%ld\n", xronia);
    printf("%ld\n", autokhnita);
    return 0;
}
