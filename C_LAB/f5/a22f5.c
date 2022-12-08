#include <stdio.h>
#include "genlib.h"
#include "simpio.h"
#include <math.h>


#define N   16


long long GetLongLong(void);
string valid_invalid(long long);
bool isValid(long long);
int dubl(int[N]);


int main(){
    long long num;
//Input
    printf("Insert card number: ");
    num = GetLongLong();
//Output
    printf("%lld is %s", num, valid_invalid(num));
    return 0;
}


long long GetLongLong(void){
    string line;
    long long value;
    char termch;

    while (TRUE) {
        line = GetLine();
        switch (sscanf(line, " %lld %c", &value, &termch)) {
          case 1:
            FreeBlock(line);
            return (value);
          case 2:
            printf("Unexpected character: '%c'\n", termch);
            break;
          default:
            printf("Please enter an integer\n");
            break;
        }
        FreeBlock(line);
        printf("Retry: ");
    }
}


/*Returns a string(valid or invalid)*/
string valid_invalid(long long num){
//isValid is a bool type function
   return(isValid(num)?"Valid":"invalid");
/*if(isValid(num)){return "VALID";}else{return "invalid";}*/
}


/*Returns bool value(True or False)*/
bool isValid(long long num){
    int dig[N];
    int i, k;
    long long number, x;
//Stores every digit to an array
    x = 10;
    for(i = N-1; i >= 0; i--){
        if(i != N-1){
            dig[i] = (num%x - dig[i+1]) / (x/10);
        }else{
            dig[i] = num%x;
        }
        x *= 10;
    }
//Finding the number from the array's elements
    k = 15;
    number = 0;
    for(i = 0; i < N; i++){
        number += dig[i]*pow(10,k);
        k--;
    }
//Statements that declare validity of the 16-digit number
    return ((number - num == 0) && (dig[0] >= 4 && dig[0] <= 7) && (dubl(dig)%10 == 0));
}


/*Returns the sum of the odd indexing elements*/
int dubl(int dig[N]){
    int count,i;
//Processing odd-indexing and even-indexing elements
    count = 0;
    for(i = 0; i < N; i ++){
        if((i+1)%2 == 0){
            count += dig[i];
        }else{
            if(dig[i] * 2 < 10){
                count += dig[i] * 2;
            }else{
                count += (dig[i] * 2 / 10) + (dig[i] * 2 % 10);
            }
        }
    }
    return count;
}
