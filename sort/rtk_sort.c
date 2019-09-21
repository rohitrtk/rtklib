#include "rtk_sort.h"

#include <string.h>

void _swap(int* val_x, int* val_y)
{
    int temp = *val_x;
    *val_x = *val_y;
    *val_y = temp;
}

void rtkBubbleSort(int* array, const size_t length)
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

void rtkInsertionSort(int* array, const size_t length)
{
    for(int i = 1; i < length; ++i)
    {
        int j = i - 1;

        while(j >= 0 && array[i] < array[j])
        {
            array[j+1] = array[j];
            j -= 1;
        }

        array[j+1] = array[i];
    }
}
