#ifndef RTK_List_h_
#define RTK_List_h_

#include <stdlib.h>
#include <string.h>

#define RTK_ERROR 1

#define INCREMENT 10

#define NullErrorCheck(x) if(x == NULL) return RTK_ERROR;

/*
#define rtklist_append(list, item, item_type) {\
    rtklist* dlist = *list;\
    \
    if(dlist->currentElement == dlist->maxElements)\
    {\
        unsigned int newSize = dlist->maxElements + INCREMENT;\
        dlist->data = realloc(dlist->data, sizeof(void*) * newSize);\
        NullErrorCheck(dlist->data);\
        dlist->maxElements = newSize;\
    }\
    \
    dlist->data[dlist->currentElement] = malloc(sizeof(item_type));\
    memcpy(dlist->data[dlist->currentElement], item, sizeof(void*));\
    dlist->currentElement++;\
}*/

struct RTK_List
{
    void** data;
    unsigned int currentElement;
    unsigned int maxElements;
};
typedef struct RTK_List rtklist;

/* Allocates memory for list and internal data */
int rtklist_init(rtklist**);

/* Frees memory allocated by init */
void rtklist_free(rtklist**);

/* Appends an item to the end of the list */
int rtklist_append(rtklist**, void*);

/* Removes an item from the list at index, shifts all items
 * after the index to the index */
int rtklist_remove(rtklist**, int);

/* Pop an item from the end of the list */
void* rtklist_pop(rtklist**, void*);

/* Returns an item in the list at index */
void* rtklist_get(rtklist**, int);

#endif
