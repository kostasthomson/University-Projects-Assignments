//filename : Chaining.c
#include <stdio.h>
#include <ctype.h>
#include "HashList.h"

void Print_HashList(HashListType HList);
void menu(int *choice);
void PrintPinakes(HashListType HList);

int main(){
   int choice;
   char ch;
   HashListType HList;
   ListElm AnItem;
   KeyType AKey;
   int Loc, Pred;

   CreateHashList(&HList);
   do
   {
   	menu(&choice);
      switch(choice)
      {
      	case 1:	do
            {
   	            printf("Enter the key for insertion in the Hash: ");
                scanf("%d", &AnItem.RecKey);
                printf("Enter the data for insertion in the Hash: ");
                scanf("%d", &AnItem.Data);
                AnItem.Link=EndOfList;
                AddRec(&HList, AnItem);
                printf("\nContinue Y/N: ");
                do
                {
      	             scanf("%c", &ch);
                } while (toupper(ch)!= 'N' && toupper(ch)!= 'Y');
            } while (toupper(ch)!='N');
            break;
         case 2: printf("Enter a number for deleting in the Hash: ");
                 scanf("%d", &AKey);
                 DeleteRec(&HList, AKey);
         		 break;
         case 3:   printf("Enter a number for searching in the Hash: ");
                    scanf("%d", &AKey);
                    SearchHashList( HList,AKey,&Loc,&Pred);
         			if ( Loc != -1)
                        printf("EGGRAFH [%d, %d, %d]\n",HList.List[Loc].RecKey,HList.List[Loc].Data,HList.List[Loc].Link);
                    else
                        printf("DEN YPARXEI EGGRAFH ME KLEIDI %d\n", AKey);
         			break;
        case 4: Print_HashList(HList);
         			break;
        case 5: PrintPinakes(HList);
         			break;
		}
   } while (choice!=6);

	return 0;
}


void Print_HashList(HashListType HList)
{
   int i, SubIndex;

     printf("HASHLIST STRUCTURE with SYNONYM CHAINING\n");
     printf("========================================\n");

          printf("PINAKAS DEIKTWN STIS YPO-LISTES SYNWNYMWN EGGRAFWN:\n");
            for (i=0; i<HMax;i++)
              printf("%d| %d\n",i,HList.HashTable[i]);

          printf("OI YPO-LISTES TWN SYNWNYMWN EGGRAFWN:\n");
          for (i=0; i<HMax;i++)
          {
              SubIndex = HList.HashTable[i];
              while ( SubIndex != EndOfList )
              {
                   printf("[%d, %d, %d]",HList.List[SubIndex].RecKey,HList.List[SubIndex].Data,HList.List[SubIndex].Link);
                   printf(" -> ");
                   SubIndex = HList.List[SubIndex].Link;
               } //* while *)
              printf("TELOS % dHS YPO-LISTAS\n", i);
          }

          printf("H STOIBA TWN ELEY8ERWN 8ESEWN THS LISTAS:\n");
          SubIndex = HList.StackPtr;
          while ( SubIndex != EndOfList )
          {
                printf("%d <= ",SubIndex);
                SubIndex = HList.List[SubIndex].Link;
          }
          printf("TELOS\n");

          printf("MEGE8OS THS LISTAS = %d\n", HList.Size);
          printf("========================================\n");
}

void menu(int *choice)
{
    printf("                  MENOY                  \n");
    printf("-------------------------------------------------\n");
    printf("1. EISAGWGH EGGRAFHS\n");
    printf("2. DIAGRAFH EGGRAFHS\n");
    printf("3. ANAZHTHSH EGGRAFHS\n");
    printf("4. EMFANISH DOMHS\n");
    printf("5. EMFANISH PINAKWN (BOH8HTIKH\n");
    printf("6. EXIT\n");
    printf("\nCHOICE: ");
    do
    {
    	scanf("%d", choice);
    } while (*choice<1 && *choice>6);
}

void PrintPinakes(HashListType HList)
{
    int i;
	printf("Hash table\n");
	for (i=0; i<HMax;i++)
              printf("%d| %d\n",i,HList.HashTable[i]);

	printf("Hash List\n");
    for (i=0;i<HList.Size;i++)
	   printf("%d) %d, %d\n",i,HList.List[i].RecKey,HList.List[i].Link);
	printf("\n");
}
