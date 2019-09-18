#include "rtk_list.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int rtklist_increment = 10;

struct rtklist* rtkMallocList()
{
    struct rtklist* list = malloc(sizeof(struct rtklist));
    list->currMul = 1;
    list->currSize = 0;
    
    list->data = malloc(sizeof(int) * list->currMul * rtklist_increment);

    return list;
}

void rtkFreeList(struct rtklist* list)
{
    free(list->data);
    free(list);
}

void rtkListAppend(struct rtklist* list, int data)
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

int rtkListGetValueAt(struct rtklist* list, int index)
{
    if(index >= list->currSize)
    {
        index = --list->currSize; 
    }

    return list->data[index];
}

int rtkListPop(struct rtklist* list, int index)
{
    int value = list->data[index];

    memmove(list->data + index, list->data + index + 1, 
        sizeof(int) * (rtklist_increment * list->currMul - list->currSize));

    return value;    
}

int rtkListGetCurrentSize(struct rtklist* list)
{
    return list->currSize;
}

int rtkListMaxSize(struct rtklist* list)
{
    return list->currMul * rtklist_increment;
}
