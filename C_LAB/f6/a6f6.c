#include <stdio.h>
#include "genlib.h"
#include "simpio.h"

#define N   5
#define col 4

void readData(int personal_data[][col]);
void FindMean(int personal_data[][col], int index, float* m_avg, float* f_avg);

int main(){
    int personal_data[N][col];
    int i;
    float m_avg, f_avg;

    readData(personal_data);
    for(i = 1; i < 4; i++){
        FindMean(personal_data, i, &m_avg, &f_avg);
        printf("Mesos oros %s andrwn: %.1f\n", i==1?"barous":i==2?"ypsous":"hlikias", m_avg);
        printf("Mesos oros %s gynaikwn: %.1f\n", i==1?"barous":i==2?"ypsous":"hlikias", f_avg);
        printf("\n");
    }
    return 0;
}

void readData(int personal_data[][col]){
    int i, j;

    for(i = 0; i < N; i++){
        for(j = 0; j < col; j+=4){
            printf("Dwse fylo:");
            personal_data[i][j] = GetInteger();
            printf("Dwse baros:");
            personal_data[i][j+1] = GetInteger();
            printf("Dwse ypsos:");
            personal_data[i][j+2] = GetInteger();
            printf("Dwse ilikia:");
            personal_data[i][j+3] = GetInteger();
        }
        printf("-----\n");
    }
}

void FindMean(int personal_data[][col], int index, float* m_avg, float* f_avg){
    int i;
    float mSum, fSum;
    int males, females;

    mSum = 0;
    fSum = 0;
    males = 0;
    females = 0;
    for(i = 0; i < N; i++){
        if(personal_data[i][0] == 0){
            mSum += personal_data[i][index];
            males++;
        }else{
            fSum += personal_data[i][index];
            females++;
        }
    }
    if(males!=0)
        *m_avg = mSum / males;
    else
        *m_avg = 0;

    if(females!=0)
        *f_avg = fSum / females;
    else
        *f_avg = 0;
}
