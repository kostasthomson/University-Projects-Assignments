#include <stdio.h>
#include <math.h>
#include "genlib.h"
#include "simpio.h"

int main(){
    long xronia, Arithmo_Aytok, Orio;
    double Rythmos;

    printf("Dwse arxiko arithmo aytokinhtwn: ");
    Arithmo_Aytok = GetLong();
    printf("Dwse ethsio arithmo ayxishs: ");
    Rythmos = GetReal();
    printf("Dwse to orio: ");
    Orio = GetLong();
    xronia = 0;
    while (Arithmo_Aytok < Orio){
        Arithmo_Aytok = ceil(Arithmo_Aytok*(1 + Rythmos));
        xronia++;
    }
    printf("%ld\n", xronia);
    printf("%ld\n", Arithmo_Aytok);
    return 0;
}
