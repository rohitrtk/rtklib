#ifndef RTK_List_h_
#define RTK_List_h_

#include <stdlib.h>
#include <string.h>

#define RTK_ERROR -1

#define INCREMENT 10

#define NullErrorCheck(value, ret) if(value == NULL) return ret;

struct RTK_List
{
    void** data;
    unsigned int currentElement;
    unsigned int maxElements;

    int (*rtklist_find)(struct RTK_List*, void*);
};
typedef struct RTK_List rtklist;

/* Allocates memory for a list and returns a pointer
 * to it. Returns NULL if list couldn't be allocated.
 */
rtklist* rtklist_init();

/* Frees the specified list and it's data from memory. */
void rtklist_free(rtklist*);

/* Copies item into allocated memory in the list. Returns
 * the index that the item was appended to.
 */
int rtklist_append(rtklist*, void*);

/* Pop an item from the end of the list. Returns
 * 0 if item was popped successfully or -1 if there
 * was an error.
 */
int rtklist_pop(rtklist*, void**);

/* Removes an item from the list at index, shifts all items
 * after the index to the index. Returns 0 if item at index
 * was successfully removed or -1 if there was an error.
 */
int rtklist_remove(rtklist*, int);

/* Returns data at specified index or NULL if the list is
 * NULL or the index exceeds the lists current index.
 */
void* rtklist_get(rtklist*, int);

/* Returns the size of the array or -1 if the list 
 * is NULL.
 */
int rtklist_size(rtklist*);

/* Returns -1. The user is supposed to define their own
 * find function since the types in the list aren't known.
 */
static inline int _rtklist_find_not_implemented() 
{
    return -1;
}

#endif
