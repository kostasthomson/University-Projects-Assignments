//filename DrillAndPractice.c;
//*PROBLHMA ASKHSHS-EJASKHSHS GIA STOIXEIWDH ARI8MHTIKH*)

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "QProbADT.h"

#define NumberLimit 99

boolean Ask(QueueElementType Problem, int RoundNum);
void Randomize();
int RandomInt(int First,int Last);
void TraverseQ(QueueType Queue);

int main()
{
  QueueType WrongQ;
  boolean Correct;
  QueueElementType Problem;
  int NumProblems,count,Wrong;

  Randomize();
  CreateQ(&WrongQ);
  TraverseQ(WrongQ);
  printf("POSA PROBLHMATA 8ELEIS; ");
  scanf("%d",&NumProblems);
  for (count=1; count<=NumProblems; count++)
  {
      Problem.Addend1=RandomInt(0,NumberLimit);
      Problem.Addend2=RandomInt(0,NumberLimit);
      Correct=Ask(Problem,1);
      if (!Correct)
        AddQ(&WrongQ,Problem);
    //TraverseQ(WrongQ);
   }

  printf("AN APANTHSATE LA8OS SE KAPOIA PROBLHMATA, SAS DINETAI\n");
  printf("MIA DEYTERH EYKAIRIA NA TA APANTHSETE.\n");
  if (FullQ(WrongQ))
    printf("KAPOIA PROBLHMATA XA8HKAN, GIATI GEMISE H OYRA.\n");
  Wrong=0;
  while (!EmptyQ(WrongQ))
   {
      RemoveQ(&WrongQ,&Problem);
      Correct=Ask(Problem,2);
      if (!Correct)
        Wrong++;
   }
  printf("APANTHSATE %d PROBLHMA(PROBLHMATA) LA8OS.\n", Wrong);
  system("PAUSE");
  return 0;
}

void Randomize()
{
    srand((int) time(NULL));
}

int RandomInt(int low,int high)
/* ΔΕΧΕΤΑΙ: ΤΟΥΣ ΑΚΕΡΑΙΟΥς low ΚΑΙ high
   ΛΕΙΤΟΥΡΓΙΑ: ΥΠΟΛΟΓΙΖΕΙ ΕΝΑΝ ΤΥΧΑΙΟ ΑΚΕΡΑΙΟ ΜΕΤΑΞΥ low KAI high
   ΕΠΙΣΤΡΕΦΕΙ: ΕΝΑΝ ΤΥΧΑΙΟ ΑΡΙΘΜΟ ΜΕΤΑΞΥ low KAI high

*/
{
    int k;
    double d;

    d = (double) rand() / ((double) RAND_MAX + 1);
    k = (int) (d * (high - low + 1));
    return (low + k);
}

boolean Ask(QueueElementType Problem, int RoundNum)
/* DEXETAI:    ENA PROBLHMA KAI THN METABLHTH RoundNum, POY DHLWNEI TO
               POSES FORES EXEI ZHTH8EI AYTO TO PROBLHMA.
   LEITOYRGIA: EMFANIZEI ENA PROBLHMA PROS8ESHS, PAIRNEI THN APANTHSH TOY
               XRHSTH KAI ELEGXEI AN EINAI SWSTH. AN RoundNum=2, EMFANIZETAI
               H SWSTH APANTHSH, AN O XRHSTHS APANTHSEI LA8OS.
   EPISTREFEI: H Correct EINAI true, AN O XRHSTHS APANTHSEI SWSTA, DIAFORETIKA
               EINAI false.
   EJODOS:     TO PROBLHMA, ENA MHNYMA KAI THN SWSTH APANTHSH.
*/

{
    int Answer,Sum;
    boolean Correct;

    printf("\n%d + %d =", Problem.Addend1,Problem.Addend2);
    scanf("%d",&Answer);
    Sum=Problem.Addend1+Problem.Addend2;

  Correct=(Answer==Sum);
//    printf("correct %d\n",Correct);
  if (Correct)
    printf("SWSTA!");
  else
    if (RoundNum==2)
        printf("LA8OS! H SWSTH APANTHSH EINAI %d\n",Sum);
    else
        printf("LA8OS!");
   return Correct;
}

void TraverseQ(QueueType Queue) {
	int current;
	current = Queue.Front;
	while (current != Queue.Rear) {
        printf("\n%d, %d\n", Queue.Element[current].Addend1,Queue.Element[current].Addend2 );
		current = (current + 1) % QueueLimit;
	}
	printf("\n");
}
