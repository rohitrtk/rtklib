#ifndef RTK_SORT_H
#define RTK_SORT_H

#include <stdlib.h>

#define BUBBLE_SORT     0
#define INSERTION_SORT  1
#define SELECTION_SORT  2
#define MERGE_SORT      3
#define QUICK_SORT      4

#define _MERGE_MULTIPIER 2

void sort(int* array, const size_t length, unsigned int sortType);

void _swap(int* val_x, int* val_y);
void _merge(int* array1, int left, int middle, int right);

void rtkBubbleSort(int* array, const size_t length);
void rtkInsertionSort(int* array, const size_t length);
void rtkSelectionSort(int* array, const size_t length);
void rtkMergeSort(int* array, const size_t length);
void rtkQuickSort(int* array, const size_t length);

#endif