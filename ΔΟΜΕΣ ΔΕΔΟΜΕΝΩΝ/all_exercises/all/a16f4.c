#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int vathmos;
    int kodikos;
} QueueElementType;           /* ο τύπος των στοιχείων της συνδεδεμένης λίστας
                                        ενδεικτικά τύπου int */
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

int main(){

    QueueType queue;
    QueueElementType item;
    int i,pl;

    CreateQ(&queue);
    printf("DWSE TO PLITHOS: ");
    scanf("%d",&pl);
    for(i=0; i<pl; i++)
    {
      printf("\nDWSE TON KODIKO TOU %dou KOMVOU: ",i+1);
      scanf("%d",&item.kodikos);
      printf("\nDWSE TO VATHMO PROTERAIOTITAS TOU %dou KOMVOU: ",i+1);
      scanf("%d",&item.vathmos);
      insert_prot(&queue,item);
    }
    printf("\n----------Priority Queue-------------\n");
    TraverseQ(queue);

 return 0;
}

void insert_prot(QueueType *Queue, QueueElementType Item)
{
    QueuePointer temp,pred,curr;
    boolean flag;
    temp=(QueuePointer)malloc(sizeof (struct QueueNode));
    temp->Data=Item;
    temp->Next=NULL;

    if(EmptyQ(*Queue))
    {
        Queue->Front=temp;
        Queue->Rear=temp;
    }
    else{
            pred=Queue->Front;
            curr=Queue->Front;
            flag=FALSE;
            if(curr->Data.vathmos > temp->Data.vathmos)
            {
                Queue->Front=temp;
                temp->Next=curr;
            }
            else{
                    while(curr!=NULL && flag==FALSE)
                    {
                        if(curr->Data.vathmos > temp->Data.vathmos)
                        {
                            pred->Next=temp;
                            temp->Next=curr;
                            flag=TRUE;
                        }
                        pred=curr;
                        curr=curr->Next;
                    }

            if(flag==FALSE)
             {
                pred->Next=temp;
                Queue->Rear=temp;
             }

            }
        }

}

void CreateQ(QueueType *Queue)
/* Λειτουργία: Δημιουργεί μια κενή συνδεδεμένη ουρά.
   Επιστρέφει: Μια κενή συνδεδεμένη ουρά
*/
{
	Queue->Front = NULL;
	Queue->Rear = NULL;
}

boolean EmptyQ(QueueType Queue)
/* Δέχεται:    Μια συνδεδεμένη ουρά.
   Λειτουργία: Ελέγχει αν η συνδεδεμένη ουρά είναι κενή.
   Επιστρέφει: True αν η ουρά είναι κενή, false  διαφορετικά
*/
{
	return (Queue.Front==NULL);
}

void AddQ(QueueType *Queue, QueueElementType Item)
/* Δέχεται:    Μια συνδεδεμένη ουρά Queue και ένα  στοιχείο Item.
   Λειτουργία: Προσθέτει το στοιχείο Item στο τέλος της συνδεδεμένης ουράς Queue.
   Επιστρέφει: Την τροποποιημένη ουρά
*/
{
	QueuePointer TempPtr;

    TempPtr= (QueuePointer)malloc(sizeof(struct QueueNode));
    TempPtr->Data = Item;
    TempPtr->Next = NULL;
    if (Queue->Front==NULL)
        Queue->Front=TempPtr;
    else
        Queue->Rear->Next = TempPtr;
    Queue->Rear=TempPtr;
}

void RemoveQ(QueueType *Queue, QueueElementType *Item)
/* Δέχεται:    Μια συνδεδεμένη ουρά.
   Λειτουργία: Αφαιρεί το στοιχείο Item από την  κορυφή της συνδεδεμένης ουράς,
                αν δεν είναι  κενή.
   Επιστρέφει: Το στοιχείο Item και την τροποποιημένη συνδεδεμένη ουρά.
   Έξοδος:     Μήνυμα κενής ουράς, αν η ουρά είναι  κενή
*/
{
    QueuePointer TempPtr;

    if (EmptyQ(*Queue)) {
   	    printf("EMPTY Queue\n");
    }
   else
   {
        TempPtr = Queue->Front;
        *Item=TempPtr->Data;
        Queue->Front = Queue->Front->Next;
        free(TempPtr);
        if (Queue->Front==NULL) Queue->Rear=NULL;
    }
}

void TraverseQ(QueueType Queue)
{
	QueuePointer CurrPtr;

   if (EmptyQ(Queue))
    {
   	    printf("EMPTY Queue\n");
    }
   else
   {
   	    CurrPtr = Queue.Front;
         while ( CurrPtr!=NULL )
        {
      	     printf("%d %d\n", CurrPtr->Data.vathmos,CurrPtr->Data.kodikos);
             CurrPtr = CurrPtr->Next;
        }
   }
    printf("\n");
}
