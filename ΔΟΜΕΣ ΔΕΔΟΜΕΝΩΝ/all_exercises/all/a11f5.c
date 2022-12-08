#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define letters 50

typedef char BinTreeElementType[letters];
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
void InorderTraversal(BinTreePointer Root);
void CreateDictionary(BinTreePointer *Root, FILE *fp);
int SpellingCheck(BinTreePointer Root, FILE *fp);

int main()
{
    FILE *fp1;
    FILE *fp2;
    BinTreePointer root;
    int i;

    fp1 = fopen("i112f5.txt", "r");
    fp2 = fopen("i111f5.txt", "r");

    CreateBST(&root);
    CreateDictionary(&root, fp1);

    printf("**********Dictionary**********\n");
    InorderTraversal(root);

    printf("**********Not in Dictionary**********\n");
    printf("Number of words not in Dictionary: %d\n",SpellingCheck(root,fp2));

    fclose(fp1);
    fclose(fp2);
    return 0;
}

void CreateDictionary(BinTreePointer *Root, FILE *fp)
{
    BinTreeElementType item;
    while(!feof(fp))
    {
        fscanf(fp,"%s",item);
        BSTInsert(&(*Root),item);
    }
    fclose(fp);
}

int SpellingCheck(BinTreePointer Root, FILE *fp)
{
    int count=0;
    boolean found;
    BinTreePointer ptr;
    BinTreeElementType item;

    while(!feof(fp))
    {
        fscanf(fp,"%s",item);
        BSTSearch(Root, item, &found, &ptr);
        if(!found)
           {
               printf( "%s\n", item);
               count++;
           }
    }
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
        if (strcmp(Item,LocPtr->Data)<0)
            LocPtr = LocPtr ->LChild;
        else if (strcmp(Item,LocPtr->Data)>0)
            LocPtr = LocPtr ->RChild;
        else
            Found = TRUE;
    }
    if (Found)
        printf("To %s EINAI HDH STO DDA\n", Item);
    else {
        LocPtr = (BinTreePointer)malloc(sizeof (struct BinTreeNode));
        strcpy(LocPtr ->Data,Item);
        LocPtr ->LChild = NULL;
        LocPtr ->RChild = NULL;
        if (Parent == NULL)
            *Root = LocPtr;
        else if (strcmp(Item,Parent ->Data) < 0)
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
        if(strcmp(KeyValue, (*LocPtr)->Data)<0)
            (*LocPtr) = (*LocPtr)->LChild;
        else
            if(strcmp(KeyValue, (*LocPtr)->Data)>0)
                (*LocPtr) = (*LocPtr)->RChild;
            else (*Found) = TRUE;
    }
}

void InorderTraversal(BinTreePointer Root)
{
    if (Root!=NULL) {
        InorderTraversal(Root->LChild);
        printf("%s\n ",Root->Data);
        InorderTraversal(Root->RChild);
    }
}
