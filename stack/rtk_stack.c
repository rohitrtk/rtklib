#include "rtk_stack.h"

#include <stdlib.h>

rtkstack* rtkMallocStack()
{
    rtkstack* stack = malloc(sizeof(rtkstack));

    stack->currSize = 0;
    stack->list = rtkMallocList();

    stack->push = _rtkStackPush;
    stack->pop  = _rtkStackPop;
    stack->size = _rtkStackSize;
    stack->dataAt = _rtkStackDataAt;

    return stack;
}

void rtkFreeStack(rtkstack* stack)
{
    rtkFreeList(stack->list);
    free(stack);
}

void _rtkStackPush(rtkstack* stack, int item)
{
    stack->list->append(stack->list, item);
}

int _rtkStackPop(rtkstack* stack)
{
    return stack->list->pop(stack->list);
}

int _rtkStackSize(rtkstack* stack)
{
    return stack->list->size(stack->list);
}

int _rtkStackDataAt(rtkstack* stack, int index)
{
    return stack->list->get(stack->list, index);
}
