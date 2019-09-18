#include "../rtklib.h"

struct rtkarray
{
    int maxElements;
    int* data;
};
typedef struct rtkarray rtkarray;

struct rtkarray*    rtkMallocArray(int numElements);
void                rtkFreeArray(struct rtkarray* array);
int                 rtkArrayGet(struct rtkarray* array, int index);
void                rtkArraySet(struct rtkarray* array, int index, int data);
