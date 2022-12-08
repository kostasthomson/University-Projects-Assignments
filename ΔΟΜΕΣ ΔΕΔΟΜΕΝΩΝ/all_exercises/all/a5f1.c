
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define megisto_plithos 1001          //μέγιστο πλήθος στοιχείων συνόλου

typedef enum {
    FALSE, TRUE
} boolean;

typedef boolean typos_synolou[megisto_plithos];
typedef int stoixeio_synolou;
boolean isFibonacci(stoixeio_synolou candidate, typos_synolou fibonacci);
void createFibonacciSet(stoixeio_synolou threshold, typos_synolou synolo);
void Dimiourgia(typos_synolou synolo);
void Eisagogi(stoixeio_synolou stoixeio, typos_synolou synolo);
boolean Melos(stoixeio_synolou stoixeio, typos_synolou synolo);
void displayset(typos_synolou set);

int main()
{
    stoixeio_synolou max,tmp;
    typos_synolou fibonacci;

    do{
       printf("Dwse to megisto arithmo. ");
       scanf("%d", &max);
    }while(max<2 || max>1000);
    createFibonacciSet(max,fibonacci);
    displayset(fibonacci);
    do{
        printf("Enter number to check: ");
        scanf("%d", &tmp);
       if(tmp>0 && tmp<1000)
        {if(Melos(tmp, fibonacci))
             printf("Fibonacci!\n");
         else
            printf("Not Fibonacci\n");}
    } while(tmp>=0);


        return 0;

}
void displayset(typos_synolou set)
{
	stoixeio_synolou i;

	for (i=0; i < megisto_plithos; i++)
	{
		if(Melos(i,set))
			printf(" %d",i);
	}
	printf("\n");
}

void Dimiourgia(typos_synolou synolo)
/* Λειτουργία: Δημιουργεί ένα σύνολο χωρίς στοιχεία, δηλαδή το κενό σύνολο.
   Επιστρέφει: Το κενό σύνολο
*/
{
    stoixeio_synolou i;

    for (i = 0; i < megisto_plithos; i++)
        synolo[i] = FALSE;
}

void Eisagogi(stoixeio_synolou stoixeio, typos_synolou synolo)
/* Δέχεται:    Ένα σύνολο και ένα στοιχείο.
   Λειτουργία: Εισάγει το στοιχείο στο σύνολο.
   Επιστρέφει: Το τροποποιημένο σύνολο
*/
{
    synolo[stoixeio] = TRUE;
}

boolean Melos(stoixeio_synolou stoixeio, typos_synolou synolo)
/* Δέχεται:    Ένα σύνολο και ένα στοιχείο.
   Λειτουργία: Ελέγχει αν το στοιχείο είναι μέλος του συνόλου.
   Επιστρέφει: Επιστρέφει TRUE αν το στοιχείο είναι μέλος του και FALSE διαφορετικά
*/
{
    return synolo[stoixeio];
}

void createFibonacciSet(stoixeio_synolou threshold, typos_synolou synolo)
{
     stoixeio_synolou tmp,f1,f2;
     f1=0;
     f2=1;
     Dimiourgia(synolo);
     Eisagogi(f1,synolo);
      do{
         Eisagogi(f2,synolo);
         tmp=f1+f2;
         f1=f2;
         f2=tmp;
     } while(f2<threshold);

}
boolean isFibonacci(stoixeio_synolou candidate, typos_synolou fibonacci)
{
        if(Melos(candidate, fibonacci))
        	return TRUE;
    return FALSE;
}

