#include <stdio.h>
#include <stdlib.h>

typedef int ListElementType;
typedef struct ListNode *ListPointer;

typedef struct ListNode
{
	ListElementType Data;
    ListPointer Next;
} ListNode;

typedef enum {
    FALSE, TRUE
} boolean;


void CreateList(ListPointer *List);
boolean EmptyList(ListPointer List);
void LinkedInsert(ListPointer *List, ListElementType Item, ListPointer PredPtr);
void LinkedDelete(ListPointer *List, ListPointer PredPtr);
void LinkedTraverse(ListPointer List);

ListElementType RemoveMins(ListPointer *InList);

int main()
{
    ListPointer list, pred;
    ListElementType item;
    int i, elements;

    CreateList(&list);

    printf("DWSE TO PLH8OS TWN STOIXEIWN THS LISTAS:");
    scanf("%d", &elements);

    pred = NULL;
    for(i=0;i<elements;i++)
    {
        printf("DWSE TON ARI8MO GIA EISAGWGH STHN ARXH THS LISTAS 1:");
        scanf("%d", &item);
        LinkedInsert(&list, item, pred);
    }

    printf("Traversing list\n");
    LinkedTraverse(list);

    printf("Removing min from list\n");
    printf("Min was %d\n", RemoveMins(&list));

    printf("Traversing list with min removed\n");
    LinkedTraverse(list);

    return 0;
}

ListElementType RemoveMins(ListPointer *InList)
{
    ListPointer cur, pred;
    ListElementType min;

    cur = *InList;
    min = cur->Data;
    while(cur != NULL)
    {
        if(cur->Data < min)
            min = cur->Data;
        cur = cur->Next;
    }

    pred = NULL;
    cur = *InList;
    while(cur!=NULL)
    {
        if(cur->Data==min)
        {
            cur = cur->Next;
            LinkedDelete(InList, pred);
        }
        else
        {
            pred = cur;
            cur = cur->Next;
        }
    }
    return min;
}


void CreateList(ListPointer *List)
{
	*List = NULL;
}

boolean EmptyList(ListPointer List)
{
	return (List==NULL);
}

void LinkedInsert(ListPointer *List, ListElementType Item, ListPointer PredPtr)
{
	ListPointer TempPtr;

   TempPtr= (ListPointer)malloc(sizeof(struct ListNode));
 /*  printf("Insert &List %p, List %p,  &(*List) %p, (*List) %p, TempPtr %p\n",
   &List, List,  &(*List), (*List), TempPtr); */
   TempPtr->Data = Item;
	if (PredPtr==NULL) {
        TempPtr->Next = *List;
        *List = TempPtr;
    }
    else {
        TempPtr->Next = PredPtr->Next;
        PredPtr->Next = TempPtr;
    }
}

void LinkedDelete(ListPointer *List, ListPointer PredPtr)
{
    ListPointer TempPtr;

    if (EmptyList(*List))
   	    printf("EMPTY LIST\n");
   else
   {
   	    if (PredPtr == NULL)
        {
      	      TempPtr = *List;
              *List = TempPtr->Next;
        }
        else
        {
      	     TempPtr = PredPtr->Next;
             PredPtr->Next = TempPtr->Next;
        }
        free(TempPtr);
    }
}

void LinkedTraverse(ListPointer List)
{
	ListPointer CurrPtr;

   if (EmptyList(List))
   	    printf("EMPTY LIST\n");
   else
   {
   	    CurrPtr = List;
         while (CurrPtr != NULL)
        {
             printf("%d ", CurrPtr->Data);
            CurrPtr = CurrPtr->Next;
        }
        printf("\n");
   }
}
