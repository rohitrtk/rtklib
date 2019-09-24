#ifndef RTK_STRING_H
#define RTK_STRING_H

#include <stdlib.h>

struct rtkstring
{
    char* data;
    unsigned int length;

    void            (*setString)    (struct rtkstring* string, const char* str);
    const char*     (*getString)    (struct rtkstring* string);
    const size_t    (*getLength)    (struct rtkstring* string);
};

typedef struct rtkstring rtkstring;

rtkstring*      rtkMallocString();
void            rtkFreeString(rtkstring* string);
void            _rtkStringSetString(rtkstring* string, const char* str);
const char*     _rtkStringGetString(rtkstring* string);
const size_t    _rtkStringGetLength(rtkstring* string);


#endif