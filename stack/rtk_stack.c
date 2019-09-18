#include "rtk_stack.h"

rtkstack* rtkMallocStack()
{
    rtkstack* stack = malloc(sizeof(rtkstack));

    stack->currSize = 0;
    stack->list = rtkMallocList();

    return stack;
}

void rtkFreeStack(rtkstack* stack)
{
    rtkFreeList(stack->list);
    free(stack);
}

void _rtkStackPush(rtkstack* stack, int item)
{

}

int _rtkStackPop(rtkstack* stack)
{

}

int _rtkStackSize(rtkstack* stack)
{

}
