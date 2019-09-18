#include "../rtklib.h"

#ifndef RTK_LIST_H
#define RTK_LIST_H

extern int rtklist_increment;

struct rtklist
{
    int currSize;
    int currMul;
    int* data;
};
typedef struct rtklist rtklist;

rtklist*    rtkMallocList();
void        rtkFreeList(rtklist* list);
void        rtkListAppend(rtklist* list, int data);
int         rtkListGetValueAt(rtklist* list, int index);
int         rtkListPop(rtklist* list, int index);
int         rtkListGetCurrentSize(rtklist* list);
int         rtkListGetMaxSize(rtklist* list);

#endif