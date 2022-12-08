// FILENAME StackADT.c                   
                    /* ΥΛΟΠΟΙΗΣΗ ΣΤΟΙΒΑΣ ΜΕ ΠΙΝΑΚΑ *
              *ΤΑ ΣΤΟΙΧΕΙΑ ΤΗΣ ΣΤΟΙΒΑΣ ΕΙΝΑΙ ΤΥΠΟΥ int*/
              
#include <stdio.h>
#include "StackADT.h"

void CreateStack(StackType *Stack) 
/* Λειτουργία: Δημιουργεί μια κενή στοίβα.
   Επιστρέφει: Κενή Στοίβα.*
*/
{
    Stack -> Top = -1;
   // (*Stack).Top = -1;
}

boolean EmptyStack(StackType Stack) 
/* Δέχεται: Μια στοίβα Stack. 
   Λειτουργία: Ελέγχει αν η στοίβα Stack είναι κενή. 
   Επιστρέφει: True αν η Stack είναι κενή, False διαφορετικά 
*/
{
    return (Stack.Top == -1);
}

boolean FullStack(StackType Stack) 
/* Δέχεται: Μια στοίβα Stack. 
   Λειτουργία: Ελέγχει αν η στοίβα Stack είναι γεμάτη. 
   Επιστρέφει: True αν η Stack είναι γεμάτη, False διαφορετικά 
*/
{
    return (Stack.Top == (StackLimit - 1));
}

void Push(StackType *Stack, StackElementType Item) 
/* Δέχεται: Μια στοίβα Stack και ένα στοιχείο Item. 
   Λειτουργία: Εισάγει το στοιχείο Item στην στοίβα Stack αν η Stack δεν είναι γεμάτη. 
   Επιστρέφει: Την τροποποιημένη Stack. 
   Έξοδος: Μήνυμα γεμάτης στοίβας, αν η στοίβα Stack είναι γεμάτη 
*/
{
    if (!FullStack(*Stack)) {
        Stack -> Top++;
        Stack -> Element[Stack -> Top] = Item;
    } else
        printf("Full Stack...");
}

void Pop(StackType *Stack, StackElementType *Item) 
/* Δέχεται: Μια στοίβα Stack. 
   Λειτουργία: Διαγράφει το στοιχείο Item από την κορυφή της Στοίβας αν η Στοίβα δεν είναι κενή. 
   Επιστρέφει: Το στοιχείο Item και την τροποποιημένη Stack. 
   Έξοδος:  Μήνυμα κενής στοίβας αν η Stack είναι κενή 
*/
{
    if (!EmptyStack(*Stack)) {
        *Item = Stack -> Element[Stack -> Top];
        Stack -> Top--;
    } else
        printf("Empty Stack...");
}


