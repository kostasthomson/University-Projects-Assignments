/*
Stock Market Analysis
 */

#include <stdio.h>
#include "genlib.h"

float find_max_tab(int size, float table[]);
int fill_int_tab(int size, float max, float table[], float intresting[]);
void separator(int p);
void print_tab_with_max(int size, float max, float table[]);
void print_tab(int size, float table[]);
float assess_cds(float el_cds, int el_risk);
void high_low(int row_in, int col_in, float table[][col_in], int* high, int* low);
bool element(float value, int row, int* pos, int r, int c, float table[r][c]);


int main(){
    float    stock_prices[10] =  {34.5, 22.4, 77.8, 22.1, 10.0, 11.25, 12, 13, 16, 20.5 };
    float    deriv_prices[5]  =  {30.5, 21.4, 89.8, 20.1, 10.0};
    float    cds_prices[11]   =  {38.5, 33.4, 67.8, 12.1, 16.0, 10.25, 11, 23, 36, 10.1 ,30.4};
    int      risk[11]         =  {90,10,20,30,50,60,30,30,30,10,10};

    float deriv_day_data[5][10] = {
                {30.5,25,22,32.3,30.5,32.6,38.9,40,22,30.5},
                {22.5,21.4,14,40.3,22.5,12.6,38.9,40,39,21.4},
                {30.5,25,22,89.8,34.5,89.8,38.9,40,30,89.8},
                {20.2,35,20.1,12.3,20.1,32.6,38.9,40,22,20.1},
                {45.5,10.0,22,10.0,14.5,23.6,48.9,8,10.0,10.0}
                                 };


    float interesting_stock[10];
    int ni_stock;
    float interesting_cds[11];
    int ni_cds;
    int high, low, pos;
    int i;
    float max_stock, max_deriv, max_cds, value;


    /* Calculating Max Values */
    max_stock = find_max_tab(10, stock_prices);
    max_deriv = find_max_tab(5, deriv_prices);
    max_cds   = find_max_tab(11, cds_prices);

    /* Finding Interesting Values */
    ni_stock = fill_int_tab(10, max_stock, stock_prices, interesting_stock);
    ni_cds   = fill_int_tab(11, max_cds, cds_prices, interesting_cds);

    /* Printing */
    printf("Stock Prices.\n");

    separator(30);

    print_tab_with_max(10, max_stock, stock_prices);
    printf("Interesting Stock Prices:");
    print_tab(ni_stock, interesting_stock);

    separator(10);

    /* Derivatives */
    printf("Derivative Prices.\n");
    separator(30);
    print_tab_with_max(5, max_deriv, deriv_prices);

    separator(10);

    /* Cds Prices */
    printf("CDS Prices.\n");
    separator(30);
    print_tab_with_max(11, max_cds, cds_prices);
    printf("Interesting CDS Prices:");
    print_tab(ni_cds, interesting_cds);

    separator(30);

    printf("CDS Assessment\n");
    for(i = 0; i < 11; i++){
        printf("CDS assessment: cds %4.2f Risk %d Value %4.2f\n", cds_prices[i], risk[i], assess_cds(cds_prices[i], risk[i]));
    }

    separator(30);

    printf("Derivative Low Hight\n");
    for(i = 0; i < 5; i++){
       high_low(i, 10,deriv_day_data, &high, &low);
       printf("Devirative %d, high %d / low %d values.\n", i, high, low);
    }

    separator(30);

    printf("Closing\n");
    for(i = 0; i < 5; i++){
        pos = 0;
        printf("Derivative %d, closing value at :: ", i);
        value = deriv_day_data[i][9];
        while(element(value, i, &pos, 5, 10, deriv_day_data)){
            printf("%d ", pos);
            pos++;
        }
        printf("\n");
    }
    return 0;
}


float find_max_tab(int size, float table[]){
    int i;
    float max;

    max = table[0];
    for(i = 1; i < size; i++){
        if(table[i] > max){
            max = table[i];
        }
    }
    return max;
}

int fill_int_tab(int size, float max, float table[], float interesting[]){
    int i, ni;

    ni=0;
    for(i = 0; i < size; i++){
        if(table[i] > max / 2){
                interesting[ni++] = table[i];
        }
    }
    return ni;
}

void separator(int p){
    int i;

    for(i = 0; i < p; i++)
        printf("-");
    printf("\n");
}

void print_tab_with_max(int size, float max, float table[]){
    int i;

    printf("Max Price:: %4.2f \n",max);
    for(i = 0; i < size; i++)
      printf("%s(%3.2f) ",(max == table[i] ? "-Max-" : ""),table[i]);
   printf("\n");
}

void print_tab(int size, float table[]){
    int i;

    for(i = 0; i < size; i++) printf("[%4.2f] ",table[i]);
    printf("\n");
}

float assess_cds(float el_cds, int el_risk){
    if(el_cds < 20 && el_risk < 50) return 20;
    if(el_cds >= 20 && el_risk < 80) return 10+(el_cds * el_risk)/100;
    return 100+(el_cds * el_risk)/100;
}

void high_low(int row_in, int col_in, float table[][col_in], int* high, int* low){
    int i;

    *high = 0;
    *low = 0;
    for(i = 0; i < col_in-1; i++){
        if(table[row_in][i] < table[row_in][9]){
            (*low)++;
        }
        if(table[row_in][i] > table[row_in][9]){
            (*high)++;
        }
    }
}

bool element(float value, int row, int* pos, int r, int c, float table[r][c]){
    int i;

    for(i = *pos; i < c; i++){
        if(value == table[row][i]){
            *pos = i;
            return TRUE;
        }
    }

    return FALSE;
}
