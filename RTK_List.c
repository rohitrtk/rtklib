#include <stdlib.h>
#include <stdio.h>
#include "RTK_List.h"

int rtklist_init(rtklist** list)
{
    *list = malloc(sizeof(rtklist));
    NullErrorCheck(*list);

    (*list)->currentElement = 0;
    (*list)->maxElements = INCREMENT;

    (*list)->data = malloc(sizeof(void*) * (*list)->maxElements);
    NullErrorCheck((*list)->data);

    return 0;
}

void rtklist_free(rtklist** list)
{
    free((*list)->data);
    free(*list);
}

int rtklist_append(rtklist** list, void* item)
{
    rtklist* dlist = *list;

    if(dlist->currentElement == dlist->maxElements)
    {
        unsigned int newSize = dlist->maxElements + INCREMENT;

        dlist->data = realloc(dlist->data, sizeof(void*) * newSize);   
        NullErrorCheck(dlist->data);

        dlist->maxElements = newSize;
    }

    void* itemCopy = item;

    dlist->data[dlist->currentElement] = itemCopy;

    dlist->currentElement++;

    return 0;
}
