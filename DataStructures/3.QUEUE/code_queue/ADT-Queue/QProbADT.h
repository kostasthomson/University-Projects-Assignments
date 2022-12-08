/*******************************************************************************
* Filename: QProbADT.h
******************************************************************************/

/* Queue */
#define QueueLimit 20  //το όριο μεγέθους της ουράς

typedef struct {
    int Addend1, Addend2;    
} QueueElementType;   /* ο τύπος δεδομένων των στοιχείων της ουράς
                         τύπος struct (δομή) */

typedef struct {
	int Front, Rear;
	QueueElementType Element[QueueLimit];;
} QueueType;

typedef enum {FALSE, TRUE} boolean;

void CreateQ(QueueType *Queue);
boolean EmptyQ(QueueType Queue);
boolean FullQ(QueueType Queue);
void RemoveQ(QueueType *Queue, QueueElementType *Item);
void AddQ(QueueType *Queue, QueueElementType Item);
