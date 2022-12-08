#include <stdio.h>
#include <math.h>
#include "genlib.h"
#include "simpio.h"

#define CTS 10
#define S 3

int main()
{
    double devnat[CTS][S], temper[CTS][S];
    double average[CTS], mdeviation[CTS];
    double natavg;
    int i, j;

	/*Read all Temperatures*/
	for (i=0; i<CTS; i++)
		for (j=0; j<S; j++)
		  	{ printf("Temp of City %d During %d 8-hour period: ",i,j);
              temper[i][j] = GetReal();
              }

	/*Calculating The Average of all Cities&Temps*/
    natavg = 0;
    for (i=0; i<CTS; i++)
      for (j=0; j<S; j+=1)
         natavg += temper[i][j];
    natavg = natavg/(CTS*S);

	/*Calculating Average temp on each City*/
	for (i=0; i<CTS; i++)
    {
        average[i] = 0;
        for (j=0; j<S; j++)
        {
            average[i] += temper[i][j];
        }
        average[i] = average[i]/S;
    }

	/*Calculating Standard Deviation*/
    for (i=0; i<CTS; i++)
        for (j=0; j<S; j++)
            devnat[i][j] = fabs(natavg-temper[i][j]);

	/*Calculating max Deviation*/
    for (i=0; i<CTS; i++)
    {
        mdeviation[i] = devnat[i][0];
        for(j=1; j<S; j++)
            if (mdeviation[i]<devnat[i][j]) mdeviation[i] = devnat[i][j];
    }

    /*Printing results*/
    printf("%3.1f\n", natavg);
    for (i=0; i<CTS; i+=1)
		printf("City %d  %.1f  %.1f\n",i, average[i], mdeviation[i]);
    system("PAUSE");
    return 0;
}
