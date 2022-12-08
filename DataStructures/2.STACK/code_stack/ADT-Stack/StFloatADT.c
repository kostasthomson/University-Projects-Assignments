// FILENAME StFloatADT.c
                    //* YLOPOIHSH STOIBAS ME PINAKA *
              //*TA STOIXEIA THS STOIBAS EINAI TYPOY float*

#include <stdio.h>
#include "StFloatADT.h"

void CreateStack(StackType *Stack)
/* LEITOYRGIA: DHMIOYRGEI MIA KENH STOIBA.
   EPISTREFEI: MIA KENH STOIBA *)
*/
{
    Stack -> Top = -1;
   // (*Stack).Top = -1;
}

boolean EmptyStack(StackType Stack)
/* DEXETAI:    MIA STOIBA Stack.
   LEITOYRGIA: ELEGXEI AN H STOIBA Stack EINAI KENH.
   EPISTREFEI: TRUE AN H Stack EINAI KENH, FALSE DIAFORETIKA. */
{
    return (Stack.Top == -1);
}

boolean FullStack(StackType Stack)
/* DEXETAI:    MIA STOIBA Stack.
   LEITOYRGIA: ELEGXEI AN H STOIBA Stack EINAI GEMATH.
   EPISTREFEI: TRUE AN H STOIBA Stack EINAI GEMATH, FALSE DIAFORETIKA. */
{
    return (Stack.Top == (StackLimit - 1));
}

void Push(StackType *Stack, StackElementType Item)
/* DEXETAI:    MIA STOIBA Stack KAI TO STOIXEIO Item.
   LEITOYRGIA: EISAGEI STH KORYFH THS STOIBAS Stack, AN DEN EINAI GEMATH,
               TO STOIXEIO Item.
   EPISTREFEI: THN TROPOPOIHMENH STOIBA Stack.
   EJODOS:     MHNYMA GEMATHS STOIBAS, AN H STOIBA EINAI GEMATH. */
{
    if (!FullStack(*Stack)) {
        Stack -> Top++;
        Stack -> Element[Stack -> Top] = Item;
    } else
        printf("Full Stack...");
}

void Pop(StackType *Stack, StackElementType *Item)
/* DEXETAI:    MIA STOIBA Stack.
   LEITOYRGIA: AFAIREI APO TH KORYFH THS STOIBAS Stack, AN DEN EINAI KENH,
               TO STOIXEIO Item.
   EPISTREFEI: TO STOIXEIO Item KAI THN TROPOPOIHMENH STOIBA Stack
   EJODOS:     MHNYMA KENHS STOIBAS, AN H STOIBA EINAI KENH. */
{
    if (!EmptyStack(*Stack)) {
        *Item = Stack -> Element[Stack -> Top];
        Stack -> Top--;
    } else
        printf("Empty Stack...");
}


