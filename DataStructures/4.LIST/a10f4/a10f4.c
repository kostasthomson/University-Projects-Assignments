#include <stdio.h>
#include <stdlib.h>

/*DEFINE DATA STRUCTURES TYPES AND DATA*/
typedef int StackElementType;

typedef struct StackNode *StackPointer;

typedef struct  StackNode
{
    StackElementType Data;
    StackPointer Next;
} StackNode;

typedef enum {
    FALSE, TRUE
} boolean;


/*CREATE METHODS*/
void CreateStack(StackPointer *Stack);
/*EMPTY METHODS*/
boolean EmptyStack(StackPointer Stack);
/*APPEND METHODS*/
void Push(StackPointer *Stack, StackElementType Item);
/*DELETE METHODS*/
void Pop(StackPointer *Stack, StackElementType *Item);
/*TRAVERSE METHODS*/
void TraverseStack(StackPointer Stack);


int main()
{
    StackPointer Stack1, Stack2;
    int i, elements, item;

    CreateStack(&Stack1);
    CreateStack(&Stack2);

    printf("PLITHOS STOIXEIWN:");
    scanf("%d", &elements);

    for(i=0;i<elements;i++)
    {
        printf("DWSE TO %do STOIXEIO:", i+1);
        scanf("%d", &item);
        Push(&Stack1, item);
    }

    printf("*********1i stoiva***********\n");
    TraverseStack(Stack1);
    
    while(!EmptyStack(Stack1))
    {
        Pop(&Stack1, &item);
        Push(&Stack2, item);
    }

    printf("*********2i stoiva***********\n");
    TraverseStack(Stack2);

    return 0;
}


/*CREATE METHODS----------------------------------------------------------------------------------------------------*/
void CreateStack(StackPointer *Stack) 
{
    *Stack = NULL;
}
/*EMPTY METHODS----------------------------------------------------------------------------------------------------*/
boolean EmptyStack(StackPointer Stack) 
{
    return (Stack == NULL);
}
/*APPEND METHODS----------------------------------------------------------------------------------------------------*/
void Push(StackPointer *Stack, StackElementType Item) 
{
    StackPointer TempPtr;

    TempPtr = (StackPointer)malloc(sizeof(struct StackNode));
    TempPtr->Data = Item;
    TempPtr->Next = *Stack;
    *Stack = TempPtr;
}
/*DELETE METHODS----------------------------------------------------------------------------------------------------*/
void Pop(StackPointer *Stack, StackElementType *Item) 
{
    StackPointer TempPtr;

    if(EmptyStack(*Stack))
        printf("EMPTY Stack\n");
    else
    {
        TempPtr = *Stack;
        *Item = TempPtr->Data;
        *Stack = TempPtr->Next;
        free(TempPtr);
    }
}
/*TRAVERSE METHODS----------------------------------------------------------------------------------------------------*/
void TraverseStack(StackPointer Stack)
{
	StackPointer CurrPtr;

   if (EmptyStack(Stack))
   	    printf("EMPTY Stack\n");
   else
   {
   	    CurrPtr = Stack;
         while ( CurrPtr!=NULL )
        {
      	     printf("%d ", CurrPtr->Data);
             CurrPtr = CurrPtr->Next;
        }
   }
    printf("\n");
}