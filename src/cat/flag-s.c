#include <string.h>

char* flag_s(char* data, int *length)
{
    for (int i = 0; i < *length - 2; )
    {
        if (data[i] == '\n' && data[i + 1] == '\n' && data[i + 2] == '\n')
        {
            for (int j = i + 2; j < *length - 1; j++)
            {
                data[j] = data[j + 1];
            }
            (*length)--;
        }
        else
        {
            i++;
        }
    }

    if (data[0] == '\n' && data[1] == '\n')
    {
        for (int i = 0; i < *length - 1; i++)
        {
            data[i] = data[i + 1];
        }
        (*length)--;
    }
    return data;
} 
