// filename TestStack.c

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "StackADT.h"

void TraverseStack(StackPointer Stack);
void menu(int *choice);

int main()
{
   StackPointer AStack;
   int choice;
   StackElementType AnItem;

   do
   {
   	menu(&choice);
      switch(choice)
      {
      	case 1: CreateStack(&AStack);
      	             break;
            case 2: if (EmptyStack(AStack))
                        printf("Empty Stack\n");
                    else
                        while (!EmptyStack(AStack))
                        {
                            Pop(&AStack, &AnItem);
      	                     printf("KORYFAIO STOIXEIO %d\n",AnItem);
                        }
      	             break;
      	    case 3: if (EmptyStack(AStack))
      	                 printf("Empty Stack\n");
      	            else printf("Not an Empty Stack\n");
      	            break;
      	    case 4: if (EmptyStack(AStack))
      	                 printf("Empty Stack\n");
      	            else {
                        Pop(&AStack, &AnItem);
                        printf("\nKORYFAIO STOIXEIO %d\n",AnItem);
                    }
      	             break;
      	    case 5: printf("DWSE STOIXEIO GIA W8HSH: ");
      	             scanf("%d",&AnItem);
      	             Push(&AStack,AnItem);
      	             break;
      	    case 6: if (EmptyStack(AStack))
      	                 printf("Empty Stack\n");
      	            else TraverseStack(AStack);
      	             break;
        }
   } while (choice!=7);

	return 0;
}

void menu(int *choice)
{
    printf("                  MENOY                  \n");
    printf("-------------------------------------------------\n");
    printf("1 ---- DHMIOYRGIA STOIBAS\n");
    printf("2 ---- ADEIASMA THS STOIBAS\n");
    printf("3 ---- ELEGXOS KENHS STOIBAS\n");
    printf("4 ---  POP STOIXEIOY APO TH KORYFH THS STOIBA\n");
    printf("5 ---  PUSH STH KORYFH THS STOIBAS\n");
    printf("6 ---- EMFANISH STOIXEIWN STOIBAS (BOH8HTHKH)\n");
    printf("7 ---- EXIT\n");
    printf("\nChoice: ");
    do
    {
    	scanf("%d", choice);
    } while (*choice<1 && *choice>7);
}

void TraverseStack(StackPointer Stack)
{
	StackPointer CurrPtr;

   if (EmptyStack(Stack))
   {
   	    printf("EMPTY Stack\n");
    }
   else
   {
   	    CurrPtr = Stack;
         while ( CurrPtr!=NULL )
        {
      	     printf("%d ", CurrPtr->Data);
             CurrPtr = CurrPtr->Next;
        }
   }
    printf("\n");
}
