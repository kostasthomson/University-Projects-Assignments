#include <stdio.h>
#include <math.h>
#include "genlib.h"
#include "simpio.h"

#define CTS 10
#define S 3

void ReadData(int row, int col, double p[row][col]);
double CalculateAverage(int row, int col, double p[row][col]);
void CalculateAvCity(int row, int col, double p[row][col], double a[row]);
void CalculateMaxDeviation(int row, int col,  double natavg, double p[row][col], double m[row]);
void PrintResults(int row, double natavg, double a[row], double m[row]);

int main()
{
    double temper[CTS][S];
    double average[CTS], mdeviation[CTS];
    double natavg;
    int i, j;

	/*Read all Temperatures*/
    ReadData(CTS, S, temper);

	/*Calculating The Average of all Cities&Temps*/
    natavg = CalculateAverage(CTS, S, temper);

	/*Calculating Average temp on each City*/
	CalculateAvCity(CTS, S, temper, average);

	/*Calculating Standard Deviation*/
	/*Calculating max Deviation*/
	CalculateMaxDeviation(CTS, S, natavg, temper, mdeviation);

    /*Printing results*/
    PrintResults(CTS, natavg, average, mdeviation);

    return 0;
}

void ReadData(int row, int col, double p[row][col]){
    int i, j;
    /*double initial[CTS][S] =    {   {10,20,30},
                                    {40,50,60},
                                    {70,80,90},
                                    {10,20,30},
                                    {40,50,60},
                                    {70,80,90},
                                    {10,20,30},
                                    {40,50,60},
                                    {70,80,90},
                                    {00,00,00}};*/
	for (i=0; i<row; i++){
		for (j=0; j<col; j++){
                printf("Temp of City %d During %d 8-hour period: ",i,j);
                p[i][j] = GetReal();
                //p[i][j] = initial[i][j];
        }
	}
}

double CalculateAverage(int row, int col, double p[row][col]){
    double natavg;
    int i,j;

    natavg = 0;
    for (i=0; i<row; i++){
      for (j=0; j<col; j+=1){
         natavg += p[i][j];
      }
    }
   return(natavg/(row*col));
}

void CalculateAvCity(int row, int col, double p[row][col], double a[row]){
    int i, j;

    for (i=0; i<row; i++){
        a[i] = 0;
        for (j=0; j<col; j++){
            a[i] += p[i][j];
        }
        a[i] = a[i]/col;
    }
}

void CalculateMaxDeviation(int row, int col, double natavg, double p[row][col], double m[row]){
    int i, j;

    for (i=0; i<row; i++){
        m[i] = fabs(natavg-p[i][0]);
        for(j=1; j<col; j++){
            if (m[i]<fabs(natavg-p[i][j])) {
                    m[i] = fabs(natavg-p[i][j]);
            }
        }
    }
}

void PrintResults(int row, double natavg, double a[row], double m[row]){
    int i;

    printf("%3.1f\n", natavg);
    for (i=0; i<row; i+=1)
		printf("City %d  %.1f  %.1f\n",i, a[i], m[i]);
}
