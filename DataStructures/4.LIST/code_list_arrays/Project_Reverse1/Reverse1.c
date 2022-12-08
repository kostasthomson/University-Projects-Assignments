// Filename Reverse1
/*           ΑΝΤΙΣΤΡΟΦΗ ΤΩΝ ΧΑΡΑΚΤΗΡΩΝ ΚΕΙΜΕΝΟΥ ΜΕ ΧΡΗΣΗ ΣΥΜΔΕΔΕΜΕΝΗΣ ΛΙΣΤΑΣ
                   ΥΛΟΠΟΙΗΣΗ ΣΥΝΔΕΔΕΜΈΝΗΣ ΛΊΣΤΑΣ ΜΕ ΠΙΝΑΚΑ
*/

#include <stdio.h>
#include "L_ListChADT.h"

#define  EndMark '$'

int main()
{
  ListPointer AList;
    NodeType Node[NumberOfNodes];
    ListPointer FreePtr,PredPtr;

    ListElementType AnItem;


  InitializeStoragePool(Node, &FreePtr);
  CreateList(&AList);
  PredPtr=NilValue;
  printf("PLHKTROLOGHSE $ STO TELOS TOY KEIMENOY.\n");
  AnItem=getchar();
  while (AnItem!=EndMark)
  {
      Insert(&AList, Node,&FreePtr, PredPtr, AnItem);
      AnItem=getchar();
  }
// H MONH ALLAGH STO L_ListChADT.c EINAI STHN TraverseLinked STHN printf %c SE SXESH ME THN L_ListADT.c !!!
  printf("TO ANASTROFO KEIMENO EINAI \n");
  TraverseLinked(AList,Node);
  printf("\n");
  system("PAUSE");
  return 0;
}
