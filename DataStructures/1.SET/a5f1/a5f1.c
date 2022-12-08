#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define megisto_plithos 1001

typedef enum {
    FALSE, TRUE
} boolean;

typedef boolean typos_synolou[megisto_plithos];
typedef int stoixeio_synolou;

void Dimiourgia(typos_synolou synolo);
void Eisagogi(stoixeio_synolou stoixeio, typos_synolou synolo);
void displayset(typos_synolou set);
boolean Melos(stoixeio_synolou stoixeio, typos_synolou synolo);
/*--------------------ETOIMES-------------------------*/

boolean isFibonacci(stoixeio_synolou n, typos_synolou);
void createFibonacciSet(int threshold, typos_synolou synolo);

int main()
{
    stoixeio_synolou max;
    stoixeio_synolou num;
    typos_synolou synolo;

    do{
        printf("Dwse to megistoarithmo. ");
        scanf("%d", &max);
    }while(max<2 || max>1000);
    createFibonacciSet(max, synolo);
    displayset(synolo);
    do{
        printf("Enter number to check: ");
        scanf("%d", &num);
        if(num<0) break;
        if(num <= 1000) printf("%s\n",(isFibonacci(num, synolo))?"Fibonacci!":"Not Fibonacci...");
    }while(num>=0);
    return 0;
}

boolean isFibonacci(stoixeio_synolou n, typos_synolou synolo)
{
    return(Melos(n, synolo));
}

void createFibonacciSet(int threshold, typos_synolou synolo)
{
    stoixeio_synolou fib0=0, fib1=1, i;
    stoixeio_synolou fib;

    Dimiourgia(synolo);
    for(i=0;i<=threshold;i++){
        if(i<=1){
            fib=i;
        }else{
            fib=fib0+fib1;
            fib0=fib1;
            fib1=fib;
        }
        if(fib>threshold) break;
        Eisagogi(fib, synolo);
    }
}

/*--------------------ETOIMES-------------------------*/
void Dimiourgia(typos_synolou synolo)
{
    stoixeio_synolou i;

    for (i = 0; i < megisto_plithos; i++)
        synolo[i] = FALSE;
}

void Eisagogi(stoixeio_synolou stoixeio, typos_synolou synolo)
{
    synolo[stoixeio] = TRUE;
}

boolean Melos(stoixeio_synolou stoixeio, typos_synolou synolo)
{
    return synolo[stoixeio];
}

void displayset(typos_synolou set)
{
	stoixeio_synolou i;

	for (i=0;i < megisto_plithos;i++)
	{
		if(Melos(i,set))
			printf(" %d",i);
	}
	printf("\n");
}
