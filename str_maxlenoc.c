#include <stdlib.h>						//for malloc

#ifndef STRUCT_STRING_ARRAY
#define STRUCT_STRING_ARRAY

typedef struct s_string_array
{
    int size;
    char** array;
} string_array;
#endif

int	maxi(char* str, char* str2)						// return array length
{
    int	count;
    
    count = 0;
    while (*str && str2[count] && *str++ == str2[count])	// Loop str и str2, till they are the same
        count++;
    return (count);
}

char* cpy(char* str, int size)						// Copy first symbols SIZE
{
    int	index;
    char* ret;
    
    index = 0;
    ret = malloc(sizeof(char) * size + 1);
    while (*str && size-- > 0)
        ret[index++] = *str++;
    ret[index] = '\0';
    return (ret);
}

char* find(char* str, char* str2)					// Loop 2 strings
{
    char* ret;
    int	count;
    int max;
    
    max = 0;
    ret = NULL;
    while (*str)
    {
        count = -1;
        while (str2[++count])
            if (maxi(str, &str2[count]) > max)				
            {
                max = maxi(str, &str2[count]);				// if substring more than MAX
                if (ret)
                    free(ret);
                ret = cpy(&str2[count], max);				// copy substring into the RET
            }
        *str++;
    }
    return (ret);
}

char* str_maxlenoc(string_array* param_1, int param_2)
{
    char** argv = param_1->array;
  	int argc = param_1->size;
    char* tmp;
    char* ret;
    int	count;
	  char* empty = "";
    ret = find(argv[0], argv[1]);				//retrieve the largest common sub-string
    if (!ret)
        return empty;						
    count = 0;
    while (count < argc)						//scan the following arguments			
    {
        tmp = find(ret, argv[count++]);			//test an argument and the previous one under string
      	if (!tmp)
            return empty;
        free(ret);
        ret = tmp;								//replace the old substring with the new one			
    }
    char* res = (char*)malloc(100);
    int pushed = 0;
    while (*ret)
    {
        res[pushed++] = *ret++;
    }
    res[pushed]='\0';
    return res;
}
