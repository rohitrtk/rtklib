#include "rtk_sort.h"

void _swap(int* val_x, int* val_y)
{
    int temp = *val_x;
    *val_x = *val_y;
    *val_y = temp;
}

void rtkBubbleSort(int* array, size_t length)
{
    for(size_t i = 0; i < length - 1; ++i)
    {
        for(size_t j = 0; j < length - 1 - i; ++j)
        {
            if(array[j] > array[j+1])
            {
                _swap(&array[j], &array[j+1]);
            }
        }
    }
}
