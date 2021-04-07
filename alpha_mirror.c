/*
**
** QWASAR.IO -- alpha_mirror
**
** @param {char*} param_1
**
** @return {char*}
**
*/
//#include <stdio.h>
//#include <string.h>

char* alpha_mirror(char* param_1)
{
	char* reverseAlphabetsmall = "zyxwvutsrqponmlkjihgfedcba";
  	char* reverseAlphabetbig = "ZYXWVUTSRQPONMLKJIHGFEDCBA";
    for (int i = 0; i < strlen(param_1); i++)
    	if(param_1[i]>='a'&&param_1[i]<='z')
          param_1[i] = reverseAlphabetsmall[param_1[i]-'a'];
 		else if (param_1[i]>='A'&&param_1[i]<='Z')
          param_1[i] = reverseAlphabetbig[param_1[i]-'A'];
  
    return param_1;
}

