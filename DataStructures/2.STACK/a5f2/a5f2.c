#include <stdio.h>
#include <stdlib.h>

#define StackLimit 15

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

int main()
{
    StackElementType i, n, item, temp;
    StackType Stack, tempStack;
    CreateStack(&Stack);
    CreateStack(&tempStack);
    for(i=0;i<StackLimit;i++){Push(&Stack, i*10);}
    TraverseStack(Stack);
    do{
        printf("Give nth element (n<=%d) ", (int)(Stack.Top-1)/2);
        scanf("%d", &n);
    }while(n>(int)(Stack.Top-1)/2);
//case 1:
    Pop(&Stack, &item);
    Pop(&Stack, &item);
    printf("\nQuestion a: x=%d\n", item);
    TraverseStack(Stack);
//case 2:
    Pop(&Stack, &temp);
    Pop(&Stack, &item);
    printf("\nQuestion b: x=%d\n", item);
    Push(&Stack, item);
    Push(&Stack, temp);
    TraverseStack(Stack);
//case 3:
    for(int t=0;t<n;t++) {Pop(&Stack, &item);}
    printf("\nQuestion c: x=%d\n", item);
    TraverseStack(Stack);
//case 4:
    for(int t = 0; t<n;t++) {Pop(&Stack, &item);Push(&tempStack, item);}
    printf("\nQuestion d: x=%d\n", item);
    for(int t = 0; t<n;t++) {Pop(&tempStack, &item);Push(&Stack, item);}
    TraverseStack(Stack);
//case 5:
    while(!EmptyStack(Stack)) {Pop(&Stack, &item);Push(&tempStack, item);}
    printf("\nQuestion e: x=%d\n", item);
    while(!EmptyStack(tempStack)) {Pop(&tempStack, &item);Push(&Stack, item);}
    TraverseStack(Stack);
//case 6:
    for(int t=Stack.Top;t>=2;t--) {Pop(&Stack, &item);Push(&tempStack, item);}
    printf("\nQuestion f: x=%d\n", item);
    while(!EmptyStack(tempStack)){Pop(&tempStack, &item);Push(&Stack, item);}
    TraverseStack(Stack);
//case 7:
    while(!EmptyStack(Stack)) {Pop(&Stack, &item);}
    printf("\nQuestion g: x=%d\n", item);
    TraverseStack(Stack);

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
