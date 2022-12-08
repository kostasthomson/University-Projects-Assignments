#include <stdio.h>
#include <stdlib.h>

#define StackLimit 50

typedef enum {
    FALSE, TRUE
} boolean;

typedef struct{
    int price;
    char size;
} StackElementType;

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
    int i;
    int shirts;
    char key;
    StackElementType shirt;
    StackType Box, tempBox;

    CreateStack(&Box);
    CreateStack(&tempBox);
//1
    printf("Give number of items ");
    scanf("%d", &shirts);
//2
    printf("Give the items to store\n");
    for(i=0;i<shirts;i++){
        printf("Give price ");
        scanf("%d", &shirt.price);
        getchar();
        printf("Give size ");
        scanf("%c", &shirt.size);
        getchar();
        Push(&Box, shirt);
    }
//3
    printf("Items in the box\n");
    TraverseStack(Box);
//4
    printf("What size do you want? ");
    scanf("%c", &key);
    for(i=Box.Top;i>=0;i--){
        Pop(&Box, &shirt);
        if(shirt.size == key){
			break;
        }
        Push(&tempBox, shirt);
    }
    if(i<=Box.Top){
        printf("Not Found the size %c\n", key);
    }else{
		printf("Found the size %c\n", key);
	}
//5
    printf("Items in the box\n");
    TraverseStack(Box);
    printf("Items out of the box\n");
    TraverseStack(tempBox);
//6
    while(!EmptyStack(tempBox)){
            Pop(&tempBox, &shirt);
            Push(&Box, shirt);
        }
/*
    if(i<=Box.Top){
        while(!EmptyStack(tempBox)){
            Pop(&tempBox, &shirt);
            Push(&Box, shirt);
        }
    }else{
        while(!EmptyStack(tempBox)){
            Pop(&tempBox, &shirt);
            Push(&Box, shirt);
        }
    }
*/
//7
    printf("Items in the box\n");
    TraverseStack(Box);
    printf("Items out of the box");
    TraverseStack(tempBox);
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
    printf("plithos sto stack %d",Stack.Top+1);
    for (i=0;i<=Stack.Top;i++) {
        printf("\n%c, %d",Stack.Element[i].size,Stack.Element[i].price);
    }
    printf("\n");
}
