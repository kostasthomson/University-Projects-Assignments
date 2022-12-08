#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

// Δήλωση τύπων
typedef struct
{
    int am;
    int ag;
} BinTreeElementType;

typedef struct BinTreeNode *BinTreePointer;

typedef struct BinTreeNode {
    BinTreeElementType Data;
    BinTreePointer LChild, RChild;
} BinTreeNode;

typedef struct
{
    int code;
    char surname[20];
    char name[20];
    char sex;
    int year;
    float grade;
} StudentT;

typedef enum {
    FALSE, TRUE
} boolean;

// Δήλωση συναρτήσεων
void CreateBST(BinTreePointer *Root);
boolean BSTEmpty(BinTreePointer Root);
void RecBSTInsert(BinTreePointer *Root, BinTreeElementType Item);
void RecBSTInorder(BinTreePointer Root);
void RecBSTSearch(BinTreePointer Root, BinTreeElementType keyValueValue, boolean *Found, BinTreePointer *LocPtr);

int BuildBST(BinTreePointer *Root);
void writeNewStudents(BinTreePointer *Root, int *size);
void printStudentsWithGrade(float theGrade);
void PrintStudent(int recNum);

int main()
{
   BinTreePointer ARoot, LocPtr;
   float theGrade;
   int size;
   StudentT student;
   boolean Found;
   BinTreeElementType keyValue;


   //  1
   printf("Q1. Build BST from a file\n");
   size=BuildBST(&ARoot);

   // 2
   printf("Q2. Print size and BST\n");
   printf("Size=%d\n",size);
   printf("Nodes of BST\n");
   RecBSTInorder(ARoot);

   //  3
   printf("\nQ3. Write new students, update file and BST\n");
   writeNewStudents(&ARoot, &size);

   // 4
   printf("Q4. Print size and BST\n");
   printf("Size=%d\n",size);
   printf("Nodes of BST\n");
   RecBSTInorder(ARoot);

   //  5
   printf("\nQ5. Search for a student\n");
   printf("Give student's code? ");
   scanf("%d",&keyValue.am);
   RecBSTSearch(ARoot,keyValue,&Found,&LocPtr);
   if (Found)
   {
     PrintStudent(LocPtr->Data.ag);}
   else
   {printf("Student with am %d not found\n",LocPtr->Data.am);}

   // 6
   printf("Q6. Print size and BST\n");
   printf("Size=%d\n",size);
   printf("Nodes of BST\n");
   RecBSTInorder(ARoot);

   //  7
   printf("\nQ7. Print students with grades >= given grade\n");
    printf("Give the grade: ");
    scanf("%f", &theGrade);
    printStudentsWithGrade(theGrade);


   return 0;
}

int BuildBST(BinTreePointer *Root)
{
  FILE *fp;
  int size;
  int nscan;
  char termch;
  BinTreeElementType indexRec;
  StudentT student;
  CreateBST(Root);

  fp = fopen("foitites.dat" ,"r");
  size=0;
  if(fp == NULL)
     {
         printf("Improper file format");
      exit(1);
     }
  else
    {
     while(TRUE)
     {
         nscan = fscanf(fp,"%d,%20[^,],%20[^,],%c,%d,%f%c",&student.code,student.name,student.surname,&student.sex,&student.year,&student.grade,&termch);
         if ( nscan == EOF )
            break;
         if ( nscan != 7||termch!='\n' )
            {printf("Improper file format\n");
            break;}
         else // Αλλιώς
         {
             indexRec.am=student.code;
             indexRec.ag=size;
             RecBSTInsert(&(*Root),indexRec);
             size++;
         }
     }

    }
  fclose(fp);
  return size;
}
void writeNewStudents(BinTreePointer *Root, int *size)

{
   BinTreePointer LocPtr;
   StudentT student;
   boolean Found;
   int am;
   char ch;
   FILE *fp;
   BinTreeElementType indexRec;


    fp=fopen("foitites.dat","a");
    if(fp == NULL)
      printf("Problem opening file");
    else
      {
          do
            {
                 printf("Give student's AM? ");
                 scanf("%d",&indexRec.am);
                 RecBSTSearch(*Root,indexRec,&Found,&LocPtr);
                 if(!Found)
                 {
                 student.code=indexRec.am;
                 printf("Give student surname? ");
                 scanf("%s",student.surname); getchar();
                 printf("Give student name? ");
                 scanf("%s",student.name); getchar() ;
                 printf("Give student sex F/M? ");
                 scanf("%c",&student.sex); getchar();
                 printf("Give student's registration year? ");
                 scanf("%d",&student.year);
                 printf("Give student's grade? ");
                 scanf("%f",&student.grade);

                 indexRec.am = student.code;
                 indexRec.ag = *size;
                 RecBSTInsert(Root,indexRec);
                 fprintf(fp,"%d,%s,%s,%c,%d,%.1f\n",student.code,student.name, student.surname,student.sex,student.year,student.grade);
                 (*size)++;
                 printf("Size=%d\n",*size);
                 }
                 else
                  {printf("Student with am AM %d already exists\n",indexRec.am);}


            printf("\nContinue Y/N: ");
            do
            {

            scanf("%c", &ch);
            } while (toupper(ch)!= 'N' && toupper(ch)!= 'Y');

       } while (toupper(ch)!='N');
       }

    fclose(fp);
}

void PrintStudent(int recNum)
{
    FILE *fp;
    int nscan;
    int lines;
    char termch;
    StudentT student;
    BinTreeElementType indexRec;

    lines=0;

    fp=fopen("foitites.dat","r");
    if(fp == NULL)
      printf("Improper file format");
    else
      {
         while(lines<=recNum)
         {
          nscan = fscanf(fp, "%d,%20[^,],%20[^,],%c,%d,%f%c",&student.code,student.name, student.surname,&student.sex,&student.year,&student.grade,&termch);
          if ( nscan == EOF )
            {break;}
          if ( nscan != 7||termch!='\n' )
            { printf("Error\n");}
          lines++;
          }
          if(lines==recNum+1)
        printf("%d,%s,%s,%c,%d,%.1f\n",student.code,student.name, student.surname,student.sex,student.year,student.grade);
        fclose(fp);
    }

}


void printStudentsWithGrade(float theGrade)
{

    FILE *fp;
    int nscan;
    char termch;
    StudentT student;

    fp = fopen("foitites.dat" ,"r");

    if(fp == NULL)
     printf("Improper file format");
    else
      {
         while(TRUE)
         {
          nscan = fscanf(fp, "%d,%20[^,],%20[^,],%c,%d,%f%c",&student.code,student.name, student.surname,&student.sex,&student.year,&student.grade,&termch);
          if ( nscan == EOF )
            {break;}
          if ( nscan != 7||termch!='\n' )
            { printf("Error\n");}
          else
           {
             if (student.grade>=theGrade)
             {
                 printf("%d,%s,%s,%c,%d,%.1f\n",student.code,student.name, student.surname,student.sex,student.year,student.grade);
             }
           }
          }

        fclose(fp);
    }


}

void RecBSTInorder(BinTreePointer Root)
/* Δέχεται:    Ένα δυαδικό δέντρο με το δείκτη Root να δείχνει στην ρίζα του.
   Λειτουργία: Εκτελεί ενδοδιατεταγμένη διάσχιση του δυαδικού δέντρου και
                επεξεργάζεται κάθε κόμβο ακριβώς μια φορά.
   Εμφανίζει: Το περιεχόμενο του κόμβου, και εξαρτάται από το είδος της επεξεργασίας
*/
{
    if (Root!=NULL) {
    //    printf("L");
        RecBSTInorder(Root->LChild);
        printf("(%d, %d), ",Root->Data.am,Root->Data.ag); // 'Αλλαξε από printf("%d ",Root->Data);
    //    printf("R");
        RecBSTInorder(Root->RChild);
    }
   // printf("U");
}

void CreateBST(BinTreePointer *Root)
/* Λειτουργία: Δημιουργεί ένα κενό ΔΔΑ.
   Επιστρέφει:  Τον μηδενικό δείκτη(NULL) Root
*/
{
    *Root = NULL;
}

boolean BSTEmpty(BinTreePointer Root)
/* Δέχεται:   Ενα ΔΔα με το Root να δείχνει στη ρίζα του.
  Λειτουργία: Ελέγχει αν το ΔΔΑ είναι κενό.
  Επιστρέφει: TRUE αν το ΔΔΑ είναι κενό και FALSE διαφορετικά
*/
{
    return (Root==NULL);
}


void RecBSTSearch(BinTreePointer Root, BinTreeElementType keyValueValue,
                    boolean *Found, BinTreePointer *LocPtr)
/* Δέχεται:    Ένα ΔΔΑ με το δείκτη Root να δείχνει στη ρίζα του και μια τιμή keyValueValue.
   Λειτουργία: Αναζητά στο ΔΔΑ έναν κόμβο με τιμή keyValueValue στο πεδίο κλειδί του.
   Επιστρέφει: Η Found έχει τιμή TRUE και ο δείκτης LocPtr δείχνει στον κόμβο που
                περιέχει την τιμή keyValueValue, αν η αναζήτηση είναι επιτυχής.
                Διαφορετικά η Found έχει τιμή FALSE
*/
{
    if (BSTEmpty(Root))
        *Found=FALSE;
    else
        if (keyValueValue.am < Root->Data.am)
            RecBSTSearch(Root->LChild, keyValueValue, &(*Found), &(*LocPtr));
        else
            if (keyValueValue.am > Root->Data.am)
                RecBSTSearch(Root->RChild, keyValueValue, &(*Found), &(*LocPtr));
            else
                {
                    *Found = TRUE;
                    *LocPtr=Root;
                }
}

void RecBSTInsert(BinTreePointer *Root, BinTreeElementType Item)
/* Δέχεται:     Ένα ΔΔΑ με το δείκτη Root να δείχνει στη ρίζα του και ένα στοιχείο Item.
   Λειτουργία:  Εισάγει το στοιχείο Item στο ΔΔΑ.
   Επιστρέφει: Το τροποποιημένο ΔΔΑ με τον δείκτη Root να δείχνει στη ρίζα του
*/
{
    if (BSTEmpty(*Root)) {
        (*Root) = (BinTreePointer)malloc(sizeof (struct BinTreeNode));
        (*Root) ->Data = Item;
        (*Root) ->LChild = NULL;
        (*Root) ->RChild = NULL;
    }
    else
        if (Item.am < (*Root) ->Data.am)
            RecBSTInsert(&(*Root) ->LChild,Item);
        else if (Item.am > (*Root) ->Data.am)
            RecBSTInsert(&(*Root) ->RChild,Item);
        else
            printf("TO STOIXEIO EINAI HDH STO DDA\n");
}
