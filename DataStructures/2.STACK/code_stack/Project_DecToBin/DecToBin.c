// Filename  DecToBin;

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "StackADT.h"

int main()
{
  int Number,Remainder;
  StackType StackOfRemainders;
  char Response;

  do
  {
    printf("\nPLHKTROLOGHSTE ENAN 8ETIKO AKERAIO ARI8MO GIA METROPH: ");
    scanf("%d",&Number);
    CreateStack(&StackOfRemainders);
    while (Number!=0)
    {
        Remainder =Number%2;
        Push(&StackOfRemainders,Remainder);
        Number=Number/2;
    }
    printf("DYAGIKH ANAPARASTASH: ");
    while (!EmptyStack(StackOfRemainders))
    {
        Pop(&StackOfRemainders,&Remainder);
        printf("%d",Remainder);
    }
    printf("\nSYNEXEIA (Y,N)? ");
    do {
        scanf("%c", &Response);
    } while (toupper(Response)!= 'N' && toupper(Response)!= 'Y');
  } while (toupper(Response)!='N');
    return 0;
}
