#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int Code;
    int Priority;
} QueueElementType;

typedef struct QueueNode *QueuePointer;

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

void CreateQ(QueueType *Queue);
boolean EmptyQ(QueueType Queue);
void AddQ(QueueType *Queue, QueueElementType Item);
void RemoveQ(QueueType *Queue, QueueElementType *Item);
void TraverseQ(QueueType Queue);
void insert_prot(QueueType *Queue, QueueElementType Item);

int main()
{
    QueueType Queue;
    QueueElementType person;
    int i, elements;

    printf("DWSE TO PLITHOS:");
    scanf("%d", &elements);

    CreateQ(&Queue);

    for(i=0;i<elements;i++)
    {
        printf("DWSE TON KODIKO TOU %dou KOMVOU:", i+1);
        scanf("%d", &person.Code);
        printf("DWSE TON VATHMO PROTERAIOTITAS TOU %dou KOMVOU:", i+1);
        scanf("%d", &person.Priority);
        insert_prot(&Queue, person);
        TraverseQ(Queue);
    }

    printf("----------Priority Queue-------------\n");
    TraverseQ(Queue);

    return 0;
}

void insert_prot(QueueType *Queue, QueueElementType Item)
{
    QueuePointer TempPtr, Curr, Pred;

    if(EmptyQ(*Queue) || Queue->Rear->Data.Priority <= Item.Priority)
        AddQ(Queue, Item);
    else
    {
        TempPtr = (QueuePointer)malloc(sizeof(struct QueueNode));
        TempPtr->Data = Item;

        Pred = Queue->Front;
        Curr = Queue->Front;
        do
        {
            if(Curr->Data.Priority > TempPtr->Data.Priority)
                break;
            Pred = Curr;
            Curr = Curr->Next;
        } while(TRUE);

        TempPtr->Next = Pred->Next;
        Pred->Next = TempPtr;
    }
}

void CreateQ(QueueType *Queue)
{
	Queue->Front = NULL;
	Queue->Rear = NULL;
}
boolean EmptyQ(QueueType Queue)
{
	return (Queue.Front == NULL);
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
      	     printf("%d %d\n", CurrPtr->Data.Priority, CurrPtr->Data.Code);
             CurrPtr = CurrPtr->Next;
        }
   }
    printf("\n");
}
