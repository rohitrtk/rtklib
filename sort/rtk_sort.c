#include "rtk_sort.h"

#include <string.h>

void sort(int* array, const size_t length, unsigned int sortType)
{
    switch(sortType)
    {
    case BUBBLE_SORT:
        rtkBubbleSort(array, length);
        break;
    case INSERTION_SORT:
        rtkInsertionSort(array, length);
        break;
    case SELECTION_SORT:
        rtkSelectionSort(array, length);
        break;
    case MERGE_SORT:
        rtkMergeSort(array, length);
        break;
    case QUICK_SORT:
        rtkQuickSort(array, length);
        break;
    default:
        rtkBubbleSort(array, length);
        break;
    }
}

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
        int k = 0;
        while(j >= 0 && array[i - k] < array[j])
        {
            _swap(&array[j], &array[i - k]);
            --j;
            ++k;
        }
    }
}

void rtkSelectionSort(int* array, const size_t length)
{
    int* currentMin;
    for(int i = 0; i < length; ++i)
    {
        currentMin = &array[i];

        for(int j = i; j < length; ++j)
        {
            if(array[j] < *currentMin)
            {
                currentMin = &array[j];
            }
        }

        _swap(&array[i], currentMin);
    }
}

void rtkMergeSort(int* array, const size_t length) 
{
    int middle = length / 2;

    // Merge Left
    rtkMergeSort(array, middle);

    // Merge Right
    rtkMergeSort(array + middle, middle + 1);

    // Merge
    
}

void _merge(int* array, int left, int middle, int right)
{

}

void rtkQuickSort(int* array, const size_t length) {}