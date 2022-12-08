#include <stdio.h>
#include <stdlib.h>

#define StackLimit 50

typedef enum {
    FALSE, TRUE
} boolean;

typedef char StackElementType;

typedef struct  {
    int Top;
    StackElementType Element[StackLimit];
} StackType;

void CreateStack(StackType *Stack);
void Push(StackType *Stack, StackElementType Item);
void Pop(StackType *Stack, StackElementType *Item);
void TraverseStack(StackType Stack);
boolean EmptyStack(StackType Stack);
boolean FullStack(StackType Stack);


int main()
{
    StackElementType ch, item;
    StackType x;
    boolean same = TRUE;

    CreateStack(&x);
    printf("Enter string:\n");
//insert data characters to the stack
    scanf("%c", &ch);
    getchar();
    if(ch == '#'){
        return 0;
    }
    while(ch != 'C' ){
         Push(&x, ch);
         scanf("%c", &ch);
        getchar();
        if(ch == '#'){
            same = FALSE;
            break;
        }
    }
//checking 'same' state
	if(same){
		//checking every new character
		while(!EmptyStack(x)){
			scanf("%c", &ch);
			getchar();
			Pop(&x, &item);
			//printf("the if statement\t%c\t%c\n", ch, item);
			if(ch != item){
				same = FALSE;
				break;
            }
		}
		if(EmptyStack(x) && same){
			scanf("%c", &ch);
			getchar();
			if(ch == '#'){
				same = TRUE;
			}else{
				same = FALSE;
			}
		}
	}
//checking different cases of same bool values
    if(same){
        printf("TRUE\n");
    }else{
        printf("FALSE\n");
    }
    return 0;
}

boolean EmptyStack(StackType Stack)
{
    return (Stack.Top == -1);
}

boolean FullStack(StackType Stack)
{
    return (Stack.Top == (StackLimit - 1));
}

void CreateStack(StackType *Stack)
{
    Stack -> Top = -1;
   // (*Stack).Top = -1;
}

void Push(StackType *Stack, StackElementType Item)
{
    if (!FullStack(*Stack)) {
        Stack -> Top++;
        Stack -> Element[Stack -> Top] = Item;
    } else
        printf("Full Stack...");
}

void Pop(StackType *Stack, StackElementType *Item)
{
    if (!EmptyStack(*Stack)) {
        *Item = Stack -> Element[Stack -> Top];
        Stack -> Top--;
    } else
        printf("Empty Stack...");
}

void TraverseStack(StackType Stack)
{
    int i;
    printf("plithos sto stack %d\n",Stack.Top+1);
    for (i=0;i<=Stack.Top;i++) {
        printf("%c\n",Stack.Element[i]);
    }
    printf("\n");
}

