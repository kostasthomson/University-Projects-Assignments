#include <stdio.h>
#include <stdlib.h>

#define StackLimit 20
#define NumberOfNodes 10
#define NilValue -1          // ειδική μεδενικη τιμη δείχνει το τέλος της Συνδ.λίστας

/*---------------STACK-----------------*/
typedef int StackElementType;   

typedef struct  {
    int Top;
    StackElementType Element[StackLimit];
} StackType;

/*---------------LIST-----------------*/
typedef struct{
    int am;
    float grade;
} ListElementType;

typedef int ListPointer;

typedef struct {
    ListElementType Data;
    ListPointer  Next;
} NodeType;

typedef enum {
    FALSE, TRUE
} boolean;

/*---------------STACK-----------------*/
void CreateStack(StackType *Stack);
boolean EmptyStack(StackType Stack);
boolean FullStack(StackType Stack);
void Push(StackType *Stack, StackElementType Item);
void Pop(StackType *Stack, StackElementType *Item);
void TraverseStack(StackType Stack);

/*---------------LIST-----------------*/
void InitializeStoragePool(NodeType Node[], ListPointer *FreePtr);
void CreateList(ListPointer *List);
boolean EmptyList(ListPointer List);
boolean FullList(ListPointer FreePtr);
void GetNode(ListPointer *P, ListPointer *FreePtr, NodeType Node[]);
void ReleaseNode(NodeType Node[NumberOfNodes], ListPointer P, ListPointer *FreePtr);
void Insert(ListPointer *List, NodeType Node[],ListPointer *FreePtr, ListPointer PredPtr, ListElementType Item);
void Delete(ListPointer *List, NodeType Node[], ListPointer *FreePtr, ListPointer PredPtr);
void TraverseLinked(ListPointer List, NodeType Node[]);
void printAll(ListPointer List, ListPointer FreePtr, NodeType Node[]);

float FindMins(ListPointer List, NodeType Node[NumberOfNodes], StackType *Stack);

int main()
{
    NodeType Node[NumberOfNodes];
    ListPointer List, freeptr, predptr;
    ListElementType element;
    StackType Stack;
    StackElementType am;
    float lowest;
    int i;

//A
    InitializeStoragePool(Node, &freeptr);
//B
    CreateList(&List);
//C
    printf("---------------Question C--------------------\n");
    printAll(List, freeptr, Node);
//D
    printf("---------------Question D--------------------\n");
    TraverseLinked(List, Node);
//E
    printf("---------------Question E--------------------\n");
    predptr = NilValue;
    for(i=0;i<5;i++)
    {
        printf("DWSE AM GIA EISAGWGH STH LISTA: ");
        scanf("%d", &element.am);
        printf("DWSE VATHMO GIA EISAGWGH STH LISTA: ");
        scanf("%f", &element.grade);
        Insert(&List, Node, &freeptr, predptr, element);
    }
//F
    printf("---------------Question F--------------------\n");
    printAll(List, freeptr, Node);
//G
    printf("---------------Question G--------------------\n");
    TraverseLinked(List, Node);
//H
    printf("---------------Question H--------------------\n");
    if(!EmptyList(List))
    {
        printf("Not an Empty List\n");
    }
    else
    {
        printf("Empty List\n");
    }
//I
    printf("---------------Question I--------------------\n");
    if(!FullList(List))
    {
        printf("Not a Full List\n");
    }
    else
    {
        printf("Full List\n");
    }
//J
    printf("---------------Question J--------------------\n");
    lowest = FindMins(List, Node, &Stack);
    printf("Min value=%.1f\n", lowest);
    printf("AM with min grade are: ");
    while (!EmptyStack(Stack))
    {
        Pop(&Stack, &am);
        printf("%d ", am);
    }
    printf("\n");
//K
    printf("---------------Question K--------------------\n");
    TraverseStack(Stack);
//L
    printf("---------------Question L--------------------\n");
    printAll(List, freeptr, Node);
//M
    printf("---------------Question M--------------------\n");
    TraverseLinked(List, Node);
    return 0;
}

float FindMins(ListPointer List, NodeType Node[NumberOfNodes], StackType *Stack)
{
    ListPointer curr;
    StackElementType item;
    float min;

    CreateStack(Stack);

    if(!EmptyList(List))
    {
        curr = List;
        min = Node[curr].Data.grade;
        
        while(curr != NilValue)
        {
            if(Node[curr].Data.grade<=min)
            {
                if(Node[curr].Data.grade<min)
                {
                    while(!EmptyStack(*Stack))
                    {
                        Pop(Stack, &item);
                    }
                    min = Node[curr].Data.grade;
                }
                Push(Stack, Node[curr].Data.am);
            }
            curr = Node[curr].Next;
        }
    }
    else
    {
        printf("Empty List... \n");
    }
    return min;
}

/*-=-=-=-=-=-=-=-=-=-=-=-=STACK-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=*/


void CreateStack(StackType *Stack) 
{
    Stack -> Top = -1;
   // (*Stack).Top = -1;
}

boolean EmptyStack(StackType Stack) 
{
    return (Stack.Top == -1);
}

boolean FullStack(StackType Stack) 
{
    return (Stack.Top == (StackLimit - 1));
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
    printf("\nplithos sto stack %d\n",Stack.Top+1);
    for (i=Stack.Top;i>=0;i--) {
        printf("%d ",Stack.Element[i]);
    }
    printf("\n");
}


/*-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=LIST-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=*/



void InitializeStoragePool(NodeType Node[], ListPointer *FreePtr)
{
   int i;

    for (i=0; i<NumberOfNodes-1;i++)
    {
        Node[i].Next=i+1;
        Node[i].Data.am=-1;
        Node[i].Data.grade = -1.0;
    }
    Node[NumberOfNodes-1].Next=NilValue;
    Node[NumberOfNodes-1].Data.am=-1;
    Node[NumberOfNodes-1].Data.grade=-1.0;
    *FreePtr=0;
}

void CreateList(ListPointer *List)
{
  *List=NilValue;
}

boolean EmptyList(ListPointer List)
{
  return (List==NilValue);
}

boolean FullList(ListPointer FreePtr)
{
  return (FreePtr == NilValue);
}

void GetNode(ListPointer *P, ListPointer *FreePtr, NodeType Node[])
{
  *P = *FreePtr;
  if (!FullList(*FreePtr))
    *FreePtr =Node[*FreePtr].Next;
}

void ReleaseNode(NodeType Node[], ListPointer P, ListPointer *FreePtr)
{
  Node[P].Next =*FreePtr;
  Node[P].Data.am = -1;
  Node[P].Data.grade = -1.0;
  *FreePtr =P;
}

void Insert(ListPointer *List, NodeType Node[],ListPointer *FreePtr, ListPointer PredPtr, ListElementType Item)
{
  ListPointer TempPtr;
  GetNode(&TempPtr,FreePtr,Node);
  if (!FullList(TempPtr)) {
    if (PredPtr==NilValue)
    {
        Node[TempPtr].Data.am = Item.am;
        Node[TempPtr].Data.grade = Item.grade;
        Node[TempPtr].Next =*List;
        *List =TempPtr;
    }
    else
      {
        Node[TempPtr].Data.am = Item.am;
        Node[TempPtr].Data.grade = Item.grade;
        Node[TempPtr].Next =Node[PredPtr].Next;
        Node[PredPtr].Next =TempPtr;
      }
}
  else
    printf("Full List ...\n");
}

void Delete(ListPointer *List, NodeType Node[], ListPointer *FreePtr, ListPointer PredPtr)
{
  ListPointer TempPtr ;

  if (!EmptyList(*List))
    if (PredPtr == NilValue)
    {
        TempPtr =*List;
        *List =Node[TempPtr].Next;
        ReleaseNode(Node,TempPtr,FreePtr);
    }
    else
      {
        TempPtr =Node[PredPtr].Next;
        Node[PredPtr].Next =Node[TempPtr].Next;
        ReleaseNode(Node,TempPtr,FreePtr);
      }
  else
    printf("Empty List ...\n");
}

void TraverseLinked(ListPointer List, NodeType Node[])
{
    ListPointer CurrPtr;

    printf("--------------Linked list--------------------\n");

    if (!EmptyList(List))
    {
        CurrPtr =List;
        while (CurrPtr != NilValue)
        {
            printf("(%d:<%d,%.1f> ->%d) ",CurrPtr,Node[CurrPtr].Data.am, Node[CurrPtr].Data.grade, Node[CurrPtr].Next);
            CurrPtr=Node[CurrPtr].Next;
        }
        printf("\n");
    }
    else printf("Empty List ...\n");
}


void printAll(ListPointer List, ListPointer FreePtr, NodeType Node[])
{
    int i;
    printf("1o STOIXEIO LISTAS=%d, 1H FREE POSITION=%d\n", List, FreePtr);
    printf("H STORAGE POOL EXEI TA EJHS STOIXEIA\n");
    for (i=0;i<NumberOfNodes;i++)
        printf("(%d:<%d,%.1f> ->%d) ", i, Node[i].Data.am, Node[i].Data.grade, Node[i].Next);
    printf("\n");
}