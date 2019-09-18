#include "rtk_list.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int rtklist_increment = 10;

rtklist* rtkMallocList()
{
    rtklist* list   = malloc(sizeof(rtklist));
    list->currMul   = 1;
    list->currSize  = 0;
    
    list->data      = malloc(sizeof(int) * list->currMul * rtklist_increment);

    list->append    = _rtkListAppend;
    list->get       = _rtkListGetCurrentSize;
    list->pop       = _rtkListPop;
    list->size      = _rtkListGetCurrentSize;
    
    return list;
}

void rtkFreeList(rtklist* list)
{
    free(list->data);
    free(list);
}

void _rtkListAppend(rtklist* list, int data)
{
    if(list->currSize == list->currMul * rtklist_increment)
    {
        LOG("Resizing list!\n");

        ++list->currMul;
        list->data = realloc(list->data, sizeof(int) * list->currMul * rtklist_increment);
    }

    list->data[list->currSize] = data;

    ++list->currSize;
}

int _rtkListGetValueAt(rtklist* list, int index)
{
    if(index >= list->currSize)
    {
        index = --list->currSize; 
    }

    return list->data[index];
}

int _rtkListPop(rtklist* list, int index)
{
    int value = list->data[index];

    memmove(list->data + index, list->data + index + 1, 
        sizeof(int) * (rtklist_increment * list->currMul - list->currSize));

    return value;    
}

int _rtkListGetCurrentSize(rtklist* list)
{
    return list->currSize;
}

int _rtkListMaxSize(rtklist* list)
{
    return list->currMul * rtklist_increment;
}
