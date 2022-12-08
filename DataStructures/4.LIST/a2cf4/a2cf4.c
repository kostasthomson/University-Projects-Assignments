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

void concat_list(ListPointer List, ListPointer BList, ListPointer *FinalList);


int main()
{
    ListPointer alist, blist, conlist,pred;
    ListElementType item;
    int i, elements;
    
    CreateList(&alist);
    CreateList(&blist);

//A-list
    printf("DWSE TO PLH8OS TWN STOIXEIWN THS LISTAS 1:");
    scanf("%d", &elements);
    
    pred = NULL;
    for(i=0;i<elements;i++)
    {
        printf("DWSE TON ARI8MO GIA EISAGWGH STHN ARXH THS LISTAS 1:");
        scanf("%d", &item);
        LinkedInsert(&alist, item, pred);
    }

//B-list
    printf("DWSE TO PLH8OS TWN STOIXEIWN THS LISTAS 2:");
    scanf("%d", &elements);
    
    pred = NULL;
    for(i=0;i<elements;i++)
    {
        printf("DWSE TON ARI8MO GIA EISAGWGH STHN ARXH THS LISTAS 2:");
        scanf("%d", &item);
        LinkedInsert(&blist, item, pred);
    }
    
//alist and blist
    printf("LISTA 1:\n");
    LinkedTraverse(alist);
    printf("LISTA 2:\n");
    LinkedTraverse(blist);

//concatinated-list
    printf("SYNENWMENH LISTA:\n");
    concat_list(alist, blist, &conlist);
    LinkedTraverse(conlist);

    return 0;
}

void concat_list(ListPointer List, ListPointer BList, ListPointer *FinalList)
{
    ListPointer curr, pred;
    boolean done;

    CreateList(FinalList);

    pred = NULL;
    curr = List;
    done = FALSE;
    while (curr != NULL)
    {
        LinkedInsert(FinalList, curr->Data, pred);
        curr = curr->Next; 
        if(curr == NULL && !done)
        {
            curr = BList;
            done = TRUE;
        }
    }
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
