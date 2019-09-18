#include "RTK_String.h"
#include <stdlib.h>

rtkstring* rtkstring_init(char* string)
{
    rtkstring* str = malloc(sizeof(rtkstring));


    str->string = string;
    return str;
}



int rtkstrlen(char* string)
{
    int i = 0;
    while(string[i] != '\0')
    {
        ++i;
    }

    return i;
}