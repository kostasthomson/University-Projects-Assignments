#include <stdio.h>
#include <stdlib.h>
#include "genlib.h"
#include "simpio.h"

#define def_row 10
#define def_col 10

void populate_data(int row, int col, int r, int c, int table[row][col]);
void print_array(int row, int col, int r, int c, int table[row][col]);
void change_array(int row, int col, int r, int c, int table[row][col]);

int main(){
    int R, C;
    int A[def_row][def_col];
//define array length
    printf("Dwse ton arithmo twn grammwn: ");
    R = GetInteger();
    printf("Dwse ton arithmo twn sthlwn: ");
    C = GetInteger();
//populate data
    populate_data(def_row, def_col, R, C, A);
//starting array
    printf("ARXIKOS PINAKAS\n");
    print_array(def_row, def_col, R, C, A);
//change array
    change_array(def_row, def_col, R, C, A);
//changed array
    printf("ALLAGMENOS PINAKAS\n");
    print_array(def_row, def_col, R, C, A);
    return 0;
}

void populate_data(int row, int col, int r, int c, int table[row][col]){
    int i, j;

    for(i = 0; i < r; i++){
        for(j = 0; j < c; j++){
            table[i][j] = rand() % 100;
        }
    }
}

void print_array(int row, int col, int r, int c, int table[row][col]){
    int i, j;

    for(i = 0; i < r; i++){
        for(j = 0; j < c; j++){
           printf("%2d   ", table[i][j]);
        }
        printf("\n");
    }
}

void change_array(int row, int col, int r, int c , int table[row][col]){
    int i, j, max, max_index;

    for(i = 0; i < r; i++){
        max_index = j = 0;
        max = table[i][j];
        while(j < c){
            if(table[i][j] > max){
                max = table[i][j];
                max_index = j;
            }
            j++;
        }
        for(j = 0; j < max_index; j++){
            table[i][j] = max;
        }
    }
}
