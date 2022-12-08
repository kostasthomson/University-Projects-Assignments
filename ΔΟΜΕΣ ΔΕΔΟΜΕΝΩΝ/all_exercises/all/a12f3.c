
#include <ctype.h>
#include <stdlib.h>
#include <stdio.h>

#define QueueLimit 3  //το όριο μεγέθους της ουράς
typedef struct
{
    int start;
    int end;
    int arrivalTime;
    int stayTime;
} QueueElementType;

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
void TraverseQ(char name[50],QueueType Queue);
QueueType TimesInQueue(QueueType *Queue);
void ReadCustomer(QueueType *Queue);

int main()
{
    QueueType WaitingQueue,ServiceQueue;
    //QueueElementType i;
    int i;

    CreateQ(&WaitingQueue);

    for(i=0; i<QueueLimit; i++)
        ReadCustomer(&WaitingQueue);

    printf("Waiting Queue\n");
    TraverseQ("Waiting Queue", WaitingQueue);

    ServiceQueue = TimesInQueue(&WaitingQueue);
    TraverseQ("Waiting Queue", WaitingQueue);
    printf("Service Queue\n");
    TraverseQ("ServiceQueue",ServiceQueue);


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
    if(Queue.Count==0)
	 return (Queue.Front == Queue.Rear);
    else printf("queue is not empty");
}

boolean FullQ(QueueType Queue)
/* Δέχεται:    Μια ουρά.
   Λειτουργία: Ελέγχει αν η ουρά είναι γεμάτη.
   Επιστρέφει: True αν η ουρά είναι γεμάτη, False διαφορετικά
*/
{
    if(Queue.Count!=QueueLimit)
     return ((Queue.Front) == ((Queue.Rear +1) % QueueLimit));
    else printf("queue is not full");
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
		Queue -> Count ++;
	}
	else
		printf("Empty Queue");
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
		printf("Full Queue");
}
void TraverseQ(char name[50],QueueType Queue) {
	int current;
	int i=1;
	if(!(EmptyQ(Queue))){
        printf("%s\n",name);
	   current = Queue.Front;
	   printf("Client \t\tStart\tEnd\tArrival\tStay\n");
	   while (current != Queue.Rear)
       {
        printf("Client %d\t\t%d\t%d\t%d\t%d\n", i+1, Queue.Element[i].start, Queue.Element[i].end, Queue.Element[i].arrivalTime, Queue.Element[i].stayTime);
        current = (current + 1) % QueueLimit;
        i++;
       }
}
    else  printf("%s is empty\n",name);

	printf("\n");
}
void ReadCustomer(QueueType *Queue)
{
    int i=0;
    QueueElementType tmpCustomer;

        printf("Give: arrival time, stay time for client %d: ", i+1);
		scanf("%2d, %2d", &tmpCustomer.arrivalTime, &tmpCustomer.stayTime);
		tmpCustomer.start = tmpCustomer.end = -1;
		AddQ(Queue, tmpCustomer);
}
QueueType TimesInQueue(QueueType *Queue)
{
    int earliestStart =0;
    int currentStart=0;
    int currentEnd=0;

    QueueType QueueServiced;
    QueueElementType CurrentCust;

    CreateQ(&QueueServiced);
    while(!EmptyQ(*Queue))
    {
        RemoveQ(&(*Queue),&CurrentCust);
        if(CurrentCust.arrivalTime==earliestStart)
			CurrentCust.start = CurrentCust.arrivalTime;
		else
		    CurrentCust.start=earliestStart;
        currentEnd=CurrentCust.start+CurrentCust.stayTime;
        earliestStart=currentEnd;
        CurrentCust.start=earliestStart;
        CurrentCust.end=CurrentCust.start+CurrentCust.stayTime;;
        AddQ(&QueueServiced, CurrentCust);

    }
    return QueueServiced;
}
