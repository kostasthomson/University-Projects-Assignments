//filename : HeapADT.h

#define  MaxElements 10          //το μέγιστο πλήθος των στοιχείων του σωρού

typedef int  HeapElementType;    //ο τύπος δεδομένων των στοιχείων του σωρού
typedef  struct { 
     HeapElementType key;
    // int Data;                // οποισδήποτε τύπος για τα παρελκόμενα δεδομένα κάθε κόμβου
} HeapNode;


typedef struct {
        int Size;
        HeapNode Element[MaxElements+1];
} HeapType;

typedef enum {
    FALSE, TRUE
} boolean;

void CreateMaxHeap(HeapType *Heap);
boolean FullHeap(HeapType Heap);
void InsertMaxHeap(HeapType *Heap, HeapNode Item);
boolean EmptyHeap(HeapType Heap);
void DeleteMaxHeap(HeapType *Heap, HeapNode *Item);
