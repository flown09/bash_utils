#include <stdlib.h>

char *flag_e(char* arr, int *length)
{
    int max_len = *length * 2 + 1;
    char* result = malloc(max_len);
    if (!result)
        return NULL;

    int pos = 0;

    for (int i = 0; i < *length; i++)
    {
        if (arr[i] == '\n')
        {
            result[pos++] = '$';
            result[pos++] = '\n';
        }
        else
            result[pos++] = arr[i];
    }
    *length = pos;
    return result;
}
