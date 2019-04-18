#ifndef RTK_List_h_
#define RTK_List_h_

#define ARRAY_ERROR 1

#define INCREMENT 10

struct RTK_List
{
    void** data; // Array of void*
    int currentElement;
    int maxElements;
};
typedef struct RTK_List rtklist;

/* Allocates memory for list and internal data */
int rtklist_init(rtklist*);

/* Frees memory allocated by init */
void rtklist_free(rtklist*);

int rtklist_append(rtklist*, void*);
int rtklist_remove(rtklist*, int);
void* rtklist_pop(rtklist*);

#endif
