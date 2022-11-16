#include <stdio.h>
#include <string.h>

char *reverseword(char word[])
{
    int i = 0;
    int j = strlen(word) - 1;
    while(j > i)
    {
        word[i]   += word[j];
        word[j]    = word[i] - word[j];
        word[i++] -= word[j--];
    }
    return word;
}

char *sepwords(char str[], char delitel[])
{
    char newstroka[strlen(str)];
    newstroka[0] = 0;

    char *p = strtok(str, delitel);

    reverseword(p);

    strcat(newstroka, p);
    strcat(newstroka, " ");

    while((p = strtok(NULL, delitel)))
    {
        reverseword(p);
        strcat(newstroka, p);
        strcat(newstroka, " ");
    }

    newstroka[strlen(newstroka)] = '\0';

    strcpy(str, newstroka);
    return str;
}

int main()
{
    char strg[100];

    scanf("%100[^\n\r]", strg);

    printf("\n%s\n", strg);

    sepwords(strg, ", .!\n?");

    printf("\n%s\n\n", strg);

    return 0;
}