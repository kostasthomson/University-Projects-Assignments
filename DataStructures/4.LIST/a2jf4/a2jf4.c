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

void insert_list_m_elements(ListPointer *List, int n);


int main()
{
    ListPointer list, pred;
    ListElementType item;
    int i, elements, n;

    CreateList(&list);

    printf("DWSE TO PLH8OS TWN STOIXEIWN THS LISTAS:");
    scanf("%d", &elements);

    pred = NULL;
    for(i=0;i<elements;i++)
    {
        printf("DWSE TON ARI8MO GIA EISAGWGH STHN ARXH THS LISTAS:");
        scanf("%d", &item);
        LinkedInsert(&list, item, pred);
    }

    printf("*********Arxiki lista************\n");
    LinkedTraverse(list);
    
    printf("DWSE TI THESI, META APO TIN OPOIA THA EISAXTHOUN TA STOIXEIA:");
    scanf("%d", &n);

    insert_list_m_elements(&list, n);

    printf("*********Teliki lista************\n");   
    LinkedTraverse(list);

    return 0;
}

void insert_list_m_elements(ListPointer *List, int n)
{
    ListPointer cur, pred;
    ListElementType data;
    int i, elements = 0;

    cur = *List;
    while(cur != NULL)
    {
        elements++;
        if(elements == n)
            pred = cur;
        cur = cur->Next;
    }

    if(n>elements)
    {
        printf("ERROR\n");
    }
    else
    {
        printf("DWSE TO PLITHOS TWN STOIXEIWN POU THA EISAXTHOUN:");
        scanf("%d", &elements);

        for(i=0;i<elements;i++)
        {
            printf("DWSE TON ARI8MO GIA EISAGWGH STHN ARXH THS LISTAS:");
            scanf("%d", &data);
            LinkedInsert(List, data, pred);
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
