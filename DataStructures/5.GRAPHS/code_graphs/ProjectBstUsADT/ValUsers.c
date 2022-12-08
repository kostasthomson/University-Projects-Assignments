// filename ValUsers.c

// ΕΛΕΓΧΟΣ ΤΑΥΤΟΤΗΤΑΣ ΧΡΗΣΤΩΝ

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "BstUsADT.h"

void Login(BinTreeElementType *UserRec,boolean *MoreUsers);
void BuildTree(FILE *UsersFile,BinTreePointer *UserTree, boolean *stop);

int main()
{
    FILE *UsersFile;
    BinTreeElementType UserRec;
    BinTreePointer UserTree;
    BinTreePointer LocPtr;
    boolean Found, MoreUsers, stop;

    UsersFile = fopen("Users.txt", "r");
    if (UsersFile == NULL)
        printf("Cannot open Users file\n");
    else
    {
        printf("\nDWSE 0 GIA NA TERMATISEI TO PROGRAMMA\n");
        BuildTree(UsersFile,&UserTree,&stop);
        if (!stop)
        {
            InorderTraversal(UserTree);
            Login(&UserRec,&MoreUsers);
            while (MoreUsers)
            {
                BSTSearch(UserTree,UserRec,&Found,&LocPtr);
                if (Found)
                    if (strcmp(LocPtr->Data.password,UserRec.password)==0)
                        printf("EGKYROS XRHSTHS!\n");
                    else
                        printf("MH EGKYRO password!\n");
                else
                    printf("MH EGKYRO User-Id!\n");
                Login(&UserRec,&MoreUsers);
            }
        }
    }
    return 0;
    system("PAUSE");
}

void BuildTree(FILE *UsersFile,BinTreePointer *UserTree, boolean *stop)
{
    BinTreeElementType UserRec;
    int nscan;
    char termch;

    *stop=FALSE;
    CreateBST(&(*UserTree));
    while (TRUE)
    {
        nscan = fscanf(UsersFile, "%d, %10[^\n]%c",
                               &UserRec.id, UserRec.password,&termch);
        if (nscan == EOF) break;
        if (nscan != 3 || termch != '\n')
        {
            printf("Improper file format\n");
            *stop=TRUE;
            break;
        }
        else
            BSTInsert(&(*UserTree),UserRec);
   }
}

void Login(BinTreeElementType *UserRec,boolean *MoreUsers)
{
    printf("User-Id? ");
    scanf("%d",&(UserRec->id));
    if (UserRec->id ==0)
        *MoreUsers=FALSE;
    else
    {
        *MoreUsers=TRUE;
        printf("Password? ");
        scanf("%s",UserRec->password);
   }
}
