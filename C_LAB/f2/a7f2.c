#include <stdio.h>
#include "genlib.h"
#include "simpio.h"

int main(){
    long kwd;
    double et_misth, amoibh, misthos_w;
    int wres_ebd;

    printf("Dwse ton kwdiko: ");
    kwd = GetLong();
    if (kwd >= 1000){
        printf("Dwse ton ethsio mistho: ");
        et_misth = GetReal();
        amoibh = et_misth / 52;
    }else{
        printf("Dwse tis wres ebdomadiaias egasias: ");
        wres_ebd = GetInteger();
        printf("Dwse thn amoibh ana wra: ");
        misthos_w = GetReal();
        amoibh = wres_ebd * misthos_w;
        if(wres_ebd > 40){
            amoibh += ((wres_ebd - 40) * misthos_w)* 0.5;
        }
    }
    printf("H ebdomadiaia amoibh einai %g\n", amoibh);

    return 0;
}
