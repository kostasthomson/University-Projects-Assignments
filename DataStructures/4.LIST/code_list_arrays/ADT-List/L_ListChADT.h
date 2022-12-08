// Filename L_ListChADT.h

#include <stdio.h>
#include <stdlib.h>

#define NumberOfNodes 50 /*όριο μεγέθους της συνδεδεμένης λίστας,
                            ενδεικτικά τέθηκε ίσο με 50*/
#define NilValue -1       // ειδική μεδενικη τιμη δείχνει το τέλος της Συνδ.λίστας

typedef char ListElementType; /*τύπος δεδομένων για τα στοιχεία της
                                συνδεδεμένης λίστας char */
typedef int ListPointer;

typedef struct {
    ListElementType Data;
    ListPointer  Next;
} NodeType;


typedef enum {
    FALSE, TRUE
} boolean;


void InitializeStoragePool(NodeType Node[], ListPointer *FreePtr);
void CreateList(ListPointer *List);
boolean EmptyLList(ListPointer List);
boolean FullList(ListPointer List);
void GetNode(ListPointer *P, ListPointer *FreePtr, NodeType Node[]);
void ReleaseNode(NodeType Node[], ListPointer P, ListPointer *FreePtr);
void Insert(ListPointer *List, NodeType Node[],ListPointer *FreePtr, ListPointer PredPtr, ListElementType Item);
void Delete(ListPointer *List, NodeType Node[], ListPointer *FreePtr, ListPointer PredPtr);
void TraverseLinked(ListPointer List, NodeType Node[]);
