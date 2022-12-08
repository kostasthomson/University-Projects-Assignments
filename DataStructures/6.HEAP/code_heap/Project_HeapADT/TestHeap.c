// filename TestHeap.c

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "HeapADT.h"

void menu(int *choice);
void PrintHeap(HeapType Heap);

int main()
{

   int choice ;
   char ch;
   HeapType AHeap;
   HeapNode AnItem;

   CreateMaxHeap(&AHeap);
   do
   {
   	menu(&choice);
      switch(choice)
      {
      	case 1:	do
            {
   	            printf("Enter a number : ");
                scanf("%d", &AnItem.key);
                InsertMaxHeap(&AHeap, AnItem);
                printf("\nContinue Y/N: ");
                do
                {
      	             scanf("%c", &ch);
                } while (toupper(ch)!= 'N' && toupper(ch)!= 'Y');
            } while (toupper(ch)!='N');
            break;
         case 2:	if (EmptyHeap(AHeap))
                        printf("Empty Heap\n");
                    else
                        printf("Not an Empty Heap\n");
         			break;
         case 3:    if (EmptyHeap(AHeap))
                        printf("Empty Heap\n");
                    else
                    {
                        DeleteMaxHeap(&AHeap, &AnItem);
         			    printf("Deleted Item is %d \n",AnItem.key);
                    }
         			break;
        case 4:    if (EmptyHeap(AHeap))
                        printf("Empty Heap\n");
                    else PrintHeap(AHeap);
         			break;
		}
   } while (choice!=5);
    system("pause");
	return 0;
}

void menu(int *choice)
{
    printf("                  MENOY                  \n");
    printf("-------------------------------------------------\n");
    printf("1. Insert an element to the Heap\n");
    printf("2. Check if Heap is empty\n");
    printf("3. Delete an element from  Heap\n");
    printf("4. Print Heap\n");
    printf("5. Telos\n");
    printf("\nChoice: ");
    do
    {
    	scanf("%d", choice);
    } while (*choice<1 && *choice>5);
}

void PrintHeap(HeapType Heap)
{
    int i,l,r,n;
    printf("Size=%d \n",Heap.Size);
     printf("N   L   R\n");
     n=Heap.Size/2;
     for (i=1; i<=n;i++)
     {
         l=2*i;
         r=2*i+1;
         printf("%d, ",Heap.Element[i].key);
         if (l<=Heap.Size)
            printf("%d, ",Heap.Element[l].key);
         else printf(",   ");
         if (r<=Heap.Size)
            printf("%d \n",Heap.Element[r].key);
         else printf("\n");
     }
     printf("Heap array\n");
     for (i=1; i<=Heap.Size;i++)
        printf("%d ",Heap.Element[i].key);
    printf(" \n");
}
