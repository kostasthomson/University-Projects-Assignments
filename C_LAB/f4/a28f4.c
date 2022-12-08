#include <stdio.h>
#include "genlib.h"
#include "simpio.h"
#include <math.h>


int get_code();
double discount_percentage(int code);
int product_points(int code, double fprice);


int main(){
    int code, points;
    double price, finalPrice, discount, total, discountSum;
    total = discountSum = 0;
    points = 0;
    while(code = get_code()){
        printf("Dwse thn timh: ");
        price = GetReal();
        discount = discount_percentage(code)*price;
        finalPrice = price - discount;
        total += finalPrice;
        discountSum += discount;
        points += product_points(code, finalPrice);
    }
    printf("-------------\n");
    printf("Teliko synolo: %.2f Euro\n", total);
    printf("Ekptwsh: %.2f Euro\n", discountSum);
    printf("Pontoi: %d\n", points);
    return 0;
}


int get_code(){
    int code;
    while(TRUE){
        printf("Dwse ton kwdiko: ");
        code = GetInteger();
        if(code>=0 && code<=2000){
            return code;
        }
        printf("Lathos Kwdikos (0-2000)\n");
    }
}

double discount_percentage(int code){
    if(code<=300) return 0.05;
    if (code<=500) return 0.1;
    if (code<=1000) return 0.15;
    return 0.2;
}

int product_points(int code, double fprice){
    int points = 1;
    if(code>=1000 && code<=1500){
        points += ceil(fprice/5);
    }
    return points;
}
