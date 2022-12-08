#include <stdio.h>
#include <ctype.h>
#include <string.h>


#define HMax 9              /*     το μέγεθος του πίνακα HashTable
                                ενδεικτικά ίσο με 5 */
#define VMax 30             /*το μέγεθος της λίστας,
                                ενδεικτικά ίσο με 30 */
#define EndOfList -1        /* σημαία που σηματοδοτεί το τέλος της λίστας
                                και της κάθε υπολίστας συνωνύμων */

typedef struct{
    //char name[20];
    //char surname[20];
    char phone[11];
    int code;
}ListElementType;  /*τύπος δεδομένων για τα στοιχεία της λίστας
                               * ενδεικτικά τύπου int */
typedef char KeyType[32];

typedef struct {
	KeyType RecKey;
	ListElementType Data;
	int Link;
} ListElm;

typedef struct  {
	int HashTable[HMax];   // πίνακας δεικτών προς τις υπολίστες συνωνύμων
    int Size;                // πλήθος εγγραφών της λίστας List
	int SubListPtr;          // Dδείκτης σε μια υπολίστα συνωνύμων
    int StackPtr;           // δείκτης προς την πρώτη ελεύθερη θέση της λίστας List
	ListElm List[VMax];
} HashListType;

typedef enum {
    FALSE, TRUE
} boolean;

void CreateHashList(HashListType *HList);
int HashKey(KeyType Key);
boolean FullHashList(HashListType HList);
void SearchSynonymList(HashListType HList,KeyType KeyArg,int *Loc,int *Pred);
void SearchHashList(HashListType HList,KeyType KeyArg,int *Loc,int *Pred);
void AddRec(HashListType *HList,ListElm InRec);
void DeleteRec(HashListType *HList,KeyType DelKey);
void Print_HashList(HashListType HList);
void PrintPinakes(HashListType HList);
void PrintListOfSynonyms(HashListType HList, KeyType key);
int findAverage(KeyType s);
void BuildHashList(HashListType *HList);
void Search_HashList_By_Subject(HashListType HList, int code);

int main()
{
    char ch;
    HashListType HList;
    ListElm AnItem;
    KeyType AKey;
    int loc,pred;
    int code;
    char surname[20];

    //1
    printf("1. Create HashList\n");
    BuildHashList(&HList);
    PrintPinakes(HList);

    //2
    printf("2. Insert new teacher\n");
    do{
        printf("Enter teacher's name: ");
        scanf("%s",AnItem.RecKey);
        printf("Enter teacher's surname: ");
        scanf("%s",surname);
        strcat(AnItem.RecKey," ");
        strcat(AnItem.RecKey,surname);
        //AKey = HashKey(AnItem.RecKey);
        printf("Enter teacher's phone: ");
        scanf("%s",&AnItem.Data.phone);
        printf("Enter teacher code: ");
        scanf("%d",&AnItem.Data.code);
        AddRec(&HList, AnItem);
        printf("\nContinue Y/N:");
    do{
                    getchar();
                    scanf("%c", &ch);
              } while (toupper(ch)!= 'N' && toupper(ch)!= 'Y');
        } while (toupper(ch)!='N');
    PrintPinakes(HList);
    //Print_HashList(HList);
    //PrintPinakes(HList);

    //3
    printf("3. Delete a teacher\n");

        printf("Enter teacher's name: ");
        scanf("%s",AKey);
        printf("Enter teacher's surname: ");
        scanf("%s",surname);
        strcat(AKey," ");
        strcat(AKey,surname);
        DeleteRec(&HList,AKey);
        PrintPinakes(HList);


    //4
    printf("4. Search for a teacher\n");

     printf("Enter teacher's name: ");
    scanf("%s",AKey);
    printf("Enter teacher's surname: ");
    scanf("%s",surname);
    strcat(AKey," ");
    strcat(AKey,surname);
    SearchHashList(HList, AKey, &loc, &pred);
    if(loc!=pred)
    {
        printf("[%s, %s, %d]", HList.List[loc].RecKey, HList.List[loc].Data.phone, HList.List[loc].Data.code);
    }else
    {
        printf("DEN YPARXEI EGGRAFH ME KLEIDI %s\n", AKey);
    }

    //5
    printf("\n 5. Search by subject\n");
    printf("Enter code:");
    scanf("%d",&code);
    printf("List of teachers with subject code %d:\n",code);
    Search_HashList_By_Subject(HList,code);

    return 0;
}

void PrintPinakes(HashListType HList)
{
    int i;
    printf("Hash table\n");
    for(i=0;i<HMax;i++)
        printf("%d, ",HList.HashTable[i]);

    printf("\nHash List\n");
    for(i=0;i<HList.Size;i++)
       printf("%d) %s, %d\n",i,HList.List[i].RecKey,HList.List[i].Link);
    printf("\n");
}
int HashKey(KeyType Key)
/* Δέχεται:    Την τιμή Key ενός κλειδιού.
   Λειτουργία: Βρίσκει την τιμή κατακερματισμού HValue για το κλειδί Key.
   Επιστρέφει: Την τιμή κατακερματισμού HValue
*/
{
    int avg;

	avg=findAverage(Key);
	return avg%HMax;
}

void BuildHashList(HashListType *HList)
{
    ListElm AnItem;
    FILE *fp;
    char surname[20], termch;
    int nscan;

    CreateHashList(HList);

    fp=fopen("i4f6.txt", "r");

    if(fp!=NULL){
        while(TRUE){
            nscan=fscanf(fp, "%10[^,],%20[^,],%10[^,],%d%c", AnItem.RecKey,surname,AnItem.Data.phone,&AnItem.Data.code,&termch);

            if(nscan==EOF) break;

            if(nscan!=5 || termch != '\n')
            {
                printf("Improper file format\n");
            }
            else{
                strcat(AnItem.RecKey, " ");
                strcat(AnItem.RecKey, surname);
                AddRec(HList, AnItem);
                }
        }
    }
    fclose(fp);
}

void Search_HashList_By_Subject(HashListType HList, int code)
{
    int i, SubIndex;

    for (i=0; i<HMax;i++)
    {
        SubIndex = HList.HashTable[i];
        while ( SubIndex != EndOfList )
            {
            if(HList.List[SubIndex].Data.code==code)
            {
                printf("%d: [%s, %s, %d]\n", SubIndex, HList.List[SubIndex].RecKey,HList.List[SubIndex].Data.phone, code);
            }
            SubIndex = HList.List[SubIndex].Link;
    }
 }
}

void CreateHashList(HashListType *HList)
/* Λειτουργία: Δημιουργεί μια δομή HList.
   Επιστρέφει: Την δομή HList
*/
{
	int index;

	HList->Size=0;
	HList->StackPtr=0;
    index=0;
	while (index<HMax)
	{
		HList->HashTable[index]=EndOfList;
		index=index+1;
    }
    index=0;
	while(index < VMax-1)
	{
		HList->List[index].Link=index+1;
		index=index+1;
	}
	HList->List[index].Link=EndOfList;
}

boolean FullHashList(HashListType HList)
/* Δέχεται:    Μια δομή HList.
   Λειτουργία: Ελέγχει αν η λίστα List της δομής HList είναι γεμάτη.
   Επιστρέφει: TRUE αν η λίστα List είναι γεμάτη, FALSE διαφορετικά.
*/
{
	return(HList.Size==VMax);
}
void SearchSynonymList(HashListType HList,KeyType KeyArg,int *Loc,int *Pred)
/* Δέχεται:     Μια δομή HList και μια τιμή κλειδιού KeyArg.
    Λειτουργία: Αναζητά μια εγγραφή με κλειδί KeyArg στην υπολίστα συνωνύμων.
    Επιστρέφει: Τη θέση Loc της εγγραφής και τη θέση Pred της προηγούμενης
                εγγραφής στην υπολίστα
*/
{
	int Next;
	Next=HList.SubListPtr;
	*Loc=-1;
	*Pred=-1;
	while(Next!=EndOfList)
	{
		if (strcmp(HList.List[Next].RecKey, KeyArg) == 0)
		{
			*Loc=Next;
			Next=EndOfList;
		}
		else
		{
			*Pred=Next;
			Next=HList.List[Next].Link;
		}
	}
}
void SearchHashList(HashListType HList,KeyType KeyArg,int *Loc,int *Pred)
/* Δέχεται:     Μια δομή HList και μια τιμή κλειδιού KeyArg.
    Λειτουργία: Αναζητά μια εγγραφή με κλειδί KeyArg στη δομή HList.
    Επιστρέφει: Τη θέση Loc της εγγραφής και τη θέση Pred της
                προηγούμενης εγγραφής της υπολίστας στην οποία ανήκει.
                Αν δεν υπάρχει εγγραφή με κλειδί KeyArg τότε Loc=Pred=-1
*/
{
	int HVal;
	HVal=HashKey(KeyArg);
    if (HList.HashTable[HVal]==EndOfList)
	{
		*Pred=-1;
		*Loc=-1;
	}
	else
	{
		HList.SubListPtr=HList.HashTable[HVal];
		SearchSynonymList(HList,KeyArg,Loc,Pred);
	}
}

void AddRec(HashListType *HList,ListElm InRec)
/* Δέχεται:    Μια δομή HList και μια εγγραφή InRec.
   Λειτουργία: Εισάγει την εγγραφή InRec στη λίστα List, αν δεν είναι γεμάτη,
                και ενημερώνει τη δομή HList.
   Επιστρέφει: Την τροποποιημένη δομή HList.
   Έξοδος:     Μήνυμα γεμάτης λίστας, αν η List είναι γεμάτη, διαφορετικά,
                αν υπάρχει ήδη εγγραφή με το ίδιο κλειδί,
                εμφάνιση αντίστοιχου μηνύματος
*/
{
	int Loc, Pred, New, HVal;


	if(!(FullHashList(*HList)))
	{
		Loc=-1;
		Pred=-1;
		SearchHashList(*HList,InRec.RecKey,&Loc,&Pred);
		if(Loc==-1)
		{
			HList->Size=HList->Size +1;
			New=HList->StackPtr;
			HList->StackPtr=HList->List[New].Link;
			HList->List[New]=InRec;
			if (Pred==-1)
			{
			    HVal=HashKey(InRec.RecKey);
                HList->HashTable[HVal]=New;
				HList->List[New].Link=EndOfList;
			}
			else
			{
                HList->List[New].Link=HList->List[Pred].Link;
				HList->List[Pred].Link=New;
			}
		}

		else
		{
			printf("YPARXEI HDH EGGRAFH ME TO IDIO KLEIDI \n");
		}
	}
	else
	{
		printf("Full list...");
	}
}
void DeleteRec(HashListType *HList,KeyType DelKey)
/* DEXETAI:    TH DOMH (HList) KAI To KLEIDI (DelKey) THS EGGRAFHS
               POY PROKEITAI NA DIAGRAFEI
   LEITOYRGIA: DIAGRAFEI, THN EGGRAFH ME KLEIDI (DelKey) APO TH
               LISTA (List), AN YPARXEI ENHMERWNEI THN DOMH HList
   EPISTREFEI: THN TROPOPOIHMENH DOMH (HList)
   EJODOS:     "DEN YPARXEI EGGRAFH ME KLEIDI" MHNYMA
*/
{
	int Loc, Pred, HVal;

	SearchHashList(*HList,DelKey,&Loc,&Pred);
	if(Loc!=-1)
	{
		if(Pred!=-1)
		{
			HList->List[Pred].Link=HList->List[Loc].Link;
		}
		else
		{
			HVal=HashKey(DelKey);
		    HList->HashTable[HVal]=HList->List[Loc].Link;
		}
		HList->List[Loc].Link=HList->StackPtr;
		HList->StackPtr=Loc;
		HList->Size=HList->Size -1;
	}
	else
	{
		printf("DEN YPARXEI  EGGRAFH ME KLEIDI %s \n",DelKey);
	}
}

int findAverage(KeyType s)
{
    int first, last;

    first=toupper(s[0]);
    last=toupper(s[strlen(s)-1]);
    return ((first-64)+(last-64))/2;
}
