#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

#define StackLimit 50

typedef struct  {
    int price;
    char size[2];
} StackElementType;

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
boolean FullStack(StackType Stack);
void Push(StackType *Stack, StackElementType Item);
void Pop(StackType *Stack, StackElementType *Item);
int main()
{
    StackElementType  AnItem;
    StackType itemStack, tempStack;
    boolean found;
    char item[2];
    int n,i;

    CreateStack(&itemStack);
    CreateStack(&tempStack);
    printf("Give number of items ");
    scanf("%d",&n);
    printf("\n");

     printf("Give the items to store\n");
     for(i=0; i<n; i++)
    {
        printf("Give price ");
        scanf("%d",&AnItem.price);
        printf("Give size ");
        scanf("%s",&AnItem.size);
        Push(&itemStack,AnItem );
    }
     printf("\n");
     printf("items in the box\n");
     TraverseStack(itemStack);

     printf("\n");
     printf("What size do you want? ");
     scanf(" %s",item);

     found=FALSE;
     while(!(EmptyStack(itemStack))&& found==FALSE)
       {
           Pop(&itemStack,&AnItem);
           if (strcmp(item,AnItem.size)==0)
            found=TRUE;
           else Push(&tempStack,AnItem);
       }
       if(found==TRUE)
         printf("Found the size %s\n",item);
       else printf("Not found the size %s\n",item);

       printf("\n items in the box\n");
       TraverseStack(itemStack);
       printf("\n");

       printf("items out of the box\n");
       TraverseStack(tempStack);
       printf("\n");

       while(!(EmptyStack(tempStack)))
        {
            Pop(&tempStack,&AnItem);
            Push(&itemStack,AnItem);
        }

       printf("items in the box\n");
       TraverseStack(itemStack);
       printf("\n");

       printf("items out of the box\n");
       TraverseStack(tempStack);


    return 0;
}
void TraverseStack(StackType Stack)
{
    int i;
    printf("plithos sto stack %d",Stack.Top+1);
    for (i=0;i<=Stack.Top;i++) {
        printf("\n%s,%d",Stack.Element[i].size,Stack.Element[i].price);
    }
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

