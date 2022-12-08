#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define megisto_plithos 201        //μέγιστο πλήθος στοιχείων συνόλου
#define F 2
#define L 200
typedef enum {
    FALSE, TRUE
} boolean;

typedef boolean typos_synolou[megisto_plithos];
typedef int stoixeio_synolou;

boolean isPrime(stoixeio_synolou n);
void createPrimeSet(stoixeio_synolou First, stoixeio_synolou Last, typos_synolou set);
void displayset(stoixeio_synolou First, stoixeio_synolou Last, typos_synolou set);
void Dimiourgia(typos_synolou synolo);
void Eisagogi(stoixeio_synolou stoixeio, typos_synolou synolo);
boolean Melos(stoixeio_synolou stoixeio, typos_synolou synolo);

int main()
{
    stoixeio_synolou First,Last;
    typos_synolou set;


    do{
        printf("Dwste arxikh timh (apo 2 ews 199 me arxikh timh < telikh timh): ");
    	scanf("%d",&First);
        printf("\n");
    }while(First<F || First>L);

     do{
        printf("Dwste teliki timh (apo 2 ews 200 me arxikh timh < telikh timh): ");
    	scanf("%d",&Last);
        printf("\n");
    }while((Last<F || Last>L)|| (First>=Last));
      printf("\n");

         createPrimeSet(First,Last,set);
         displayset(First,Last,set);

        return 0;
}
void Dimiourgia(typos_synolou set)
/* Λειτουργία: Δημιουργεί ένα σύνολο χωρίς στοιχεία, δηλαδή το κενό σύνολο.
   Επιστρέφει: Το κενό σύνολο
*/
{
    stoixeio_synolou i;

    for (i = 0; i < megisto_plithos; i++)
        set[i] = FALSE;
}

void Eisagogi(stoixeio_synolou n, typos_synolou set)
/* Δέχεται:    Ένα σύνολο και ένα στοιχείο.
   Λειτουργία: Εισάγει το στοιχείο στο σύνολο.
   Επιστρέφει: Το τροποποιημένο σύνολο
*/
{
    set[n] = TRUE;
}

boolean Melos(stoixeio_synolou n, typos_synolou set)
/* Δέχεται:    Ένα σύνολο και ένα στοιχείο.
   Λειτουργία: Ελέγχει αν το στοιχείο είναι μέλος του συνόλου.
   Επιστρέφει: Επιστρέφει TRUE αν το στοιχείο είναι μέλος του και FALSE διαφορετικά
*/
{
    return set[n];
}

boolean isPrime(stoixeio_synolou n)
{
    stoixeio_synolou i;
    boolean limit;
    limit=TRUE;
    for (i=2; i <= n/2; ++i) {
        if (n % i == 0)
            limit=FALSE;


    }
   return limit;

}
void createPrimeSet(stoixeio_synolou First, stoixeio_synolou Last, typos_synolou set)
{
     stoixeio_synolou i;
     Dimiourgia(set);
     for(i=First; i<= Last;++i)
     {
         if(isPrime(i))
            Eisagogi(i,set);
     }


}
void displayset(stoixeio_synolou First, stoixeio_synolou Last, typos_synolou set)
{
    stoixeio_synolou i;
    for (i = First; i<=Last; i++)
    {
        if(Melos(i,set))
           printf("%d ",i);
    }
    printf("\n");
}


