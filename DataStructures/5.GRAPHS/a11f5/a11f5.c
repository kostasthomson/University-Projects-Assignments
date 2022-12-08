#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define letters 50

typedef char *BinTreeElementType;
typedef struct BinTreeNode *BinTreePointer;

struct BinTreeNode {
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

void CreateDictionary(BinTreePointer *Root, FILE *fp);
int SpellingCheck(BinTreePointer Root, FILE *fp);

int main()
{
    FILE *fp1, *fp2;
    BinTreePointer root;
    int i;

    fp1 = fopen("i112f5.txt", "r");
    fp2 = fopen("i111f5.txt", "r");

    BinTreeElementType item;
    while(feof(fp1))
    {
        fscanf(fp1,"%s",item);
        printf("%s", item);
    }
/*
    CreateBST(&root);
    CreateDictionary(&root, fp1);

    printf("**********Dictionary**********\n");
    InorderTraversal(root);

    printf("**********Not in Dictionary**********\n");
    printf("Number of words not in Dictionary:%d\n", SpellingCheck(root, fp2));
*/
    return 0;
}

void CreateDictionary(BinTreePointer *Root, FILE *fp)
{
    BinTreeElementType item;
    while(feof(fp))
    {
        fscanf(fp,"%s",item);
        BSTInsert(Root,item);
    }
    /*
    int line;
    char word[letters+1];
    char term;

    line = fscanf(fp, "%[^\n]%c", word, &term);
    while(line != EOF)
    {
        if(line != 2 || term != '\n')
            printf("egine blakeia\n");
        BSTInsert(Root, word);
        line = fscanf(fp, "%[^\n]%c", word, &term);
    }*/
}

int SpellingCheck(BinTreePointer Root, FILE *fp)
{
    BinTreePointer ptr;
    BinTreeElementType item;
    boolean found;
    int count;
    while(feof(fp))
    {
        fscanf(fp,"%s",item);
        BSTSearch(Root, item, &found, &ptr);
        if(!found)
            fprintf(fp, "%s", item);
            count++;
    }
    /*
    int line, count=0;
    char word[letters+1];
    char term;
    boolean found;
    BinTreePointer ptr;


    line = fscanf(fp, "%[^\n]%c", word, &term);
    while(line != EOF)
    {
        if(line != 2 || term != '\n')
            printf("egine blakeia\n");
        BSTSearch(Root, word, &found, &ptr);
        if(!found)
            fprintf(fp, "%s", word);
            count++;
        line = fscanf(fp, "%[^\n]%c", word, &term);
    }
    printf("Number of words not in Dictionary:%d\n", count);*/
    return count;
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
        if (Item < LocPtr->Data)
            LocPtr = LocPtr ->LChild;
        else if (Item > LocPtr ->Data)
            LocPtr = LocPtr ->RChild;
        else
            Found = TRUE;
    }
    if (Found)
        printf("To %s EINAI HDH STO DDA\n", Item);
    else {
        LocPtr = (BinTreePointer)malloc(sizeof (struct BinTreeNode));
        strcpy(LocPtr ->Data,Item);
        //LocPtr ->Data = Item;
        LocPtr ->LChild = NULL;
        LocPtr ->RChild = NULL;
        if (Parent == NULL)
            *Root = LocPtr;
        else if (Item < Parent ->Data)
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
        if (KeyValue < (*LocPtr)->Data) {
            *Parent=*LocPtr;
            *LocPtr = (*LocPtr)->LChild;
        }
        else
            if (KeyValue > (*LocPtr)->Data) {
                *Parent=*LocPtr;
                *LocPtr = (*LocPtr)->RChild;
            }
            else *Found = TRUE;
    }

}

void BSTSearch(BinTreePointer Root, BinTreeElementType KeyValue, boolean *Found, BinTreePointer *LocPtr)
{
    int cmp;

    (*LocPtr) = Root;
    (*Found) = FALSE;
    while (!(*Found) && (*LocPtr) != NULL)
    {
        cmp = strcmp(KeyValue, (*LocPtr)->Data);
        if (cmp < 0)
            (*LocPtr) = (*LocPtr)->LChild;
        else
            if (cmp > 0)
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
        printf("TO STOIXEIO %s DEN EINAI STO DDA\n", KeyValue);
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
                strcpy(n->Data, nNext->Data);
                //n->Data = nNext->Data;
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
        printf("%s ",Root->Data);
        InorderTraversal(Root->RChild);
    }
}



