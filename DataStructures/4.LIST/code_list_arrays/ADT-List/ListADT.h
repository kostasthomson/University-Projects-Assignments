// Filename ListADT.h
#define ListLimit 50    //όριο μεγέθους της λίστας, ενδεικτικά τέθηκε ίσο με 50

typedef int ListElementType;   /*τύπος δεδομένων για τα στοιχεία της λίστας 
                                    ενδεικτικά επιλέχθηκε ο τύπος int */
typedef struct {
    int Size;
    ListElementType Element[ListLimit];
} ListType;

typedef enum {
    FALSE, TRUE
} boolean;

void CreateList(ListType *List);
boolean EmptyList(ListType List);
boolean FullList(ListType List);
void Insert(ListType *List, ListElementType Item, int Pos);
void Delete(ListType *List, int Pos);
void TraverseList(ListType List);
