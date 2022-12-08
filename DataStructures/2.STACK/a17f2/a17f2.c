#include <stdio.h>
#include <stdlib.h>

#define StackLimit 50

typedef enum {
    FALSE, TRUE
} boolean;

typedef int StackElementType;

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
StackType CopyStack(StackType s1);


int main(){
	StackType s1, s2;
	StackElementType i;

	CreateStack(&s1);
	printf("Stack s1\n");
	for(i=0;i<20;i++){
		Push(&s1, i);
	}
	TraverseStack(s1);
	s2 = CopyStack(s1);
	printf("After copying s1 to s2\n");
	printf("Stack s1\n");
	TraverseStack(s1);
	printf("Stack s2\n");
	TraverseStack(s2);
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
        printf("%d ",Stack.Element[i]);
    }
    printf("\n");
}

StackType CopyStack(StackType s1){
	StackType s2, temp;
	StackElementType i, item;

	CreateStack(&s2);
	CreateStack(&temp);

	while(!EmptyStack(s1)){
		Pop(&s1, &item);
		Push(&temp, item);
	}
	while(!EmptyStack(temp)){
		Pop(&temp, &item);
		Push(&s2, item);
	}
	return s2;
}
