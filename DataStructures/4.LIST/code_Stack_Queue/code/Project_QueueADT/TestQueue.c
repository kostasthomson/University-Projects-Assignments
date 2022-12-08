//filename TestQueue.c

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "QueueADT.h"

void menu(int *choice);
void TraverseQ(QueueType Queue);

int main()
{
   QueueType AQueue;
   int choice;
   QueueElementType AnItem;
do
   {
   	menu(&choice);
      switch(choice)
      {
      	    case 1: CreateQ(&AQueue);
      	             break;
            case 2: if (EmptyQ(AQueue))
                        printf("Empty Queue...\n");
                    else
                        while (!EmptyQ(AQueue))
                        {
                            RemoveQ(&AQueue, &AnItem);
      	                     printf("KORYFAIO STOIXEIO %d\n",AnItem);
                        }
      	             break;
      	    case 3: if (EmptyQ(AQueue))
      	                 printf("Empty Queue\n");
      	            else printf("Not an Empty Queue\n");
      	            break;
      	    case 4: if (EmptyQ(AQueue))
      	                 printf("Empty Queue\n");
      	            else {
                            RemoveQ(&AQueue, &AnItem);
                            printf("KORYFAIO STOIXEIO %d\n",AnItem);
                        }
      	            break;
      	    case 5: printf("DWSE STOIXEIO GIA EIGWGH: ");
      	             scanf("%d",&AnItem);
      	             AddQ(&AQueue,AnItem);
      	             break;
      	    case 6: if (EmptyQ(AQueue))
                        printf("Empty Queue...\n");
                    else TraverseQ(AQueue);
      	             break;
        }
   } while (choice!=7);

	return 0;
}

void menu(int *choice)
{
    printf("                  MENOY                  \n");
    printf("-------------------------------------------------\n");
    printf("1 ---- DHMIOYRGIA OURAS\n");
    printf("2 ---- ADEIASMA THS OYRAS\n");
    printf("3 ---- ELEGXOS KENHS OYRAS\n");
    printf("4 ---  DIAGRAFH STOIXEIOY APO TH KORYFH THS OYRAS\n");
    printf("5 ---  PROS8HKH STOIXEIOY STO TELOS THS OYRAS\n");
    printf("6 ---- EMFANISH STOIXEIWN OURAS (BOH8HTHKH)\n");
    printf("7 ---- EXIT\n");
    printf("\nChoice: ");
    do
    {
    	scanf("%d", choice);
    } while (*choice<1 && *choice>7);
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
      	     printf("%d ", CurrPtr->Data);
             CurrPtr = CurrPtr->Next;
        }
   }
    printf("\n");
}
