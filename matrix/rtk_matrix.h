#pragma once

struct matrix
{
    int** data;
    int rows;
    int cols;
};
typedef struct matrix rtkmatrix;

rtkmatrix*  rtkmatrixAlloc(void* data, int size);
void        rtkmatrixFree();

int         rtkmatrixGet(int row, int col);
int**       rtkmatrixGetArray();
