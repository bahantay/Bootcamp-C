/*
**
** QWASAR.IO -- first_param
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

char* first_param(string_array* param_1)
{
  	char* res = malloc(100);
  	for (int i = 0; i < 1; i++)
    {
    	res = param_1->array[i];
    }
  	return res;
}

