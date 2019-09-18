#include "rtk_matrix.h"

#include <stdlib.h>

rtkmatrix* rtkmatrixAlloc(int** data, int size)
{
    rtkmatrix* matrix   = malloc(sizeof(rtkmatrix));
    matrix->data        = malloc(size);
    

    return matrix;
}