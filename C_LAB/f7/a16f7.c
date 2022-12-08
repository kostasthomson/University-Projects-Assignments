#include <stdio.h>
#include <string.h>

int main(){
    char str[100];
    char number[11];
    int digits[100];
    char op;
    int i, j, k, sum;

    strcpy(number, "0123456789\0");
    printf("Insert a string: ");
    gets(str);
    sum = 0;
    k =0;
    for(i=0; i<strlen(str);i++){
        for(j=0; j<10; j++){
            if(str[i] == number[j]){
                sum += j;
                digits[k] = j;
                k++;
                break;
            }
        }
    }
    if(k!=0){
        digits[k] = sum;
        k++;
        for(i=0; i<k; i++){
            if(i == k-2)
                op = '=';
            else if(i<k-2)
                op = '+';
            else
                op = ' ';
            printf("%d %c ", digits[i], op);
        }
    }else{
        printf("No digits in input.");
    }
    return 0;
}
