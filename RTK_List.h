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

/* Finds item in list. Returns 0 if item is in the
 * list, returns 1 if item wasn't found and returns
 * -1 if there was an error.
 */
int _rtklist_find(rtklist*, void*);

#define rtklist_find(list, item, item_type) _rtklist_find(list, (item_type*)item)

#endif
