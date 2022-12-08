// Filename ListADT.c
/*                     (* YLOPOIHSH LISTAS ME PINAKA *)
              (*TA STOIXEIA THS LISTAS EINAI TYPOY integer*)
*/

#include <stdio.h>
#include <stdlib.h>
#include "ListADT.h"


void CreateList(ListType *List)
/* Λειτουργία: Δημιουργεί μια κενή λίστα.
   Επιστρέφει: Μια κενή λίστα
*/
{
    List -> Size = 0;
}

boolean EmptyList(ListType List)
/* Δέχεται:    Μια λίστα List.
   Λειτουργία: Ελέγχει αν η λίστα List είναι κενή.
   Επιστρέφει: True αν η λίστα List είναι άδεια, false διαφορετικά
*/
{
    return (List.Size == 0);
}

boolean FullList(ListType List)
/* Δέχεται:    Μια λίστα List.
   Λειτουργία: Ελέγχει αν η λίστα List είναι γεμάτη.
   Επιστρέφει: True αν η λίστα List είναι γεμάτη, false διαφορετικά
*/
{
    return (List.Size == (ListLimit));
}

void Insert(ListType *List, ListElementType Item, int Pos)
/* Δέχεται:    Μια λίστα List, το στοιχείο Item και τη θέση Pos μέσα στη λίστα.
   Λειτουργία: Εισάγει, στη λίστα List, αν δεν είναι γεμάτη, μετά τη θέση Pos
                το στοιχείο Item.
   Επιστρέφει: Την τροποποιημένη λίστα List.
   Εξοδος:     Mήνυμα γεμάτης λίστας, αν η λίστα List είναι γεμάτη
*/
{
    int i;
    if (FullList(*List))
        printf("Full list...\n");
    else
    {
        for (i=List->Size-1; i>=Pos+1;i--)
            List->Element[i+1] = List ->Element[i];
        List->Element[Pos+1]=Item;
        List->Size++;
    }
}

void Delete(ListType *List, int Pos)
/* Δέχεται:    Μια λίστα List.
   Λειτουργία: Διαγράφει από τη λίστα List, αν δεν είναι κενή,
                το στοιχείο που βρίσκεται στη θέση Pos.
   Επιστρέφει: Την τροποποιημένη λίστα List.
   Έξοδος:     Μήνυμα κενής λίστας, αν η λίστα List είναι κενή

*/
{
    int i;
    if (EmptyList(*List))
        printf("Empty list...\n");
    else
    {
        for (i=Pos; i<List->Size-1; i++)
            List->Element[i] = List ->Element[i+1];
        List->Size--;
    }
}

void TraverseList(ListType List)
/* Δέχεται:    Μια λίστα List.
   Λειτουργία: Κάνει διάσχιση της λίστα List, αν δεν είναι κενή.
   Έξοδος:     Εξαρτάται από την επεξεργασία
*/
{
    int i;
    if (EmptyList(List))
      	printf("Empty List\n");
    else
    {
        printf("\nPlithos stoixeiwn sth lista %d\n",List.Size);
        for (i=0;i<List.Size;i++)
            printf("%d ",List.Element[i]);
        printf("\n");
    }
}

