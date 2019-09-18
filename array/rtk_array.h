#ifndef RTK_ARRAY_H
#define RTK_ARRAY_H_

#include "../rtklib.h"

struct rtkarray
{
    int maxElements;
    int* data;

    int     (*get)  (struct rtkarray* this, int index);
    void    (*set)  (struct rtkarray* this, int index, int data);
    int     (*size) (struct rtkarray* this);
};
typedef struct rtkarray rtkarray;

rtkarray*   rtkMallocArray(int numElements);
void        rtkFreeArray(rtkarray* array);
int         _rtkArrayGet(rtkarray* array, int index);
void        _rtkArraySet(rtkarray* array, int index, int data);
int         _rtkArraySize(rtkarray* array);

#endif
