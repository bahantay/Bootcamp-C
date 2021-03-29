#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int is_upper(char c)
{
    return c >= 'A' && c <= 'Z';
}

int my_lower(char c)
{
    if (is_upper(c))
        return c + 32;
    return c;
}

int my_strlen(char *s)
{
    int i = 0;
    for (; s[i]; i++)
        ;
    return i;
}

int my_is(char c)
{
    return c == ' ' || c == '\t';
}

char *my_strsub(char *s, int start, int end)
{
    char *res = malloc(100);
    int i = 0;
    while (start < end)
        res[i++] = s[start++];
    res[i] = 0;
    return res;
}

int cmp_alpha(char *a, char *b)
{
    while (*a && *b && *a == *b)
    {
         a++;
         b++;
    }
    return my_lower(*a) <= my_lower(*b);
}

int cmp_len(char *a, char *b)
{
     return my_strlen(a) <= my_strlen(b);
}

void my_sort(char *arr[], int n, int(*cmp)(char*, char*))
{
    char *tmp;
    for (int i = 0; i < n; i++)
         for (int j = 0; j < n - 1; j++)
         {
             if ((*cmp)(arr[j], arr[j + 1]) == 0)
             {
                  tmp = arr[j];
                  arr[j] = arr[j + 1];
                  arr[j + 1] = tmp;
             }
         }
}

char* ord_alphlong(char *s)
{
     int start = 0, idx = 0;
     char *words[my_strlen(s) / 2 + 1];
     for (int i = 0; s[i]; i++)
     {
         if (!my_is(s[i]) && i > 0 && my_is(s[i - 1]))
              start = i;
         if (my_is(s[i]) && i > 0 && !my_is(s[i - 1]))
              words[idx++] = my_strsub(s, start, i);
         if (!s[i + 1] && !my_is(s[i]))
              words[idx++] = my_strsub(s, start, i + 1);
     }
     my_sort(words, idx, &cmp_alpha);
     my_sort(words, idx, &cmp_len);
     char* res = malloc(100);
     int pushed=0;
	 if (idx)
     for (int i = 0; ; )
     {
           char *word = words[i];
           int lng = my_strlen(word);
           if (100 < pushed+lng+1) exit(1);                 // too long
           for (int i = 0; i < lng; ) res[pushed++] = word[i++];
           if (++i == idx) break;                           // last word
           res[pushed++] = lng < my_strlen(words[i]) ? '^'  // other size
                                                     : ' '; // same size
     }
     res[pushed]='\0';
     return res;
}

int main()
{	
	char *my_str = strdup("Never take a gamble you are not prepared to lose");
    printf("%s\n", ord_alphlong(my_str));
    return 0;
}
