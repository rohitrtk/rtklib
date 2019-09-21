#include "list/rtk_list.h"
#include "array/rtk_array.h"
#include "stack/rtk_stack.h"
#include "random/rtk_random.h"
#include "sort/rtk_sort.h"

#include <stdio.h>

#define LAZYFOR(loopNum, block) for(int i = 0; i < loopNum; ++i) { block; }

void testList()
{
    rtklist* list = rtkMallocList();

    for(int i = 0; i < 12; i++)
    {
        list->append(list, i * 4);
    }
    
    for(int i = 0; i < 12; i++)
    {
        printf("Index %d: %d\n" , i, list->get(list, i));
    }

    printf("Pop index %d and got %d\n", 3, list->remove(list, 3));
    printf("Pop index %d and got %d\n", 3, list->remove(list, 3));
    printf("Pop index %d and got %d\n", 3, list->remove(list, 3));
    
    for(int i = 0; i < 12; i++)
    {
        printf("Index %d: %d\n" , i, list->get(list, i));
    }

    rtkFreeList(list);
}

void testArray()
{
    rtkarray* array = rtkMallocArray(10);

    for(int i = 0; i < array->size(array); ++i)
    {
        array->set(array, i, i * 4);
    }

    for(int i = 0; i < array->size(array); ++i)
    {
        printf("%d\n", array->get(array, i));
    }

    rtkFreeArray(array);
}

void testStack()   
{
    rtkstack* stack = rtkMallocStack();

    for(int i = 0; i < 5; ++i)
    {
        stack->push(stack, i);
    }

    printf("Size of stack is:%d\n", stack->size(stack));
    printf("Popped:%d\n", stack->pop(stack));
    printf("Popped:%d\n", stack->pop(stack));
    printf("Size of stack is:%d\n", stack->size(stack));

    for(int i = 0; i < stack->size(stack); ++i)
    {
        printf("Index %d of stack:%d\n", i, stack->dataAt(stack, i));
    }

    rtkFreeStack(stack);
}

int main(int argc, char** argv)
{
    int array[20];
    for(int i = 0; i < 20; ++i)
    {
        array[i] = rtkrandom(1, 20);
    }

    printf("Before sort:");
    for(int i = 0; i < 20; i++)
    {
        printf(" %d", array[i]);
    }
    printf("\n");

    rtkBubbleSort(array, 20);

    printf("After sort:");
    for(int i = 0; i < 20; i++)
    {
        printf(" %d", array[i]);
    }
    printf("\n");
    
    return 0;
}