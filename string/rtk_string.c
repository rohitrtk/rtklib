#include "rtk_string.h"

rtkstring* rtkMallocString()
{
    rtkstring* string = malloc(sizeof(rtkstring));

    string->data = NULL;
    string->length = 0;

    string->setString = _rtkStringSetString;
    string->getLength = _rtkStringGetLength;

    return string;
}

void rtkFreeString(rtkstring* string)
{
    if(string->data)
    {
        free(string->data);
    }

    free(string);
}

void _rtkStringSetString(rtkstring* string, const char* data)
{
    size_t len = 0;

    while(string->data[len] != '\0')
    {
        ++len;
    }
    
    if(string->data)
    {
        string->data = realloc(string->data, len);
    }
    else
    {
        string->data = malloc(len);
    }
    
    for(size_t i = 0; i < len; ++i)
    {
        string->data[i] = data[i];
    }
}

const char* _rtkStringGetString(rtkstring* string)
{
    return string->data;
}

const size_t _rtkStringGetLength(rtkstring* string)
{
    return string->length;
}