/*
**
** QWASAR.IO -- my_sort
**
** @param {integer_array*} param_1
** @param {char*} param_2
**
** @return {integer_array*}
**
*/
#ifndef STRUCT_INTEGER_ARRAY
#define STRUCT_INTEGER_ARRAY
typedef struct s_integer_array
{
    int size;
    int* array;
} integer_array;
#endif

integer_array* my_sort(integer_array* param_1, char * param_2)
{	
    integer_array *res;
    res = (integer_array *)malloc(sizeof(integer_array));	//malloc size of integer_array
    res->size = param_1->size;
    res->array = param_1->array;

  	if (param_2[0]==97 && param_2[1]==115 && param_2[2]==99) //"asc" a=97, s=115, c=99 by ASCII
    {
    	for (int i = 0; i<res->size; i++)
        {
        	for (int j = 0; j<res->size; j++)
        	{
        		if (res->array[j] > res->array[i])          //Comparing other array elements
				{
					int tmp = res->array[i];                //Using temporary variable for storing last value
					res->array[i] = res->array[j];          //replacing value
					res->array[j] = tmp;                    //storing last value
				}
        	}
        }
      	return res;
    }
	else if (param_2[0]==100 && param_2[1]==101 && param_2[2]==115 && param_2[3]==99) //"desc" d=100, e=101, s=115, c=99 by ASCII
    {
    	for (int i = 0; i<res->size; i++)
    	{
      		for (int j = 0; j<res->size; j++)
     		{
        		if (res->array[j] < res->array[i])          //Comparing other array elements
				{
					int tmp = res->array[i];                //Using temporary variable for storing last value
					res->array[i] = res->array[j];          //replacing value
					res->array[j] = tmp;                    //storing last value
				}
     		}
     	}
   		return res;
	}
  	else {
    return res;
    }
}

//https://en.wikiversity.org/wiki/C_Source_Code/Sorting_array_in_ascending_and_descending_order
