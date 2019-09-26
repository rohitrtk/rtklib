#include "rtk_string.h"

rtkstring* rtkMallocString()
{
    rtkstring* string = malloc(sizeof(rtkstring));

    string->data = NULL;
    string->length = 0;

    string->setString = _rtkStringSetString;
    string->getString = _rtkStringGetString;
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
    size_t len = rtkStringLen(data);
    
    string->length = len;

    if(string->data != NULL)    string->data = realloc(string->data, len);
    else                        string->data = malloc(len);
    
    rtkStringCpy(string->data, data, len);

    if(string->data[len - 1] != '\0') string->data[len - 1] = '\0';
}

const char* _rtkStringGetString(rtkstring* string)
{
    return string->data;
}

const size_t _rtkStringGetLength(rtkstring* string)
{
    return string->length;
}

const size_t rtkStringLen(const char* string)
{
    size_t len = 0;

    do
    {
        ++len;
    } 
    while(string[len] != '\0');

    return len;
}

void rtkStringCpy(char* dest, const char* src, size_t len)
{
    for(size_t i = 0; i < len; ++i)
    {
        dest[i] = src[i];
    }
}
