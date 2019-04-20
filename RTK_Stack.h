#ifndef RTK_Stack_h_
#define RTK_Stack_h_

struct RTK_Stack
{
    void** data;
    unsigned int maxSize;
    unsigned int currentSize;
};
typedef RTK_Stack rtkstack;

rtkstack* rtkstack_init(int);
void rtkstack_free(rtkstack*);
int rtkstack_push(rtkstack*, void*);
int rtkstack_pop(rtkstack*);
void* rtkstack_get(rtkstack*);

#endif
