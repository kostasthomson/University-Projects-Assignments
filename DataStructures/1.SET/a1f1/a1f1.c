#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define megisto_plithos 201

typedef enum {
    FALSE, TRUE
} boolean;

typedef boolean typos_synolou[megisto_plithos];
typedef int stoixeio_synolou;

void Dimiourgia(typos_synolou synolo);
void Eisagogi(stoixeio_synolou stoixeio, typos_synolou synolo);
boolean Melos(stoixeio_synolou stoixeio, typos_synolou synolo);
/*------------------------------------------ETOIMES-------------------------------------------------------*/
void createPrimeSet(stoixeio_synolou first, stoixeio_synolou last, typos_synolou synolo);
void displaySet(typos_synolou synolo, stoixeio_synolou first, stoixeio_synolou last);
boolean isPrime(int n);

int main(){
    stoixeio_synolou first, last;
    typos_synolou synolo;

    do{
        do{
            printf("Dwse first(2-200):");
            scanf("%d", &first);
        }while(first < 2 || first > 200);
        do{
            printf("Dwse last(2-200):");
            scanf("%d", &last);
        }while(last < 2 || last > 200);
    }while(first >= last);

    createPrimeSet(first, last, synolo);
    displaySet(synolo, first, last);
    return 0;
}

void createPrimeSet(stoixeio_synolou first, stoixeio_synolou last, typos_synolou synolo)
{
    stoixeio_synolou  i;

    Dimiourgia(synolo);
    for(i = first; i <=last; i++){
        if(isPrime(i)){
            Eisagogi(i, synolo);
        }
    }
}

void displaySet(typos_synolou synolo, stoixeio_synolou first, stoixeio_synolou last)
{
    stoixeio_synolou i;

    for(i=first; i<=last; i++){
        if(Melos(i, synolo)){
            printf("%d ", i);
        }
    }
}

boolean isPrime(int n)
{
    int i;

    for(i=2; i < n; i++){
        if(n%i==0){
            return FALSE;
        }
    }
    return TRUE;
}
/*------------------------------------------ETOIMES-------------------------------------------------------------------*/
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
