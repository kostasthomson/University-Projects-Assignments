// Filename TestL_List.c

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "L_ListADT.h"

void menu(int *choice);
void printAll(ListPointer List, ListPointer FreePtr, NodeType Node[]);

int main()
{
    ListPointer AList;
    NodeType Node[NumberOfNodes];
    ListPointer FreePtr,PredPtr;

    ListElementType AnItem;

   int choice;
   char ch;

   InitializeStoragePool(Node, &FreePtr);
   printAll(AList, FreePtr, Node);
   do
   {
   	menu(&choice);
      switch(choice)
      {
      	  case 1: CreateList(&AList);          //DHMIOYRGIA LISTAS
      	             break;
          case 2:	do
                    {
   	                    printf("FreePtr=%d\n",FreePtr);
                        printf("DWSE ARI8MO GIA EISAGWGH STH LISTA: ");
                        scanf("%d", &AnItem);
                        /*H EISAGWGH STOIXEIOY GINETAI PANTA STHN ARXH THS LISTAS (STO PX SYMPERIFERETAI WS STOIBA)
                        * SE PERIPTWSH POY 8ELW PX  TAXINOMHMENH LISTA 8A PREPEI NA YLOPOIHSW EPIPLEON SYNARTHSH SEARCH
                        * POY 8A EPISTREFEI TH TIMH THS PredPtr
                        */
                        PredPtr=NilValue;
                        Insert(&AList, Node,&FreePtr, PredPtr, AnItem); //EISAGWGH STOIXEIOY META TH 8ESH POS STH LISTA
                        printf("AList=%d\n",AList);
                        printf("\nContinue Y/N: ");
                        do
                        {
      	                     scanf("%c", &ch);
                        } while (toupper(ch)!= 'N' && toupper(ch)!= 'Y');
                    } while (toupper(ch)!='N');
                    printAll(AList, FreePtr, Node);
                    break;
          case 3:	printf("FreePtr=%d\n",FreePtr);
                    TraverseLinked(AList, Node);      //DIASXISH LISTAS
         			break;
          case 4:   if (EmptyList(AList))
      	                 printf("Empty List\n");
      	            else
      	            {
                        printAll(AList, FreePtr, Node);
                        printf("DWSE TH 8ESH TOY PROHGOYMENO STOIXEIOY GIA DIAGRAFH: ");
                        scanf("%d", &PredPtr);
                        Delete(&AList, Node, &FreePtr, PredPtr);  //DIAGRAFH STOIXEIOY META TH 8ESH POS STH LISTA
                        printAll(AList, FreePtr, Node);
                    }
         			break;
          case 5:   if (EmptyList(AList))
      	                 printf("Empty List\n");
      	            else printf("Not an Empty List\n");
      	            break;
      	case 6:   if (FullList(FreePtr))
      	                 printf("Full List\n");
      	            else printf("Not a Full List\n");
      	            break;
      	 case 7:	printAll(AList, FreePtr, Node);     //EMFANISH STORAGE POOL
         			break;
	  }
   } while (choice!=8);
    system("pause");
	return 0;
}

void menu(int *choice)
{
    printf("                  MENOY                  \n");
    printf("-------------------------------------------------\n");
    printf("1. Create List\n");
    printf("2. Insert an element to List\n");
    printf("3. Traverse List\n");
    printf("4. Delete an element from the List\n");
    printf("5. Check if List is empty\n");
    printf("6. Check if List is full\n");
    printf("7. Print storage pool\n");
    printf("8. Telos\n");
    printf("\nChoice 1-8 : ");
    do
    {
    	scanf("%d", choice);
    } while (*choice<1 && *choice>7);
}

void printAll(ListPointer List, ListPointer FreePtr, NodeType Node[])
{
    int i;
    printf("1o STOIXEIO LISTAS=%d, 1H FREE POSITION=%d\n", List, FreePtr);
    printf("H STORAGE POOL EXEI TA EJHS STOIXEIA\n");
    for (i=0;i<NumberOfNodes;i++)
        printf("(%d: %d->%d) ",i,Node[i].Data, Node[i].Next);
    printf("\n");
}


