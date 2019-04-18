#include <stdlib.h>
#include <stdio.h>
#include <string.h>
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
    for(int i = 0;i < (*list)->currentElement;i++)
    {
        free((*list)->data[i]);
    }

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

    dlist->data[dlist->currentElement] = malloc(sizeof(*item));

    memcpy(dlist->data[dlist->currentElement], item, sizeof(void*));

    NullErrorCheck(dlist->data[dlist->currentElement]);

    dlist->currentElement++;

    return 0;
}

void* rtklist_pop(rtklist** list, void* pop)
{
    rtklist* dlist = *list;

    if(dlist->currentElement == 0)
    {
        pop = NULL;
        return pop;
    }

    int prev = dlist->currentElement--;
    
    memcpy(pop, dlist->data[prev], sizeof(void*));

    free(dlist->data[prev]);

    dlist->currentElement--;

    return pop;
}

int rtklist_remove(rtklist** list, int index)
{
    return 0;
}

void* rtklist_get(rtklist** list, int index)
{
    rtklist* dlist = *list;

    if(index >= dlist->currentElement)
    {
        return NULL;
    }

    return dlist->data[index];
}
