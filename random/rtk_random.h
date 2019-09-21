#ifndef RTK_RANDOM_H
#define RTK_RANDOM_H

#include <stdlib.h>

static inline int rtkrandom(int min, int max)
{
    return rand() % (min + max) + min;
}

#endif