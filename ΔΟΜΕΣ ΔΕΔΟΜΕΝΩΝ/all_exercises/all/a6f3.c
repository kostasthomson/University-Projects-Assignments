#include <ctype.h>
#include <stdlib.h>
#include <stdio.h>

#define QueueLimit 10  //το όριο μεγέθους της ουράς

typedef int QueueElementType;   /* ο τύπος δεδομένων των στοιχείων της ουράς
                                  ενδεικτικά τύπος int */

typedef struct {
	int Front, Rear;
	QueueElementType Element[QueueLimit];
	int Count;
} QueueType;

typedef enum {FALSE, TRUE} boolean;

void CreateQ(QueueType *Queue);
boolean EmptyQ(QueueType Queue);
boolean FullQ(QueueType Queue);
void RemoveQ(QueueType *Queue, QueueElementType *Item);
void AddQ(QueueType *Queue, QueueElementType Item);
void TraverseQ(QueueType Queue);

int main()
{
    QueueType Queue;
    QueueElementType i,item;

    CreateQ(&Queue);

    printf("---a---\n");
    for(i=0; i<QueueLimit; i++)
        AddQ(&Queue,i);
    TraverseQ(Queue);
    printf("front:%d rear:%d queue:%d\n",Queue.Front,Queue.Rear,Queue.Count);

    printf("---b---\n");
    item=10;
    AddQ(&Queue,item);
    TraverseQ(Queue);
    printf("front:%d rear:%d queue:%d\n",Queue.Front,Queue.Rear,Queue.Count);

    printf("---c---\n");
    RemoveQ(&Queue,&item);
    TraverseQ(Queue);
    printf("Removed item:%d front:%d rear:%d queue:%d\n",item,Queue.Front,Queue.Rear,Queue.Count);

    printf("---d---\n");
    item=25;
    AddQ(&Queue,item);
    TraverseQ(Queue);
    printf("front:%d rear:%d queue:%d\n",Queue.Front,Queue.Rear,Queue.Count);

    printf("---e---\n");
    item=15;
    AddQ(&Queue,item);
    TraverseQ(Queue);
    printf("front:%d rear:%d queue:%d\n",Queue.Front,Queue.Rear,Queue.Count);

    printf("---f---\n");
    while(!EmptyQ(Queue)){
    RemoveQ(&Queue,&item);
    TraverseQ(Queue);
    printf("Removed item:%d front:%d rear:%d queue:%d\n",item,Queue.Front,Queue.Rear,Queue.Count);

    }

return 0;
}

void CreateQ(QueueType *Queue)
/*  Λειτουργία:  Δημιουργεί μια κενή ουρά.
    Επιστρέφει:  Κενή ουρά
*/
{

	Queue->Front = 0;
	Queue->Rear = 0;
	Queue->Count = 0;
}

boolean EmptyQ(QueueType Queue)
/* Δέχεται:    Μια ουρά.
   Λειτουργία: Ελέγχει αν η ουρά είναι κενή.
   Επιστρέφει: True αν η ουρά είναι κενή, False διαφορετικά
*/
{
    return(Queue.Count==0);
}

boolean FullQ(QueueType Queue)
/* Δέχεται:    Μια ουρά.
   Λειτουργία: Ελέγχει αν η ουρά είναι γεμάτη.
   Επιστρέφει: True αν η ουρά είναι γεμάτη, False διαφορετικά
*/
{
    return(Queue.Count==QueueLimit);

}

void RemoveQ(QueueType *Queue, QueueElementType *Item)
/* Δέχεται:    Μια ουρά.
   Λειτουργία: Αφαιρεί το στοιχείο Item από την εμπρός άκρη της ουράς
                αν η ουρά δεν είναι κενή.
   Επιστρέφει: Το στοιχείο Item και την τροποποιημένη ουρά.
   Έξοδος:     Μήνυμα κενής ουρά αν η ουρά είναι κενή
*/
{
	if(!EmptyQ(*Queue))
	{
		*Item = Queue ->Element[Queue -> Front];
		Queue ->Front  = (Queue ->Front + 1) % QueueLimit;
		Queue -> Count --;
	}
	else
		printf("Empty Queue\n");
}

void AddQ(QueueType *Queue, QueueElementType Item)
/* Δέχεται:    Μια ουρά Queue και ένα στοιχείο Item.
   Λειτουργία: Προσθέτει το στοιχείο Item στην ουρά Queue
                αν η ουρά δεν είναι γεμάτη.
   Επιστρέφει: Την τροποποιημένη ουρά.
   Έξοδος:     Μήνυμα γεμάτης ουράς αν η ουρά είναι γεμάτη
*/
{
	if(!FullQ(*Queue))
	{
		Queue ->Element[Queue ->Rear] = Item;
		Queue ->Rear = (Queue ->Rear + 1) % QueueLimit;
		Queue -> Count ++;
	}
	else
		printf("Full Queue\n");
}
void TraverseQ(QueueType Queue) {
	int current,i;
	printf("Queue: ");
	if(EmptyQ(Queue))
        printf("Empty Queue\n");
	current = Queue.Front;
	for (i=0; i<Queue.Count;i++) {
        printf("%d ", Queue.Element[current]);
		current = (current + 1) % QueueLimit;
	}

	printf("\n");
}
