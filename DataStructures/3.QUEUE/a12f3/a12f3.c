#include <stdio.h>
#include <string.h>
#include <stdlib.h>



#define QueueLimit 4  //το όριο μεγέθους της ουράς



typedef struct

{

	int start;

	int end;

	int arrivalTime;

	int stayTime;

} QueueElementType;   /* ο τύπος δεδομένων των στοιχείων της ουράς

                                  ενδεικτικά τύπος int */



typedef struct {

	int Front, Rear;

	QueueElementType Element[QueueLimit];

} QueueType;



typedef enum {FALSE, TRUE} boolean;



void CreateQ(QueueType *Queue);

boolean EmptyQ(QueueType Queue);

boolean FullQ(QueueType Queue);

void RemoveQ(QueueType *Queue, QueueElementType *Item);

void AddQ(QueueType *Queue, QueueElementType Item);

void TraverseQ(QueueType Queue, char name[]);

//---------------------------------------------------------------------------------

void Client_properties(QueueType *Queue);

QueueType TimesInQueue(QueueType *Queue);



int main()
{
//initializing queues
	QueueType waiting, service;
	char name[20];
//creating waiting queue
	CreateQ(&waiting);
//setup waiting queue
	Client_properties(&waiting);
//printing waiting queue
	//printf("Waiting Queue\n");
	strcpy(name, "Waiting Queue");
	TraverseQ(waiting, name);
//setup service queue
	service = TimesInQueue(&waiting);
//printing waiting queue info
	printf("\nWaiting Queue is empty\n");
//printing service queue
	//printf("Service Queue\n");
	strcpy(name, "Service Queue");
	TraverseQ(service, name);

	return 0;
}



QueueType TimesInQueue(QueueType *Queue)
{
	int i=0;
	QueueElementType client, prev_client;
	QueueType service;

	CreateQ(&service);

	while(!EmptyQ(*Queue))
	{
		RemoveQ(Queue, &client);

		if(i==0)
		{
			client.start = client.arrivalTime;
		}
		else
		{
			if(prev_client.end<=client.arrivalTime)
			{
				client.start = client.arrivalTime;
			}
			else
			{
				client.start = prev_client.end;
			}
		}
		client.end = client.start + client.stayTime;

		AddQ(&service, client);

		prev_client = client;
		i++;
	}
	return service;
}



void Client_properties(QueueType *Queue)
{
	int i=0;
	QueueElementType client;

	do{
		printf("Give: arrival time, stay time for client %d: ", i+1);
		scanf("%2d, %2d", &client.arrivalTime, &client.stayTime);
		client.start = client.end = -1;
		AddQ(Queue, client);
		i++;
	}while(!FullQ(*Queue));

}

//---------------------------------------------------------------------------------
void TraverseQ(QueueType Queue, char name[])
{
    int i=1;
    QueueElementType client;

    if(EmptyQ(Queue))
    {
        printf("\ns is empty\n", name);
    }
    else
    {
        printf("%s\n", name);
        printf("Client  \t\tStart\tEnd\tArrival\tStay\n");
        while(!EmptyQ(Queue))
        {
            RemoveQ(&Queue, &client);
            printf("Client %d\t\t%d\t%d\t%d\t%d\n", i, client.start, client.end, client.arrivalTime, client.stayTime);
            i++;
        }
    }
}


void CreateQ(QueueType *Queue)
{
	Queue->Front = 0;
	Queue->Rear = 0;
}


boolean EmptyQ(QueueType Queue)
{
	return (Queue.Front == Queue.Rear);
}


boolean FullQ(QueueType Queue)
{
	return ((Queue.Front) == ((Queue.Rear +1) % QueueLimit));
}


void RemoveQ(QueueType *Queue, QueueElementType *Item)
{
	if(!EmptyQ(*Queue))
	{
		*Item = Queue ->Element[Queue -> Front];
		Queue ->Front  = (Queue ->Front + 1) % QueueLimit;
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
    }
	else
		printf("Full Queue\n");
}
