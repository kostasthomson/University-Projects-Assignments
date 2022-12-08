// FILENAME StFloatADT.h
                    //* YLOPOIHSH STOIBAS ME PINAKA *
              //*TA STOIXEIA THS STOIBAS EINAI TYPOY float*

#define StackLimit 80

typedef float StackElementType;

typedef struct  {
    int Top;
    StackElementType Element[StackLimit];
} StackType;

typedef enum {
    FALSE, TRUE
} boolean;

void CreateStack(StackType *Stack);
boolean EmptyStack(StackType Stack);
boolean FullStack(StackType Stack);
void Push(StackType *Stack, StackElementType Item);
void Pop(StackType *Stack, StackElementType *Item);

