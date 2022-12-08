#include <stdio.h>
#include "genlib.h"
#include "simpio.h"

int main(){
    int coffees,change, remain;
    double cost;

    printf("Dose kafedes: ");
    coffees = GetInteger();
    cost = coffees * 0.7;

    if (cost <= 5){
        //find the rest of the subtraction
        cost -= 5;
        cost *=  (-10);

        printf("Resta\n");
        //calculate and print the results

        //2E
        change = (int)cost / 20;
        remain = (int)cost % 20;
        printf("Kermata 2E: %d\n",change);

        //1E
        change = remain / 10;
        remain = remain % 10;
        printf("Kermata 1E: %d\n",change);

        //50L
        change = remain / 5;
        remain = remain % 5;
        printf("Kermata 50L: %d\n",change);

        //20L
        change = remain / 2;
        printf("Kermata 20L: %d\n",change);

        //10L
        change = remain% 2;
        printf("Kermata 10L: %d\n",change);

    }else{
        printf("den ftanoun ta xrhmata gia tosous kafedes");
    }
    return 0;
}
