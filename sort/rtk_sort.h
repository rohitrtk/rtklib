#ifndef RTK_SORT_H
#define RTK_SORT_H

#include <stdlib.h>

void _swap(int* val_x, int* val_y);

void rtkBubbleSort(int* array, const size_t length);
void rtkInsertionSort(int* array, const size_t length);
void rtkSelectionSort(int* array, const size_t length);
void rtkMergeSort(int* array, const size_t length);
void rtkQuickSort(int* array, const size_t length);

#endif