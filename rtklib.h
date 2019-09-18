#ifndef RTKLIB_H_
#define RTKLIB_H_

#include "list/rtk_list.h"

#define DEBUG 1

#if DEBUG == 1
    #define LOG(x) printf(x);
#else
    #define LOG(x)
#endif

#endif 
