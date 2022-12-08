#include <stdio.h>
#include <stdlib.h>
#include "genlib.h"
#include "simpio.h"

#define row 50

void populate(int rows, int table[rows]);
void printArr(int rows, int table[rows]);
int checkTable(int rows, int N, int table[rows], int indexes[rows]);

int main(){
    int N, pos, i;
    int a[row], indexes[row];

    populate(row, a);
    printArr(row, a);
    printf("\n------------\n");
    printf("Dose arithmo apo to 0 ews to 9: ");
    N = GetInteger();
    pos = checkTable(row, N, a, indexes);
    printf("\no Arithmos %d emfanizetai %d fores.\nStis Thesis:\n", N, pos);
    printArr(pos, indexes);
    printf("\n--------------\n");
    return 0;
}

void populate(int rows, int table[rows]){
    int i;

    for(i = 0; i < rows; i++){
        table[i] = rand() % 10;
    }
}

void printArr(int rows, int table[rows]){
    int i;

    for(i = 0; i < rows; i++){
        printf(" %d ", table[i]);
    }
}

int checkTable(int rows, int N, int table[rows], int indexes[rows]){
    int i, ind_row;

    ind_row = 0;
    for(i = 0; i < rows; i++){
        if(table[i] == N){
            indexes[ind_row] = i;
            ind_row++;
        }
    }
    return(ind_row);
}
