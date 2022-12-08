// Filename: StackADT.c

/* ΥΛΟΠΟΙΗΣΗ ΣΤΟΙΒΑΣ ΔΥΝΑΜΙΚΑ ΜΕ ΔΕΙΚΤΕΣ*/

#include <stdio.h>
#include <stdlib.h>
#include "StackADT.h"

void CreateStack(StackPointer *Stack)
/* Λειτουργία: Δημιουργεί μια κενή συνδεδεμένη στοίβα. 
   Επιστρέφει: Μια κενή συνδεδεμένη στοίβα, Stack  
*/
{
	*Stack = NULL;
}

boolean EmptyStack(StackPointer Stack)
/* Δέχεται:     Μια συνδεδεμένη στοίβα, Stack.
   Λειτουργία:  Ελέγχει αν η Stack είναι κενή.
   Επιστρέφει:  TRUE αν η στοίβα είναι κενή, FALSE διαφορετικά
*/
{
	return (Stack==NULL);
}

void Push(StackPointer *Stack, StackElementType Item)
/* Δέχεται:    Μια συνδεδεμένη στοίβα που η κορυφή της δεικτοδοτείται από τον 
                δείκτη Stack και ένα στοιχείο Item. 
   Λειτουργία: Εισάγει στην κορυφή της συνδεδεμένης στοίβας, το στοιχείο Item. 
   Επιστρέφει: Την τροποποιημένη συνδεδεμένη στοίβα 
*/
{
	StackPointer TempPtr;

    TempPtr= (StackPointer)malloc(sizeof(struct StackNode));
    TempPtr->Data = Item; 
    TempPtr->Next = *Stack;
    *Stack = TempPtr;
}

void Pop(StackPointer *Stack, StackElementType *Item)
/* Δέχεται:    Μια συνδεδεμένη στοίβα που η κορυφή της δεικτοδοτείται από τον δείκτη Stack. 
   Λειτουργία: Αφαιρεί από την κορυφή της συνδεδεμένης στοίβας, 
                αν η στοίβα δεν είναι κενή, το στοιχείο Item. 
   Επιστρέφει: Την τροποποιημένη συνδεδεμένη στοίβα και το στοιχείο Item. 
   Έξοδος:     Μήνυμα κενής στοίβας, αν η συνδεδεμένη στοίβα είναι κενή 
*/
{
    StackPointer TempPtr;
    
    if (EmptyStack(*Stack)) {
   	    printf("EMPTY Stack\n");
    }
   else
   {
        TempPtr = *Stack;
        *Item=TempPtr->Data;
        *Stack = TempPtr->Next;     
        free(TempPtr);
    }
}



