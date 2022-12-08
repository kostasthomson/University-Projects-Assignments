
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define StackLimit 15

typedef int StackElementType;  // ο τύπος των στοιχείων  της στοίβας

typedef struct  {
    int Top;
    StackElementType Element[StackLimit];
} StackType;

typedef enum {
    FALSE, TRUE
} boolean;

void TraverseStack(StackType Stack);
void CreateStack(StackType *Stack);
boolean EmptyStack(StackType Stack);
void Push(StackType *Stack, StackElementType Item);
void Pop(StackType *Stack, StackElementType *Item);

int main()
{
    StackType S,tempS;
    int i,n;
    StackElementType x,temp;

    CreateStack(&S);

    for(i=0; i<=14; i++)
    {Push(&S,(i*10));}
    TraverseStack(S);

    printf("Give nth element (n<=6) ");
    scanf("%d",&n);
    printf("\n");
    Pop(&S,&x);
    Pop(&S,&x);
    printf("Question a: x=%d",x);
    TraverseStack(S);
    printf("\n");

    Pop(&S,&temp);
    Pop(&S,&x);
    printf("Question b: x=%d",x);
    Push(&S,x);
    Push(&S,temp);
    TraverseStack(S);
    printf("\n");

    for(i=0; i<n; i++)
    {Pop(&S,&x);}
    printf("Question c: x=%d",x);
    TraverseStack(S);
    printf("\n");

    CreateStack(&tempS);
    for(i=0;i<n;i++)
      {Pop(&S,&x);
       Push(&tempS,x);}

    printf("Question d: x=%d",x);

    while(!(EmptyStack(tempS)))
       {Pop(&tempS,&x);
        Push(&S,x);}
    TraverseStack(S);
    printf("\n");
    while(!(EmptyStack(S)))
      {Pop(&S,&x);
       Push(&tempS,x);}

    printf("Question e: x=%d",x);

    while(!(EmptyStack(tempS)))
      {Pop(&tempS,&x);
       Push(&S,x);}

    TraverseStack(S);
    printf("\n");

    while(S.Top>1)
    {Pop(&S,&x);
     Push(&tempS,x);}

     printf("Question f: x=%d",x);

    while(!(EmptyStack(tempS)))
    {Pop(&tempS,&x);
     Push(&S,x);}

    TraverseStack(S);
    printf("\n");

    while(!EmptyStack(S))
    {Pop(&S,&x);}

     printf("Question g: x=%d",x);
     TraverseStack(S);

     return 0;
}
void TraverseStack(StackType Stack)
{
 int i;
 printf("\nplithos sto stack %d\n",Stack.Top+1);
 for (i=0;i<=Stack.Top;i++)
 printf("%d ",Stack.Element[i]);
 printf("\n");
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

boolean FullStack(StackType Stack
                  /* Δέχεται: Μια στοίβα Stack.
   Λειτουργία: Ελέγχει αν η στοίβα Stack είναι γεμάτη.
   Επιστρέφει: True αν η Stack είναι γεμάτη, False διαφορετικά
*/)
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
