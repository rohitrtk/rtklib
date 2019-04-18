#include <stdlib.h>
#include <stdio.h>
#include "RTK_List.h"

int rtklist_init(rtklist* list)
{
    list = malloc(sizeof(rtklist));

    list->currentElement = 0;
    list->maxElements = INCREMENT;

    list->data = malloc(sizeof(void*) * list->maxElements);

    return 0;
}

void rtklist_free(rtklist* list)
{
    printf("In Free\n");

}

int rtklist_append(rtklist* list, void* item)
{
    if(list->currentElement == list->maxElements)
    {
        list = realloc(list, sizeof(void*) * (list->maxElements + INCREMENT));
        if(list == NULL)
        {
            return ARRAY_ERROR;
        }
    }

    list->data[list->currentElement] = item;
    list->currentElement++;

    return 0;
}
