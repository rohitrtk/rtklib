#ifndef RTK_STACK_H
#define RTK_STACK_H

#include "list/rtk_list.h"

struct rtkstack
{
    int currSize;
    rtklist* list;
};
typedef struct rtkstack rtkstack;

rtkstack*   rtkMallocStack();
void        rtkFreeStack(rtkstack* stack);
void        _rtkStackPush(rtkstack* stack, int item);
int         _rtkStackPop(rtkstack* stack);
int         _rtkStackSize(rtkstack* stack);


#endif
