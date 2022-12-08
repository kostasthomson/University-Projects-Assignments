// Filename TestList.c

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "ListADT.h"

void menu(int *choice);

int main()
{
    int Apos;
    ListElementType AnItem;
    ListType AList;

   int choice;
   char ch;

   do
   {
   	menu(&choice);
      switch(choice)
      {
      	  case 1: CreateList(&AList);          //DHMIOYRGIA LISTAS
      	             break;
          case 2: do
                {
   	                printf("DWSE ARI8MO GIA EISAGWGH STH LISTA: ");
                    scanf("%d", &AnItem);
                    do {
                        printf("DWSE TH 8ESH META THN OPOIA 8A GINEI H EISAGWGH STOIXEIOY: ");
                        scanf("%d", &Apos);
                    } while (Apos<-1 || Apos>AList.Size-1);
                    Insert(&AList, AnItem, Apos);    //EISAGWGH STOIXEIOY META TH 8ESH POS STH LISTA
                    printf("\nContinue Y/N: ");
                    do
                    {
      	                 scanf("%c", &ch);
                    } while (toupper(ch)!= 'N' && toupper(ch)!= 'Y');
                } while (toupper(ch)!='N');
                break;
          case 3:	TraverseList(AList);      //DIASXISH LISTAS
         			break;
          case 4:  if (EmptyList(AList))
      	                 printf("Empty List\n");
      	            else
                    {
                        do {
                            printf("DWSE TH 8ESH TOY STOIXEIOY GIA DIAGRAFH: ");
                            scanf("%d", &Apos);
                        } while (Apos<0 || Apos>AList.Size-1);
                        Delete(&AList,Apos);  //DIAGRAFH STOIXEIOY STH 8ESH POS STH LISTA
                    }
         			    break;

          case 5:   if (EmptyList(AList))
      	                 printf("Empty List\n");
      	            else printf("Not an Empty List\n");
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
    printf("1. Create List\n");
    printf("2. Insert an element to List\n");
    printf("3. Traverse List\n");
    printf("4. Delete an element from the List\n");
    printf("5. Check if List is empty\n");
    printf("6. Telos\n");
    printf("\nChoice 1-6 : ");
    do
    {
    	scanf("%d", choice);
    } while (*choice<1 && *choice>6);
}


