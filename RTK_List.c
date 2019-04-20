#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "RTK_List.h"

rtklist* rtklist_init()
{
    rtklist* list = malloc(sizeof(rtklist));

    NullErrorCheck(list, NULL);

    list->currentElement = 0;
    list->maxElements = INCREMENT;

    list->data = malloc(sizeof(void*) * list->maxElements);

    if(list->data == NULL)
    {
        free(list);
        return NULL;
    }

    return list;
}

void rtklist_free(rtklist* list)
{
    NullErrorCheck(list,);

    for(int i = 0;i < list->currentElement;i++)
    {
        free(list->data[i]);
    }
    
    free(list->data);
    free(list);
}

int rtklist_append(rtklist* list, void* item)
{
    if(list->currentElement == list->maxElements)
    {
        unsigned int newSize = list->maxElements + INCREMENT;

        list->data = realloc(list->data, sizeof(void*) * newSize);   
        NullErrorCheck(list->data, RTK_ERROR);

        list->maxElements = newSize;
    }

    list->data[list->currentElement] = malloc(sizeof(*item));

    memcpy(list->data[list->currentElement], item, sizeof(void*));

    NullErrorCheck(list->data[list->currentElement], RTK_ERROR);

    list->currentElement++;

    return list->currentElement - 1;
}

/* TODO */
int rtklist_pop(rtklist* list, void** pop)
{
    int index = list->currentElement - 1;

    memcpy(*pop, list->data[index], sizeof(void*));

    return rtklist_remove(list, index);
}

/* TODO: Fix memory leak */
int rtklist_remove(rtklist* list, int index)
{
    if(index >= list->currentElement)
    {
        return RTK_ERROR;
    }

    memmove(list->data + index, list->data + index + 1, sizeof(void*) * 
        (list->maxElements - index));

    list->currentElement--;

    return 0;
}

void* rtklist_get(rtklist* list, int index)
{
    if(list == NULL || index >= list->currentElement)
    {
        return NULL;
    }

    return list->data[index];
}


int _rtklist_find(rtklist* list, void* item)
{

    return 1;
}
