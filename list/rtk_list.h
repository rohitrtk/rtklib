#ifndef RTK_LIST_H
#define RTK_LIST_H

#include "../rtklib.h"

extern int rtklist_increment;

struct rtklist
{
    int currSize;
    int currMul;
    int* data;

    void    (*append)   (struct rtklist* this, int data);
    int     (*get)      (struct rtklist* this, int index);
    int     (*pop)      (struct rtklist* this, int index);
    int     (*size)     (struct rtklist* this);
};
typedef struct rtklist rtklist;

rtklist*    rtkMallocList();
void        rtkFreeList(rtklist* list);
void        _rtkListAppend(rtklist* list, int data);
int         _rtkListGetValueAt(rtklist* list, int index);
int         _rtkListPop(rtklist* list, int index);
int         _rtkListGetCurrentSize(rtklist* list);
int         _rtkListGetMaxSize(rtklist* list);

#endif