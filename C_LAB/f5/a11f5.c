#include <stdio.h>
#include "genlib.h"
#include "simpio.h"
#include <math.h>

#define CTS 10  //cities
#define S   3   //temperatures

int main(){
    double temper[CTS][S];
    int i, j;
    double natavg;
    double average[CTS];
    double devnat[CTS][S];
    double mdeviation[CTS];

    /* Read 3 temperatures for 10 cities */
    for(i=0; i<CTS; i++){
        for(j=0; j<S; j++){
            printf("Temp of City %d During %d 8-hour period: ", i, j);
            temper[i][j] = GetReal();
        }
    }

    /* Calculating the average of ALL cities & temperatures */
    natavg = 0;
    for(i=0; i<CTS; i++){
        for(j=0; j<S; j++){
                natavg += temper[i][j];
        }
    }
    natavg /= (CTS*S);

    /*Calculating the average temperatures for each city*/
    for(i=0; i<CTS; i++){
        average[i] = 0;
        for(j=0; j<S; j++){
            average[i] += temper[i][j];
        }
        average[i] /= S;
    }

    /*Calculating standard deviation*/
    for(i=0; i<CTS; i++){
        for(j=0; j<S; j++){
            devnat[i][j] = fabs(natavg - temper[i][j]);
        }
    }
    /*Calculating max deviation*/
    for(i=0; i<CTS; i++){
        mdeviation[i] = devnat[i][0];
        for(j=1; j<S; j++){
            if(mdeviation[i] < devnat[i][j]){
                mdeviation[i] = devnat[i][j];
            }
        }
    }

    /*Printing results*/
    printf("%3.1f\n", natavg);
    for(i=0; i<CTS; i++){
        printf("City %d %.1f %.1f\n", i, average[i], mdeviation[i]);
    }
    return 0;
}
