// FILENAME StChADT.h
                    /* ΥΛΟΠΟΙΗΣΗ ΣΤΟΙΒΑΣ ΜΕ ΠΙΝΑΚΑ */
              /* ΤΑ ΣΤΟΙΧΕΙΑ ΤΗΣ ΣΤΟΙΒΑΣ ΕΙΝΑΙ ΤΥΠΟΥchar */

#define StackLimit 80  // το όριο μεγέθους της στοίβας, ενδεικτικά ίσο με 80

typedef char StackElementType;  // ο τύπος των στοιχείων  της στοίβας
                                //ενδεικτικά τύπος char

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

