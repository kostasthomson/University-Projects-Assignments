// filename TestBST.c

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "BstADT.h"

void menu(int *choice);

int main()
{

   int choice ;
   char ch;
   BinTreePointer ARoot, LocPtr;
   BinTreeElementType AnItem;
   boolean Found;

   CreateBST(&ARoot);
   do
   {
   	menu(&choice);
      switch(choice)
      {
      	case 1:	do
            {
   	            printf("Enter a number for insertion in the Tree: ");
                scanf("%d", &AnItem);
                BSTInsert(&ARoot, AnItem);
                printf("\nContinue Y/N: ");
                do
                {
      	             scanf("%c", &ch);
                } while (toupper(ch)!= 'N' && toupper(ch)!= 'Y');
            } while (toupper(ch)!='N');
            break;
         case 2:	if (EmptyBST(ARoot))
                        printf("Empty tree\n");
                    else
                        InorderTraversal(ARoot);
         			break;
         case 3:    if (EmptyBST(ARoot))
                        printf("Empty tree\n");
                    else
                    {
                        printf("Enter a number for searching in the Tree: ");
                        scanf("%d", &AnItem);
                        BSTSearch(ARoot, AnItem, &Found, &LocPtr);
         			    if (Found==FALSE)
         			        printf("Item %d not in tree \n",AnItem);
         			    else
         			        printf("Item %d is in tree \n",AnItem);
                    }
         			break;
        case 4:    if (EmptyBST(ARoot))
                        printf("Empty tree\n");
                    else
                    {
                        printf("Enter a number for deleting in the Tree: ");
                        scanf("%d", &AnItem);
                        BSTDelete(&ARoot, AnItem);
                    }
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
    printf("1. Insert an element to Binary Tree\n");
    printf("2. Inoder traverse of Binary TreeA\n");
    printf("3. Search for a element in Binary Tree\n");
    printf("4. Delete an element of Binary Tree\n");
    printf("5. Telos\n");
    printf("\nEpilogh: ");
    do
    {
    	scanf("%d", choice);
    } while (*choice<1 && *choice>4);
}
