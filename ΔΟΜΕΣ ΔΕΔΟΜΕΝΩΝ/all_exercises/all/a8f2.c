#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

#define StackLimit 50

typedef char StackElementType;   // ο τύπος των στοιχείων  της στοίβας

typedef struct  {
    int Top;
    StackElementType Element[StackLimit];
} StackType;

typedef enum {
    FALSE, TRUE
} boolean;

void CreateStack(StackType *Stack);
boolean EmptyStack(StackType Stack);
boolean FullStack(StackType Stack);
void Push(StackType *Stack, StackElementType Item);
void Pop(StackType *Stack, StackElementType *Item);
int main()
{
    StackElementType ch, item;
    StackType S;
    boolean valid, flag;

    flag=FALSE;
    valid=TRUE;
    CreateStack(&S);

    printf("Enter string: \n");
    scanf("%c", &ch);
    getchar();

    if(ch=='#')
        return 0;
    while(!(ch=='#')&& valid==TRUE)
    {
        if(flag==FALSE)
        {

            if(ch=='C')
            {
                flag=TRUE;
                scanf("%c", &ch);
                getchar();
            }
            else
            {
                 Push(&S,ch);
                 scanf("%c", &ch);
                 getchar();
            }
        }
        else
        {

            if(!(EmptyStack(S)))
            {
                Pop(&S,&item);
                if(item!=ch)
                    valid=FALSE;
                else
                {
                    scanf("%c", &ch);
                    getchar();
                }
            }
            else valid=FALSE;

    }
    }
      if((valid==TRUE) && (EmptyStack(S)))
        printf("TRUE");
      else  printf("FALSE");


  return 0;
}

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

