#include <stdio.h>
#include "genlib.h"
#include "simpio.h"


int gcd(int a, int b);
bool coprime(int a, int b);
int phi(int n);


int main(){
    int x;
    printf("Enter X: ");
    x = GetInteger();
    for(int i=1; i <= x; i++){
        printf("phi(%d) = %d\n", i, phi(i));
    }
    return 0;
}


int gcd(int a, int b){
    if(b == 0) return a;
    return gcd(b, a%b);
}

bool coprime(int a, int b){
    return(gcd(a,b) == 1);
}

int phi(int n){
    int count = 0;
    for(int i=1; i <= n; i++){
        if(coprime(i, n))
            count++;
    }
    return count;
}
