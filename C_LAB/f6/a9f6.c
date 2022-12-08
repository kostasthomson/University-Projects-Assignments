#include <stdio.h>
#include "genlib.h"
#include "simpio.h"

#define SALESMEN    4
#define PRODUCTS    5


void calculateSales(int S, int P, int salesTable[S][P], int price[], int sp[]);
void calculateProductSales(int S, int P, int salesTable[S][P], int prods[]);
void maxArray(int size, int table[], int *max, int *pos);
void printArray(int size, int table[]);


int main(){
    int salesPerson[SALESMEN], productSale[SALESMEN];
    int price[PRODUCTS] = {250, 150, 320, 210, 920};
    int sales[SALESMEN][PRODUCTS] = {
                {10, 4, 5, 6, 7},
                {7, 0, 12, 1, 3},
                {4, 19, 5, 0, 8},
                {3, 2, 1, 5, 6}};
    int MaxSalesMan, MaxProduct;
    int income, items;
//sales
    printf("SalesMan-Sales \n");
    calculateSales(SALESMEN, PRODUCTS, sales, price, salesPerson);
    printArray(SALESMEN, salesPerson);
    maxArray(SALESMEN, salesPerson, &MaxSalesMan,&income);
    printf("Best SalesMan was %d with %d sales\n", income, MaxSalesMan);
//product
    printf("Product-Items \n");
    calculateProductSales(SALESMEN, PRODUCTS, sales, productSale);
    printArray(PRODUCTS, productSale);
    maxArray(SALESMEN, productSale, &MaxProduct, &items);
    printf("Best Product was %d with %d items\n", items, MaxProduct);
    return 0;
}


void calculateSales(int S, int P, int salesTable[S][P], int price[], int sp[]){
    int i,j;
    for(i = 0; i < S; i++){
        sp[i] = 0;
        for(j = 0; j < P; j++){
            sp[i] += salesTable[i][j] * price[j];
        }
    }
}

void calculateProductSales(int S, int P, int salesTable[S][P], int prods[]){
    int i, j;
    for(i = 0; i < P; i++){
        prods[i] = 0;
        for(j = 0; j < S; j++){
            prods[i] += salesTable[j][i];
        }
    }
}

void maxArray(int size, int table[], int *max, int *pos){
    int i;
    *max = table[0];
    *pos = 0;
    for(i = 1; i < size; i++){
        if(*max < table[i]){
            *max = table[i];
            *pos = i;
        }
    }
}

void printArray(int size, int table[]){
    int i;
    for(i = 0; i < size; i++){printf("    %d    %d\n", i, table[i]);}
}
