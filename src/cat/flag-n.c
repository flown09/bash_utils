#include <stdlib.h>
#include <stdio.h>

char* flag_n(char* data, int *length)
{
    int line_number = 1;
    int max_line_digits = 10;

    int new_length = *length;
    for (int i = 0; i < *length; i++) {
        if (data[i] == '\n' || i == 0) {
            new_length += max_line_digits + 8; 
        }
    }
    char* result = malloc(new_length + 1);
    if (!result)
        return NULL;

    char line_prefix[max_line_digits + 2];
    int pos = 0;
    if (*length != 0)
    {
        for (int i = 0; i < *length; i++)
        {
            if (i == 0 || data[i - 1] == '\n') 
            {
                sprintf(line_prefix, "     %d  ", line_number++);
                for (int j = 0; line_prefix[j] != '\0'; j++) 
                {
                    result[pos++] = line_prefix[j];
                }
            }
            result[pos++] = data[i];
        }
    }
    *length = pos;
    return result;
}