// Filename InfToRPN;
//             {METATROPO MIAS ENDO8EMATIKHS PARASTASHS SE RPN}


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "StChADT.h"

#define   MaxExpression 50 //* MEGISTO MEGE8OS ARI8MHTIKHS EKFRASHS *
#define  EndMark ';'  //* SHMATODOTEI TO TELOS THS ENDO8EMATIKHS EKFRASHS *
#define  OperatorSet "+-*/"  //* SYNOLO TELESTWN *

int Priority(char Operator);
void ConvertToRPN(char Expression[]);

int main()
{
    char Expression[MaxExpression]; //* ENDO8EMATIKH EKFRASH *)
    int i;
    fflush(stdin);

    printf("DWSE ENDOTHEMATIKH EKFRASH. DWSE ; GIA TELOS:");
    i=-1;
    do
    {
        i++;
        Expression[i]=getchar();
    } while (Expression[i] !=EndMark);
    i++;
    Expression[i]='\0';
    printf("H ENDOTHEMATIKH PARASTASSH SE RPN MORFH:");
    ConvertToRPN(Expression);
    printf("\n");
    system("PAUSE");
    return 0;
}

int Priority(char Operator)
{
    switch (Operator)
    {
        case '(' : return 0;
        case '+' :  case '-' : return 1;
        case '*' :  case '/' : return 2;
        default:
            printf("Invalid token: %c. Exting now...", Operator);
            exit(-11);
    }
}

void ConvertToRPN(char Expression[])
{
    StackType AStack;
    int i;
    char Token, TopToken;
    boolean DonePopping, Wrong;

    CreateStack(&AStack);
    Wrong=FALSE;
    i=0;
    Token=Expression[0];
    while ((Token!=EndMark) && (!Wrong))
    {
        while (Expression[i]==' ')          //ingnore empty space
            i++;
        Token=Expression[i];
        if (Token=='(')                 // left parenthesis
            Push(&AStack, Token);
        else
            if (Token==')')             // right parenthesis
            {
                DonePopping=FALSE;
                do
                {
                    if (EmptyStack(AStack))
                        Wrong=TRUE;
                    else
                    {
                        Pop(&AStack, &TopToken);
                        if (TopToken !='(')
                            printf("%2c", TopToken);
                        else
                            DonePopping= TRUE;
                    }
                } while ((!DonePopping) && (!Wrong));
            }
            else {
                if (strchr(OperatorSet, Token) !=NULL)   // Operator
                {
                    DonePopping=FALSE;
                    while ((!EmptyStack(AStack)) && (!DonePopping))
                    {
                        Pop(&AStack,&TopToken);
                        if (Priority(Token)<=Priority(TopToken))
                            printf("%2c",TopToken);
                        else
                        {
                            Push(&AStack, TopToken);
                            DonePopping=TRUE;
                        }
                    }
                    Push(&AStack,Token);
                }
                else
                    if (Token!=EndMark)   //Operator
                        printf("%2c",Token);
                i++;
            }
    }// while
    //pop stack and print elements of stack

    while ((!EmptyStack(AStack)) && (!Wrong))
    {
        Pop(&AStack,&TopToken);
        if (TopToken !='(')
            printf("%c",TopToken);
        else Wrong=TRUE;
    }

    if (Wrong)
        printf("Error in infix notation\n");
    else printf("\n");
}
