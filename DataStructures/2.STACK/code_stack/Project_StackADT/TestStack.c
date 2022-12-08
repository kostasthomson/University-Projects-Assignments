#include <stdio.h>
#include <stdlib.h>
#include "StackADT.h"

void TraverseStack(StackType Stack);

void menu(int *choice);

int main()
{
    StackElementType AnItem;
    StackType AStack;
    int choice;

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
      	    case 4: if (!EmptyStack(AStack)) {
                        Pop(&AStack, &AnItem);
                        printf("\nKORYFAIO STOIXEIO %d\n",AnItem);
                    }
                    else printf("Empty Stack\n");
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
  printf("\nXRHSIMOPOIHSE TIS PARAKATW ENTOLES GIA NA ELEGJEIS TO unit StackADT\n");
  printf("1 ---- DHMIOYRGIA STOIBAS\n");
  printf("2 ---- ADEIASMA THS STOIBAS\n");
  printf("3 ---- ELEGXOS KENHS STOIBAS\n");
  printf("4 ---  POP STOIXEIOY APO TH KORYFH THS STOIBA\n");
  printf("5 ---  PUSH STH KORYFH THS STOIBAS\n");
  printf("6 ---- EMFANISH STOIXEIWN STOIBAS (BOH8HTHKH)\n");
  printf("7 ---- EXIT\n");
  do
    {
    	scanf("%d", choice);
    } while (*choice<1 && *choice>7);
}

// ΑΥΤΗ Η ΕΚΔΟΣΗ ΕΜΦΑΝΙΖΕΙ ΤΑ ΣTOIXEIA ΤΗΣ ΣΤΟΙΒΑΣ ΑΠΟ ΤΗ ΘΕΣΗ TOP-0

void TraverseStack(StackType Stack)
{
    int i;
    printf("\nplithos sto stack %d\n",Stack.Top+1);
    for (i=Stack.Top;i>=0;i--) {
        printf("%d ",Stack.Element[i]);
    }
    printf("\n");
}
 /*
 ΑΥΤΗ Η ΕΚΔΟΣΗ ΕΙΝΑΙ ΣΤΙΣ ΣΗΜΕΙΩΣΕΙΣ ΚΑΙ ΕΜΦΑΝΙΖΕΙ ΤΑ STOIXEIA ΤΗΣ ΣΤΟΙΒΑΣ ΑΠΟ ΤΗ ΘΕΣΗ 0-TOP
 void TraverseStack(StackType Stack)
{
    int i;
    printf("\nplithos sto stack %d\n",Stack.Top+1);
    for (i=0;i<=Stack.Top;i++) {
        printf("%d ",Stack.Element[i]);
    }
    printf("\n");
}
*/
