#ifndef STRUCT_STRING_ARRAY
#define STRUCT_STRING_ARRAY
typedef struct s_string_array
{
    int size;
    char** array;
} string_array;
#endif

#include <stdio.h>
#include <string.h>

//putted to mystrtok
char * mystrchr(const char * s, const char c) {
    while ( *s && *s != c )
        ++s;
    return ( *s ) ? (char*) s : NULL;
}
//function strtok is prohibited according to the task 
char * mystrtok(char * str, const char * delim) {
    static char * next;
    
    if ( str ) {
        next = str;
        while ( *next && mystrchr(delim, *next) )
            *next++ = '\0';
    }
    
    if ( ! *next )
        return NULL;
    
    str = next;
    
    while ( *next && ! mystrchr(delim, *next) )
        ++next;
    while ( *next && mystrchr(delim, *next) )
        *next++ = '\0';
    
    return str;
}
// main function according to the task
string_array* my_split(char* param_1, char* param_2)
{
    int i=0;
    int len=strlen(param_1)+1;
    string_array* result=malloc(10*sizeof(string_array));
    result->size=len+1;
    result->array=malloc(len*sizeof(char*));
    char* ptr=mystrtok(param_1, param_2);
    while(ptr!=NULL)
    {
        result->array[i]=ptr;
        i++;

        ptr=mystrtok(NULL,param_2);
    }
    result->size=i;
    return result;
}
