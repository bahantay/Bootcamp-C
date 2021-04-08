#include <stdio.h>

// prrint 2 maximum elements of array
int main ()
{
    int massive[11] = {1, 4, 6, 2, 1, 7, 1, 5, 3, 5, 5};
    int i, j, count=0, count2=0;
    int max = 0;
    int element = 0;
    int second_element = 0;
    printf("array: \n");
    for (i = 0; i < 11; i++) // i++  i = i + 1
    {
        printf("%d ", massive[i]);
    }
    printf("\n\n");
    for (i = 0; i < 11; i++)
    {
        for (j = 0; j < 11; j++)
        {
            if (massive[i] == massive[j]) 
            {
                count++;
                count2++;
            }
        }
        if (count>max)
        {
            max = count;
            element = massive[i];
        }
        else if (count2>max)
        {
            max = count2;
            second_element = massive[i];
        }
        count = 0;
    }
    printf("First element: %d \nSecond element: %d \n", element, second_element);
}
