#include "rtk_array.h"

#include <stdlib.h>

rtkarray* rtkMallocArray(int numElements)
{
    rtkarray* array = malloc(sizeof(rtkarray));
    array->maxElements = numElements;
    array->data = malloc(sizeof(int) * numElements);

    array->get = _rtkArrayGet;
    array->set = _rtkArraySet;
    array->size = _rtkArraySize;

    return array;
}

void rtkFreeArray(rtkarray* array)
{
    free(array->data);
    free(array);
}

void _rtkArraySet(rtkarray* array, int index, int data)
{
    array->data[index] = data;
}

int _rtkArrayGet(rtkarray* array, int index)
{
    return array->data[index];
}

int _rtkArraySize(rtkarray* array)
{
    return array->maxElements;
}
