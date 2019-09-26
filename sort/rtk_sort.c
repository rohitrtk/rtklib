#include "rtk_sort.h"

#include <string.h>

#include <stdio.h>

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
    if(length < 2)
    {
        return;
    }

    int middle = length / 2;

    size_t lengthLeft = middle;
    size_t lengthRight = length - middle;

    int left[lengthLeft];
    int right[lengthRight];

    for(int i = 0; i < lengthLeft; ++i) 
    {
        left[i] = array[i];
    }

    for(int i = 0; i < lengthRight; ++i)
    {
        right[i] = array[lengthLeft + i];
    }

    rtkMergeSort(left, lengthLeft);
    rtkMergeSort(right, lengthRight);

    _merge(left, right, array, lengthLeft, lengthRight);
}

void _merge(int* left, int* right, int* array, const size_t lengthLeft, const size_t lengthRight)
{
    int i = 0;
    int j = 0;
    int k = 0;

    while(i < lengthLeft && j < lengthRight)
    {
        if(left[i] <= right[i])
        {
            array[k] = left[i];
            ++i;
        }
        else
        {
            array[k] = right[j];
            ++j;
        }
        
        ++k;
    }

    while(i < lengthLeft)
    {
        array[k] = left[i];
        ++i;
        ++k;
    }

    while(j < lengthRight)
    {
        array[k] = right[j];
        ++j;
        ++k;
    }
}

void rtkQuickSort(int* array, const size_t length) {}