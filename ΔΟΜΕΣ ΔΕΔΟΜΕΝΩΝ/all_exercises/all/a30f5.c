#include <stdio.h>

#define  MaxElements 10

typedef float  HeapElementType;

typedef  struct {
     HeapElementType key;
    // int Data;
} HeapNode;

typedef struct {
        int Size;
        HeapNode Element[MaxElements+1];
} HeapType;

typedef enum {
    FALSE, TRUE
} boolean;

void CreateMinHeap(HeapType *Heap);
boolean FullHeap(HeapType Heap);
void InsertMinHeap(HeapType *Heap, HeapNode Item);
boolean EmptyHeap(HeapType Heap);
void DeleteMinHeap(HeapType *Heap, HeapNode *Item);
void PrintHeap(HeapType Heap);





int main(){
    HeapType AHeap;
    HeapNode AnItem;
    int m;
    FILE *fp;

	CreateMinHeap(&AHeap);
	printf("Give m:");
	scanf("%d", &m);
	fp = fopen("transactions.txt", "r");

    while(!feof(fp)) {
        fscanf(fp, "%f [^\n]", &AnItem.key);
        InsertMinHeap(&AHeap, AnItem);
        if(AHeap.Size>m){
            DeleteMinHeap(&AHeap, &AnItem);
        }
    }

    PrintHeap(AHeap);
    printf("\nTransactions\n");
    while(!EmptyHeap(AHeap)){
        DeleteMinHeap(&AHeap, &AnItem);
        printf("%.2f ", AnItem.key);
    }

    fclose(fp);
	return 0;
}






void CreateMinHeap(HeapType *Heap)
/* ����������: ���������� ��� ���� ����.
   ����������: ��� ���� ����
*/
{
  (*Heap).Size=0;
}

boolean EmptyHeap(HeapType Heap)
/* �������:    ��� ���� Heap.
   ����������: ������� �� � ����� ����� �����.
   ����������: TRUE �� � ����� ����� �����, FALSE �����������
*/
{
  return (Heap.Size==0);
}

boolean FullHeap(HeapType Heap)
/* �������:    ��� ����.
   ����������: ������� �� � ����� ����� �������.
   ����������: TRUE �� � ����� ����� �������, FALSE �����������
*/
{
  return (Heap.Size==MaxElements);
}

void InsertMinHeap(HeapType *Heap, HeapNode Item)
/*  �������:    ��� ���� Heap ��� ��� �������� ��������� Item .
    ����������: ������� �� �������� Item ��� ����, �� � ����� ��� ����� �������.
    ����������: ��� ������������� ����.
    ������:     ������ ������� ����� �� � ����� ����� �������
*/
{
   int hole;

   if (!FullHeap(*Heap))
   {
          (*Heap).Size++;

          hole=(*Heap).Size;
          while (hole>1 && Item.key < Heap->Element[hole/2].key)
          {
            (*Heap).Element[hole]=(*Heap).Element[hole/2];
                      hole=hole/2;
          }
          (*Heap).Element[hole]=Item;
   }
   else
     printf("Full Heap...\n");
}

void DeleteMinHeap(HeapType *Heap, HeapNode *Item)
/* �������:    ��� ���� Heap.
   ����������: ������ ��� ��������� �� ���������� �������� ��� �����.
   ����������: �� ���������� �������� Item ��� ����� ��� ��� ������������� ����
*/
{
   int parent, child;
   HeapNode last;
   boolean done;

   if (!EmptyHeap(*Heap))
   {
        done=FALSE;
        *Item=(*Heap).Element[1];
        last=(*Heap).Element[(*Heap).Size];
        (*Heap).Size--;

        parent=1; child=2;

        while (child<=(*Heap).Size && !done)
        {
            if (child<(*Heap).Size)
                if ((*Heap).Element[child].key > (*Heap).Element[child+1].key)
                    child++;
            if (last.key <= (*Heap).Element[child].key)
                done=TRUE;
            else
            {
               (*Heap).Element[parent]=(*Heap).Element[child];
               parent=child;
               child=2*child;
            }
        }
        (*Heap).Element[parent]=last;
    }
   else
       printf("Empty heap...\n");
}


void PrintHeap(HeapType Heap)
{
    	int i;

	printf("Data Structure Size = %d\n", Heap.Size);
   	 for (i=1; i<=Heap.Size;i++)
     	 	printf("%.2f ",Heap.Element[i].key);
}

