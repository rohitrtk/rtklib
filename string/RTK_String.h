struct RTK_String
{
    int length;
    char* string;
};

typedef struct RTK_String rtkstring;

rtkstring* rtkstring_init(char*);
rtkstring* rtkstring_get();
void rtkstring_free(rtkstring* string);

int rtkstrlen(char* string);