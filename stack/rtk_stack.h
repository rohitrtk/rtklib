#ifndef RTK_STACK_H
#define RTK_STACK_H

#include "../list/rtk_list.h"

struct rtkstack
{
    int currSize;
    rtklist* list;

    void    (*push)     (struct rtkstack* stack, int item);
    int     (*pop)      (struct rtkstack* stack);
    int     (*size)     (struct rtkstack* stack);
    int     (*dataAt)   (struct rtkstack* stack, int index);
};
typedef struct rtkstack rtkstack;

rtkstack*   rtkMallocStack();
void        rtkFreeStack(rtkstack* stack);
void        _rtkStackPush(rtkstack* stack, int item);
int         _rtkStackPop(rtkstack* stack);
int         _rtkStackSize(rtkstack* stack);
int         _rtkStackDataAt(rtkstack* stack, int index);

#endif
