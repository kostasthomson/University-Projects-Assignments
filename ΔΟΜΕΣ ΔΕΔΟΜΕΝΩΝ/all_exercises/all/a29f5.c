#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct
{
    int amka;
    int afm;
    int age;
} BinTreeElementType;
typedef struct BinTreeNode *BinTreePointer;

struct BinTreeNode
{
    BinTreeElementType Data;
    BinTreePointer LChild, RChild;
};

typedef enum {
    FALSE, TRUE
} boolean;


void CreateBST(BinTreePointer *Root);
boolean EmptyBST(BinTreePointer Root);
void BSTInsert(BinTreePointer *Root, BinTreeElementType Item);
void BSTSearch2(BinTreePointer Root, BinTreeElementType KeyValue, boolean *Found, BinTreePointer *LocPtr, BinTreePointer *Parent);
void BSTSearch(BinTreePointer Root, BinTreeElementType KeyValue, boolean *Found, BinTreePointer *LocPtr);
void BSTDelete(BinTreePointer *Root, BinTreeElementType KeyValue);
void InorderTraversal(BinTreePointer Root);


int main()
{
    BinTreePointer under_60, over_60, ptr;
    BinTreeElementType person;
    boolean found;
    char ans;

    CreateBST(&under_60);
    CreateBST(&over_60);

    do
    {
        printf("Give AMKA? ");
        scanf("%d", &person.amka);
        getchar();
        printf("Give AFM? ");
        scanf("%d", &person.afm);
        getchar();
        printf("Give age? " );
        scanf("%d", &person.age);
        getchar();
        if(person.age<=60)
            BSTInsert(&under_60, person);
        else
            BSTInsert(&over_60, person);
        printf("\nContinue Y/N:");
        scanf("%c", &ans);
        getchar();
    } while(toupper(ans)!='N');

    printf("\nPeople with age less-equal 60\n");
    InorderTraversal(under_60);
    printf("\n");
    printf("\nPeople with age greater than 60\n");
    InorderTraversal(over_60);
    printf("\n");

    for(int i=0;i<3;i++)
    {
        printf("Give AMKA: ");
        scanf("%d", &person.amka);
        printf("Give age: ");
        scanf("%d", &person.age);
        if(person.age <= 60)
            BSTSearch(under_60, person, &found, &ptr);
        else
            BSTSearch(over_60, person, &found, &ptr);

        if(found)
       {
          if(person.age==ptr->Data.age)
            printf("The person with AMKA %d, AFM %d and age %d is in the catalogue\n",ptr->Data.amka,ptr->Data.afm,ptr->Data.age);
        else
            printf("The person with AMKA %d has age %d different from the person you are looking for\n",ptr->Data.amka,ptr->Data.age);
       }

       else
        printf("The person with AMKA %d and age %d is Unknown\n",person.amka,person.age);

        /*switch(i)
        {
            case 0:
                printf("The person with AMKA %d, AFM %d, and age %d is the catalogue\n", ptr->Data.amka, ptr->Data.afm, ptr->Data.age);
                break;
            case 1:
                printf("The person with AMKA %d has age %d different from the person you are looking for\n", ptr->Data.amka, ptr->Data.age);
                break;
            case 2:
                printf("The person with AMKA %d and age %d is Unknown\n", ptr->Data.amka, ptr->Data.age);
                break;
        }*/
    }
    return 0;
}

void CreateBST(BinTreePointer *Root)
{
    *Root = NULL;
}

boolean EmptyBST(BinTreePointer Root)
{   return (Root==NULL);
}

void BSTInsert(BinTreePointer *Root, BinTreeElementType Item)
{
    BinTreePointer LocPtr, Parent;
    boolean Found;

    LocPtr = *Root;
    Parent = NULL;
    Found = FALSE;
    while (!Found && LocPtr != NULL) {
        Parent = LocPtr;
        if (Item.amka < LocPtr->Data.amka)
            LocPtr = LocPtr ->LChild;
        else if (Item.amka > LocPtr ->Data.amka)
            LocPtr = LocPtr ->RChild;
        else
            Found = TRUE;
    }
    if (Found)
        printf("To (%d,%d,%d) EINAI HDH STO DDA\n", Item.amka, Item.afm, Item.age);
    else {
        LocPtr = (BinTreePointer)malloc(sizeof (struct BinTreeNode));
        LocPtr ->Data = Item;
        LocPtr ->LChild = NULL;
        LocPtr ->RChild = NULL;
        if (Parent == NULL)
            *Root = LocPtr;
        else if (Item.amka < Parent ->Data.amka)
            Parent ->LChild = LocPtr;
        else
            Parent ->RChild = LocPtr;
    }
}
void BSTSearch2(BinTreePointer Root, BinTreeElementType KeyValue, boolean *Found, BinTreePointer *LocPtr, BinTreePointer *Parent)
{
    *LocPtr = Root;
    *Parent=NULL;
    *Found = FALSE;
    while (!(*Found) && *LocPtr != NULL)
    {
        if (KeyValue.amka < (*LocPtr)->Data.amka) {
            *Parent=*LocPtr;
            *LocPtr = (*LocPtr)->LChild;
        }
        else
            if (KeyValue.amka > (*LocPtr)->Data.amka) {
                *Parent=*LocPtr;
                *LocPtr = (*LocPtr)->RChild;
            }
            else *Found = TRUE;
    }

}

void BSTSearch(BinTreePointer Root, BinTreeElementType KeyValue, boolean *Found, BinTreePointer *LocPtr)
{
    (*LocPtr) = Root;
    (*Found) = FALSE;
    while (!(*Found) && (*LocPtr) != NULL)
    {
        if (KeyValue.amka < (*LocPtr)->Data.amka)
            (*LocPtr) = (*LocPtr)->LChild;
        else
            if (KeyValue.amka > (*LocPtr)->Data.amka)
                (*LocPtr) = (*LocPtr)->RChild;
            else (*Found) = TRUE;
    }
}

void BSTDelete(BinTreePointer *Root, BinTreeElementType KeyValue)
{

   BinTreePointer
   n,
   Parent,
   nNext,
   SubTree;
   boolean Found;

     BSTSearch2(*Root, KeyValue, &Found , &n, &Parent);
     if (!Found)
        printf("TO STOIXEIO (%d, %d, %d) DEN EINAI STO DDA\n", KeyValue.amka, KeyValue.afm, KeyValue.age);
     else {
          if (n->LChild != NULL && n->RChild != NULL)
          {
                 nNext = n->RChild;
                 Parent = n;
                 while (nNext->LChild !=NULL)
                 {
                      Parent = nNext;
                      nNext = nNext->LChild;
                 }
                n->Data = nNext->Data;
                n = nNext;
          }
          SubTree = n->LChild;
          if (SubTree == NULL)
             SubTree = n->RChild;
          if (Parent == NULL)
             *Root = SubTree;
          else if (Parent->LChild == n)
                  Parent->LChild = SubTree;
               else
                   Parent->RChild = SubTree;
          free(n);
     }
}

void InorderTraversal(BinTreePointer Root)
{
    if (Root!=NULL) {
        InorderTraversal(Root->LChild);
        printf("(%d, %d, %d) ",Root->Data.amka,Root->Data.afm,Root->Data.age);
        InorderTraversal(Root->RChild);
    }
}
