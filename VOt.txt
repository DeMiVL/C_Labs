#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

short isnumber(char str[])
{
    int j = strlen(str);
    
    for(int i = 0; i < j; i++)
    {
        if (!isdigit(str[i])) return 0;
    }

    return 1;
}

int sumnumbers(char str[])
{
    char delitel[1] = " ";
    int   sum = 0;
    int   g   = 0;
    char *p   = strtok(str, delitel);

    if(isnumber(p))
    {
        g    = atoi(p);
        sum += g;
    }

    while((p = strtok(NULL, delitel)))
    {
        if(isnumber(p))
        {
            g    = atoi(p);
            sum += g;
        }
    }

    return sum;
}

int main()
{
    char strg[100];

    scanf("%100[^\n\r]", strg);

    printf("%d\n", sumnumbers(strg));

    return 0;
}