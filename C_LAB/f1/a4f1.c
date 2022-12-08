#include <stdio.h>
#include "genlib.h"
#include "simpio.h"

int main(){
    int rate;
    double saleAmount, profit;
    long purchaseAmount;

    printf("dwse thn katharh axia: ");
    purchaseAmount = GetLong();

    printf("dwse to pososto kerdous: ");
    rate = GetInteger();

    profit = (double) purchaseAmount * rate/100;
    printf("to kerdos einai: %g\n", profit);

    saleAmount = purchaseAmount + profit;
    printf("to sinoliko poso einai: %g\n", saleAmount);

    return 0;
}
