// filename TestBSTRec.c

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "BstRecADT.h"

void menu(int *choice);

int main()
{

   int choice;
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
                RecBSTInsert(&ARoot, AnItem);
                printf("\nContinue Y/N: ");
                do
                {
      	             scanf("%c", &ch);
                } while (toupper(ch)!= 'N' && toupper(ch)!= 'Y');
            } while (toupper(ch)!='N');
            break;
         case 2:	if (BSTEmpty(ARoot))
                        printf("\nEmpty tree\n");
                    else
                        RecBSTInorder(ARoot);
         			break;
         case 3:    if (BSTEmpty(ARoot))
                        printf("Empty tree\n");
                    else {
                        printf("Enter a number for searching in the Tree: ");
                        scanf("%d", &AnItem);
                        RecBSTSearch(ARoot, AnItem, &Found, &LocPtr);
         			    if (Found==FALSE)
         			        printf("Item %d not in tree \n",AnItem);
         			    else
         			        printf("Item %d is in tree \n",AnItem);
                    }
         			break;
        case 4:    if (BSTEmpty(ARoot))
                        printf("\nEmpty tree\n");
                    else {
                        printf("Enter a number for deleting in the Tree: ");
                        scanf("%d", &AnItem);
                        RecBSTDelete(&ARoot, AnItem);
                    }
         			break;
        case 5:	if (BSTEmpty(ARoot))
                        printf("\nEmpty tree\n");
                    else
                        RecBSTPreorder(ARoot);
         			break;
		case 6:	if (BSTEmpty(ARoot))
                        printf("\nEmpty tree\n");
                    else
                        RecBSTPostorder(ARoot);
         			break;
		}
   } while (choice!=7);

	return 0;
}

void menu(int *choice)
{
    printf("\n                  MENOY                  \n");
    printf("-------------------------------------------------\n");
    printf("1. Insert an element to Binary Tree\n");
    printf("2. Inoder traverse of Binary TreeA\n");
    printf("3. Search for a element in Binary Tree\n");
    printf("4. Delete an element of Binary Tree\n");
    printf("5. Preoder traverse of Binary TreeA\n");
    printf("6. Postoder traverse of Binary TreeA\n");
    printf("7. Telos\n");
    printf("\nEpilogh: ");
    do
    {
    	scanf("%d", choice);
    } while (*choice<1 && *choice>6);
}




