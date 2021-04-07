/*
**
** QWASAR.IO -- last_param
**
** @param {string_array*} param_1
**
** @return {char*}
**
*/
#ifndef STRUCT_STRING_ARRAY
#define STRUCT_STRING_ARRAY
typedef struct s_string_array
{
    int size;
    char** array;
} string_array;
#endif

char* last_param(string_array* param_1)
{
	char* res = malloc(100);
  	int len = param_1->size;
  	for (int i=len-1; i<len; i++)
    {
    	res=param_1->array[i];
    }
  	return res;
}

