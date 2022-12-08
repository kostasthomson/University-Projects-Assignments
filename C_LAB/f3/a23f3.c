#include <stdio.h>
#include "genlib.h"
#include "simpio.h"

int main(){
    int n, i;
    printf("Enter number: ");
    n = GetInteger();
    //1st SOLUTION(short)
    for(i = (n % 2 ==0)?0:1; i <= n; i+=2){
        printf("%d ",i);
    }
    //2nd SOLUTION(longer)
    /*int s;
    if(n%2==0){
        s = 0;
    }else{
        s = 1;
    }
    printf("\n");
    for(i = s; i <= n; i+=2){
        printf("%d ",i);
    }*/
    return 0;
}
