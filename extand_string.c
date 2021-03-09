char* expand_string(char* param_1)
{
 int len1 = strlen(param_1);
    int i;
    int k = 0;
    char* tmp = malloc(100);
    char* tmp2 = malloc(100);
    int k2 =0;
    if (len1 == 0)
    {
    	return tmp;
	} 
 	else
 	{ 
     	for(i = 0; i < len1; i++)
     	{   
         	if ((i == 0 && param_1[i] == 32) || (param_1[i] == 32 && param_1[i+1] == 32) || (i == len1-1 && param_1[i] == 32)) //condition to remove space or 32 ASCII
            {
            }
            else 
            {
                tmp[k] = param_1[i];
                k++;
            }
     	}
     	//printf("%s/n", tmp);
      	for (i = 0; i < len1; i++)
      	{
        	if(tmp[i] == 32)
        	{
          		tmp2[k2] = 32;
          		tmp2[k2+1] =32;
          		tmp2[k2+2] =32;
          		k2 = k2+3;
        	}
        	else
        	{
         	tmp2[k2] = tmp[i];
          	k2++;
        	}
        	if(tmp[i] == '"')
        	{
         	break;
        	}
      	}
        return tmp2;
 	}
}
