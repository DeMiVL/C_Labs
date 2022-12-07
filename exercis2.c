#include "isogram.h"
#include <string.h>

bool is_isogram(const char phrase[])
{
    int   len    = strlen(phrase);
    char  pow1[len + 1];
    pow1[0] = 0;
    int i;
    for (i = 0; i < len; i++)
    {
        pow1[i] = phrase[i];
    }
    pow1[len] = 0;
    for (i = 0; i < len - 1; i++)
    {
        if (pow1[i] > pow1[i + 1])
        {
            pow1[i]     += pow1[i + 1];
            pow1[i + 1]  = pow1[i] - pow1[i + 1];
            pow1[i]     -= pow1[i + 1];
        }
    }
    for (i = 0; i < len - 1; i++)
    {
        if(pow1[i] == 32) continue;
        if(pow1[i] == pow1[i + 1]) return 0;
    }
    return 1;
}
