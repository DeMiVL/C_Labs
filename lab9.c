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
    int iter     = 0;
    while(1)
    {
        char word[strlen(str)];
        int  i = 0;
        while(1)
        {
            if (strchr(delitel, str[iter + i]) == NULL)
            {   
                word[i] = str[iter + i];
                i++;
            }
            else
            {
                if (strlen(word) != 0)
                {
                    word[i] = '\0';
                    reverseword(word);
                    strcat(newstroka, word);
                    iter = strlen(newstroka);
                }
                newstroka[iter] = str[iter];
                newstroka[iter + 1] = 0;
                iter = strlen(newstroka);
                break;
            }
        }
        if(str[iter] == '\0')
        {
            break;
        }    
    }
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