#include "rtk_array.h"

#include <stdlib.h>

struct rtkarray* rtkListMalloc(int numElements)
{
    struct rtkarray* array = malloc(sizeof(struct rtkarray));
    array->maxElements = numElements;
    array->data = malloc(sizeof(int) * numElements);

    return array;
}

void rtkFreeArray(struct rtkarray* array)
{
    free(array->data);
    free(array);
}

void rtkArraySet(struct rtkarray* array, int index, int data)
{
    array->data[index] = data;
}

int rtkArrayGet(struct rtkarray* array, int index)
{
    return array->data[index];
}
