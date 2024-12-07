#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "flag-s.h"
#include "flag-v.h"
#include "flag-e.h"
#include "flag-t.h"
#include "flag-n.h"
#include "flag-b.h"

void* flags(int count_flags[8], char* data, int *length);
int isFlag(int count_flags[8], char* flags[], int count_argc);
char* readFile(char filename[256], char* data, int *length);
void printFile(char* data, int length);
void* append(char* data, int *length, int *capacity, char value);
int isFile(char filename[256]);

int main(int argc, char* argv[])
{
    if (strcmp(argv[1], "cat") == 0)
    {
        int count_flags[8] = {0};
        if (isFlag(count_flags, argv, argc) == 1)
        {
            printf("n/a");
        }
        else
        {
            for (int i = 2; i < argc; i++)
            {
                if (isFile(argv[i]) == 0)
                {
                    char *data;
                    int length = 0;
                    data = readFile(argv[i], data, &length);
                    data = flags(count_flags, data, &length);
                    printFile(data, length);
                }
                else if (strncmp(argv[i], "-", 1) != 0)
                {
                    printf("cat: %s: No such file or directory", argv[i]);
                    break;
                }
            }
        }
    }
    
    return 0;
}

void* flags(int count_flags[8], char* data, int *length)
{
    if (count_flags[4] > 0)
        data = flag_s(data, length);
    if (count_flags[7] > 0 || count_flags[1] > 0 || count_flags[5] > 0)
        data = flag_v(data, length);

    if (count_flags[1] > 0)
        data = flag_e(data, length);
    else if (count_flags[2] > 0)
        data = flag_e(data, length);

    if (count_flags[5] > 0)
        data = flag_t(data, length);
    else if (count_flags[6] > 0)
        data = flag_t(data, length);
    
    if (count_flags[0] > 0)
        data = flag_b(data, length);
    else if (count_flags[3] > 0)
        data = flag_n(data, length);

    return data;
}

int isFlag(int count_flags[8], char* flags[], int count_argc)
{
    for (int i = 2; i < count_argc; i++)
    {
        if (flags[i][0] == '-')
        {
            if (strcmp(flags[i], "--number-nonblank") == 0)
                count_flags[0] += 1;
            else if (strcmp(flags[i], "--number") == 0)
                count_flags[3] += 1;
            else if (strcmp(flags[i], "--squeeze-blank") == 0)
                count_flags[4] += 1;
            else
            {
                for (int j = 1; flags[i][j] != '\0'; j++)
                {
                    printf("%c", flags[i][j]);
                    if (flags[i][j] == 'b')
                        count_flags[0] += 1;
                    else if (flags[i][j] == 'e')
                        count_flags[1] += 1;
                    else if (flags[i][j] == 'E')
                        count_flags[2] += 1;
                    else if (flags[i][j] == 'n')
                        count_flags[3] += 1;
                    else if (flags[i][j] == 's')
                        count_flags[4] += 1;
                    else if (flags[i][j] == 't')
                        count_flags[5] += 1;
                    else if (flags[i][j] == 'T')
                        count_flags[6] += 1;
                    else if (flags[i][j] == 'v')
                        count_flags[7] += 1;
                    else
                        return 1;
                }
            }
        }
    }
    return 0;
}

char* readFile(char filename[256], char* data, int *length)
{
    FILE *fp = fopen(filename, "rb");

    // Определяем размер файла
    fseek(fp, 0, SEEK_END);
    *length = ftell(fp);
    rewind(fp);

    data = malloc(*length);

    fread(data, 1, *length, fp);
    fclose(fp);
    return data;

    // char ch;
    // data = malloc(sizeof(char) * *capacity);
    // while ((ch = fgetc(fp)) != EOF)
    //     data = append(data, length, capacity, ch);
    // return data;
    // fclose(fp);
}

void* append(char* data, int *length, int *capacity, char value)
{
    if (*length >= *capacity)
    {
        (*capacity) *= 2;
        char* ar = realloc(data, sizeof(char) * *capacity);
        if (ar == NULL)
            return data;
        data = ar;
    }
    data[*length] = value;
    (*length)++;

    return data;
}

int isFile(char filename[256])
{
    FILE *fp;
    if ((fp = fopen(filename, "r")) == NULL)
    {
        return 1;
    }
    fclose(fp);
    return 0;
}

void printFile(char* data, int length)
{
    for (int i = 0; i < length; i++)
    {
        printf("%c", data[i]);
    }
}