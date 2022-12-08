#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "SetADT.h"

void menu(int *choice);
void displayset(typos_synolou set);

int main()
{
    stoixeio_synolou AnItem;
    int choice, s;
    typos_synolou set, set1, set2, tomi, enosi,diafora;
    char ch;

    do
   {
   	    menu(&choice);
        switch(choice)
        {
      	     case 1: Dimiourgia(set1);
      	             printf("\nset1\n");
                     displayset(set1);
      	             Dimiourgia(set2);
      	             printf("\nset2\n");
      	             displayset(set2);
      	             break;
             case 2: Katholiko(set);
                     printf("\nkatholio\n");
      	             displayset(set);
      	             break;
     	     case 3: printf("\nDWSE set 1 or 2 ");
      	             scanf("%d",&s);
                     do
                     {
   	                    printf("DWSE ARI8MO GIA EISAGWGH STO set: ");
                        scanf("%d", &AnItem);
                        if (s==1)
                            Eisagogi(AnItem,set1);
                        else
                            Eisagogi(AnItem,set2);
                        printf("\nContinue Y/N: ");
                        do
                        {
      	                     scanf("%c", &ch);
                        } while (toupper(ch)!= 'N' && toupper(ch)!= 'Y');
                    } while (toupper(ch)!='N');
                    if (s==1)
                        displayset(set1);
                    else displayset(set2);
                    break;
      	     case 4: printf("\nset1: ");
                     displayset(set1);
                     printf("\nset2: ");
                     displayset(set2);
                     printf("\nDWSE STOIXEIO gia diagrafi ");
      	             scanf("%d",&AnItem);
                     printf("\nDWSE synolo set 1 or 2 ");
      	             scanf("%d",&s);
      	             if (s==1) {
                        Diagrafi(AnItem, set1);
                        printf("\nset1 meta th diagrafi tou stoixeiou %d : ",AnItem );
                        displayset(set1);
                     }
                     else {
                        Diagrafi(AnItem, set2);
                        printf("\nset2 meta th diagrafi tou stoixeiou %d : ",AnItem );
                        displayset(set2);
                     }
      	             break;
      	     case 5: printf("\nDWSE STOIXEIO ");
      	             scanf("%d",&AnItem);
      	             printf("\nDWSE set 1 or 2 ");
      	             scanf("%d",&s);
      	             if (s==1)
                        if (Melos(AnItem, set1))
                            printf("%d einai melos tou set1\n",AnItem);
                        else printf("%d den einai melos tou set1\n",AnItem);
                     else
                        if (Melos(AnItem, set2))
                            printf("%d einai melos tou set2\n",AnItem);
                        else printf("%d den einai melos tou set2\n",AnItem);
      	             break;
      	     case 6: printf("\nDWSE set 1 or 2 ");
      	             scanf("%d",&s);
      	             if (s==1)
                        if (KenoSynolo(set1))
      	                     printf("Empty set1\n");
      	                else printf("not Empty set1\n");
      	             else
                        if (KenoSynolo(set2))
                            printf("Empty set2\n");
      	                else printf("not Empty set2\n");
      	             break;
      	     case 7: if (IsaSynola(set1,set2))
      	                 printf("isa\n");
      	             else printf("Not isa sets\n");
      	             break;
             case 8: printf("\nDWSE set 1 or 2 ");
      	             scanf("%d",&s);
      	             if (s==1)
                        if (Yposynolo(set1,set2))
      	                 printf("set1 yposynolo tou set2\n");
      	                 else printf("Not yposynolo\n");
      	             else if (Yposynolo(set2,set1))
      	                 printf("set2 yposynolo tou set1\n");
      	                 else printf("Not yposynolo\n");
      	             break;
             case 9: EnosiSynolou(set1,set2,enosi);
                     printf("ENWSH\n");
                     displayset(enosi);
      	             break;
             case 10: TomiSynolou(set1,set2,tomi);
                      displayset(tomi);
      	             break;
             case 11: DiaforaSynolou(set1,set2,diafora);
                      printf("DIAFORA\n");
                      displayset(diafora);
      	              break;
        }
        } while (choice!=12);
        return 0;
        system("PAUSE");
}

void menu(int *choice)
{
  printf("\nXRHSIMOPOIHSE TIS PARAKATW ENTOLES GIA NA ELEGJEIS TO unit SetADT\n");
  printf("1 ---- DHMIOYRGIA SYNOLOU\n");
  printf("2 ---- KA8OLIKO\n");
  printf("3 ---- EISAGWGH\n");
  printf("4 ---  DIAGRAFH\n");
  printf("5 ---  MELOS\n");
  printf("6 ---- KENO SYNOLO\n");
  printf("7 ---- ISA SYNOLA\n");
  printf("8 ---- YPOSYNOLO\n");
  printf("9 ---- ENOSH 2 SYNOLWN\n");
  printf("10 ---- TOMH 2 SYNOLWN\n");
  printf("11 ---- DIAFORA SYNOLOU\n");
  printf("12 ---- EXIT\n");
  printf("\nChoice 1-12: ");
  do
    {
    	scanf("%d", choice);
    } while (*choice<1 && *choice>12);
}


void displayset(typos_synolou set)
{
	stoixeio_synolou i;

	for (i=0;i < megisto_plithos;i++)
	{
		if(Melos(i,set))
			printf(" %d",i);
	}
	printf("\n");
}



