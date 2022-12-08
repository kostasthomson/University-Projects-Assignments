#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*DEFINE DATA STRUCTURES TYPES AND DATA*/
typedef char StackElementType;
typedef char QueueElementType;

typedef struct StackNode *StackPointer;
typedef struct QueueNode *QueuePointer;

typedef struct  StackNode
{
    StackElementType Data;
    StackPointer Next;
} StackNode;

typedef struct QueueNode
{
    QueueElementType Data;
    QueuePointer Next;	
} QueueNode;
typedef struct
{
    QueuePointer Front;
    QueuePointer Rear;
} QueueType;

typedef enum {
    FALSE, TRUE
} boolean;


/*CREATE METHODS*/
void CreateStack(StackPointer *Stack);
void CreateQ(QueueType *Queue);
/*EMPTY METHODS*/
boolean EmptyStack(StackPointer Stack);
boolean EmptyQ(QueueType Queue);
/*APPEND METHODS*/
void Push(StackPointer *Stack, StackElementType Item);
void AddQ(QueueType *Queue, QueueElementType Item);
/*DELETE METHODS*/
void Pop(StackPointer *Stack, StackElementType *Item);
void RemoveQ(QueueType *Queue, QueueElementType *Item);
/*TRAVERSE METHODS*/
void TraverseStack(StackPointer Stack);
void TraverseQ(QueueType Queue);



int main()
{
    StackPointer Stack;
    QueueType Queue;
    char itemS, itemQ;
    char word[50];
    int i, sum;

    CreateStack(&Stack);
    CreateQ(&Queue);

    printf("DWSE TO ALFARITHMITIKO:");
    scanf("%[^\n]%*c",word);

    for(i=0;i<strlen(word);i++)
    {   
        AddQ(&Queue, word[i]);
        Push(&Stack, word[i]);
    }

    printf("-------Stack of characters-------\n");
    TraverseStack(Stack);
    printf("-------Queue of characters-------\n");
    TraverseQ(Queue);

    for(i=0;i<strlen(word);i++)
    {
        Pop(&Stack, &itemS);
        RemoveQ(&Queue, &itemQ);
        if(itemS == itemQ)
            sum++;
    }
    
    if(sum == strlen(word))
        printf("%s ACCEPTED", word);
    else
        printf("%s REJECTED", word);
    printf("\n");
    return 0;
}

/*CREATE METHODS----------------------------------------------------------------------------------------------------*/
void CreateStack(StackPointer *Stack) 
{
    *Stack = NULL;
}
void CreateQ(QueueType *Queue)
{
	Queue->Front = NULL;
	Queue->Rear = NULL;
}
/*EMPTY METHODS----------------------------------------------------------------------------------------------------*/
boolean EmptyStack(StackPointer Stack) 
{
    return (Stack == NULL);
}
boolean EmptyQ(QueueType Queue)
{
	return (Queue.Front == NULL);
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
void AddQ(QueueType *Queue, QueueElementType Item)
{
	QueuePointer TempPtr;

    TempPtr = (QueuePointer)malloc(sizeof(struct QueueNode));
    TempPtr->Data = Item;
    TempPtr->Next = NULL;
    if(Queue->Front == NULL)
        Queue->Front = TempPtr;
    else
        Queue->Rear->Next = TempPtr;
    Queue->Rear = TempPtr;
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
void RemoveQ(QueueType *Queue, QueueElementType *Item)
{
	QueuePointer TempPtr;

    if(EmptyQ(*Queue))
        printf("EMPTY Queue\n");
    else
    {
        TempPtr = Queue->Front;
        *Item = TempPtr->Data;
        Queue->Front = Queue->Front->Next;
        free(TempPtr);
        if(Queue->Front == NULL)
            Queue->Rear = NULL;
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
      	     printf("%c ", CurrPtr->Data);
             CurrPtr = CurrPtr->Next;
        }
   }
    printf("\n");
}
void TraverseQ(QueueType Queue)
{
	QueuePointer CurrPtr;

   if (EmptyQ(Queue))
   	    printf("EMPTY Queue\n");
   else
   {
   	    CurrPtr = Queue.Front;
         while ( CurrPtr!=NULL )
        {
      	     printf("%c ", CurrPtr->Data);
             CurrPtr = CurrPtr->Next;
        }
   }
    printf("\n");
}
