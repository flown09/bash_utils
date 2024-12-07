#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

char* flag_v(char* arr, int *length)
{
    int max_len = *length * 4 + 1;
    char* result = malloc(max_len);
    if (!result)
        return NULL;

    int pos = 0;

    for (int i = 0; i < *length; i++)
    {
        unsigned char c = arr[i];
        if (c > 0 && c < 32 && c != '\t' && c !='\n')
        {
            result[pos++] = '^';
            result[pos++] = c + 64;
        }
        else if (c > 127 && c <160)
        {
            result[pos++] = 'M';
            result[pos++] = '-';
            result[pos++] = '^';
            result[pos++] = c - 64;
        }
        else if (c >= 160 && c < 255)
        {
            result[pos++] = 'M';
            result[pos++] = '-';
            result[pos++] = c - 128;
        }
        else if (c == 127)
        {
            result[pos++] = '^';
            result[pos++] = '?';
        }
        else if (c == 255)
        {
            result[pos++] = 'M';
            result[pos++] = '-';
            result[pos++] = '^';
            result[pos++] = '?';
        }
        else
            result[pos++] = c;
        // if (c == 255)
        // {
        //     result[pos++] = 'M';
        //     result[pos++] = '-';
        //     result[pos++] = '^';
        //     result[pos++] = '?';
        // }
        // else if (isprint(c) || c == '\t' || c == '\n' || c == '\r')
        //     result[pos++] = c;
        // else if (c < 32)
        // {
        //     result[pos++] = '^';
        //     result[pos++] = c + '@';
        // }
        // else if (c == 127)
        // {
        //     result[pos++] = '^';
        //     result[pos++] = '?';
        // }
        // else
        // { 
        //     result[pos++] = 'M';
        //     result[pos++] = '-';
        //     if (c == 255)
        //     {
        //         result[pos++] = '^';
        //         result[pos++] = '?';
        //     }
        //     else if (c >= 160)
        //         result[pos++] = c - 128;
        //     else
        //     {
        //         result[pos++] = '^';
        //         result[pos++] = c - 64;
        //     }
        // }
    }
    *length = pos;
    return result;
}