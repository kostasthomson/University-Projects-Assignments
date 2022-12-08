#include <stdio.h>
#include <stdlib.h>

#define QueueLimit 10  //το όριο μεγέθους της ουράς

typedef int QueueElementType;   /* ο τύπος δεδομένων των στοιχείων της ουράς
                                  ενδεικτικά τύπος int */

typedef struct {
	int Front, Rear, Count;
	QueueElementType Element[QueueLimit];
} QueueType;

typedef enum {FALSE, TRUE} boolean;

void CreateQ(QueueType *Queue);
boolean EmptyQ(QueueType Queue);
boolean FullQ(QueueType Queue);
void RemoveQ(QueueType *Queue, QueueElementType *Item);
void AddQ(QueueType *Queue, QueueElementType Item);
void TraverseQ(QueueType Queue);


int main(){
    int l;
    QueueElementType i, item;
    QueueType queue;

    CreateQ(&queue);
    for(l=97;l<=102;l++){
        printf("---%c---\n", l);
        switch (l)
        {
        case 97:/*case a*/
            for(i=0;i<QueueLimit;i++){
                AddQ(&queue, i);
            }
            TraverseQ(queue);
            printf("Front=%d Rear=%d Count=%d\n", queue.Front, queue.Rear, queue.Count);
            break;
        case 98:/*case b*/
            item = rand()%100;
            AddQ(&queue, item);
            TraverseQ(queue);
            printf("Front=%d Rear=%d Count=%d\n", queue.Front, queue.Rear, queue.Count);
            break;
        case 99:/*case c*/
            RemoveQ(&queue, &item);
            TraverseQ(queue);
            printf("Removed item=%d Front=%d Rear=%d Count=%d\n", item,queue.Front, queue.Rear, queue.Count);
            break;
        case 100:/*case d*/
            item = 25;
            AddQ(&queue, item);
            TraverseQ(queue);
            printf("Front=%d Rear=%d Count=%d\n", queue.Front, queue.Rear, queue.Count);
            break;
        case 101:/*case e*/
            item = rand()%100;
            AddQ(&queue, item);
            TraverseQ(queue);
            printf("Front=%d Rear=%d Count=%d\n", queue.Front, queue.Rear, queue.Count);
            break;
        case 102:/*case f*/
            while(!EmptyQ(queue)){
                RemoveQ(&queue, &item);
                TraverseQ(queue);
                printf("Removed item=%d Front=%d Rear=%d Count=%d\n", item,queue.Front, queue.Rear, queue.Count);
            }
            break;
        }
    }
    return 0;
}

void CreateQ(QueueType *Queue)
{
	Queue->Front = 0;
	Queue->Rear = 0;
    Queue->Count = 0;
}

boolean EmptyQ(QueueType Queue)
{
	return (Queue.Count == 0);
}

boolean FullQ(QueueType Queue)
{
	return (Queue.Count == QueueLimit);
}

void RemoveQ(QueueType *Queue, QueueElementType *Item)
{
	if(!EmptyQ(*Queue))
	{
		*Item = Queue ->Element[Queue -> Front];
		Queue ->Front  = (Queue ->Front + 1) % QueueLimit;
        Queue->Count -= 1;
	}
	else
		printf("Empty Queue\n");
}

void AddQ(QueueType *Queue, QueueElementType Item)
{
	if(!FullQ(*Queue))
	{
		Queue ->Element[Queue ->Rear] = Item;
		Queue ->Rear = (Queue ->Rear + 1) % QueueLimit;
        Queue->Count += 1;
    }
	else
		printf("Full Queue\n");
}

void TraverseQ(QueueType Queue) {
	int current;

	current = Queue.Front;

    printf("Queue: ");
    if(!EmptyQ(Queue)){
        while (/*current != Queue.Rear*/Queue.Count != 0) {
            printf("%d ", Queue.Element[current]);
            current = (current + 1) % QueueLimit;
            Queue.Count -= 1;
        }
    }else{
        printf("Empty Queue");
    }
	printf("\n");
}
