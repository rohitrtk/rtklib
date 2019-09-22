#ifndef RTK_RANDOM_H
#define RTK_RANDOM_H

#include <stdlib.h>
#include <time.h>

static int _run = 0;

static inline int rtkrandom(int min, int max)
{
    if(_run == 0)
    {
        srand((unsigned int)time(NULL));
        _run++;
    }

    return rand() % (min + max) + min;
}

#endif