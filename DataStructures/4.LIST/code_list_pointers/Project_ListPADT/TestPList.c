
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "ListPADT.h"

void menu(int *choice);
void list_insertion(ListPointer *List, int choice1);

int main()
{
   ListPointer AList, PredPtr;
   int choice, choice1;
   ListElementType keyvalue;
   boolean Found;

   CreateList(&AList);
   printf("ORDER OR ANORDER LIST (1 OR 2) ");
   scanf("%d", &choice1);
   do
   {
   	menu(&choice);
      switch(choice)
      {
      	case 1:	printf("main: &AList= %p, AList= %p\n",&AList, AList);
                list_insertion(&AList, choice1);
                printf("&AList %p, AList %p\n",&AList, AList);
         			break;
         case 2:	LinkedTraverse(AList);
         			break;
         case 3:  printf("Enter Data for searching: "); scanf("%d", &keyvalue);
         			LinearSearch(AList, keyvalue, &PredPtr, &Found);
                    if ( Found )
                  	     printf("Found IN NODE \n");
                    else
                  	     printf("Item NOT IN LIST\n");
         			break;
         case 4:  printf("Enter Data for deleting: "); scanf("%d", &keyvalue);
         			LinearSearch(AList, keyvalue, &PredPtr, &Found);
         			if (Found)
         			    LinkedDelete(&AList, PredPtr);
         			else
         			    printf("Item NOT IN LIST\n");
         			break;
        case 5:  printf("Enter Data for searching: "); scanf("%d", &keyvalue);
         			OrderedLinearSearch(AList, keyvalue, &PredPtr, &Found);
                    if ( Found )
                  	     printf("Found IN NODE \n");
                    else
                  	     printf("Item NOT IN LIST\n");
         			break;
		}
   } while (choice!=6);
    system("pause");
	return 0;
}

void menu(int *choice)
{
    printf("                  MENOY                  \n");
    printf("-------------------------------------------------\n");
    printf("1. Eisagwgh stoixeiwn sth lista\n");
    printf("2. Diasxish stoixeiwn ths listas\n");
    printf("3. Anazhthsh stoixeiou sth lista\n");
    printf("4. Diagrafh stoixeiou apo th lista\n");
    printf("5. Anazhthsh stoixeiou se ordered lista\n");
    printf("6. Telos\n");
    printf("\nEpilogh: ");
    do
    {
    	scanf("%d", choice);
    } while (*choice<1 && *choice>6);
}

void list_insertion(ListPointer *List,int choice1)
{
 	ListElementType Item;
    char ch;
    ListPointer PredPtr;
    boolean Found;

	do
    {
   	    printf("Enter a number for insertion in the list: "); scanf("%d", &Item);
   	    if (choice1==1)
   	        OrderedLinearSearch(*List, Item, &PredPtr, &Found);
   	    else
            PredPtr= NULL;
        LinkedInsert(List, Item, PredPtr);
        printf("\nContinue Y/N: ");
        do
        {
      	     scanf("%c", &ch);
        } while (toupper(ch)!= 'N' && toupper(ch)!= 'Y');
    } while (toupper(ch)!='N');
}
