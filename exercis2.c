#include "isogram.h"
#include <string.h>

bool is_isogram(const char phrase[])
{
    int   len    = strlen(phrase);
    char  pow1[len + 1];
    pow1[0] = 0;
    strcpy(pow1, phrase);
    int i, j;
    for (i = 0; i < len - 1; i++)
        for (j = 0; j < len - i - 1; j++)
            if (pow1[j] > pow1[j + 1])
                {
                    pow1[j]     += pow1[j + 1];
                    pow1[j + 1]  = pow1[j] - pow1[j + 1];
                    pow1[j]     -= pow1[j + 1];
                }
    for (i = 0; i < len - 1; i++)
    {
        if(pow1[i] == 32) continue;
        if(pow1[i] == pow1[i + 1]) return 0;
    }
    
    return 1;
}
