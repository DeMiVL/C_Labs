#include <stdio.h>
#include <string.h>

char *reverseword(char word[])
{
    int i = 0;
    int j = strlen(word) - 1;
    while(i != j || j > i)
    {
        word[i] += word[j];
        word[j] = word[i] - word[j];
        word[i] -= word[j];
        i++; j--;
        if (i == j || i > j) break;
    }
    return word;
}

char *sepwords(char str[], char delitel[])
{
    char newstroka[strlen(str)];
    newstroka[0] = 0;
    int len = 0;
    while(1)
    {
        char word[strlen(str)];
        int i = 0;
        while(1)
        {
            if (strchr(delitel, str[len + i]) == NULL)
            {   
                word[i] = str[len + i];
                i++;
            }
            else
            {
                if (strlen(word) != 0)
                {
                    word[i] = '\0';
                    reverseword(word);
                    strcat(newstroka, word);
                }
                len = strlen(newstroka);
                newstroka[len] = str[len];
                newstroka[len + 1] = 0;
                len = strlen(newstroka);
                break;
            }
        }
        if(str[len] == '\0')
        {
            break;
        }    
    }
    strcpy(str, newstroka);
    return str;
}

int main()
{
    char strg[] = "Night time, cavity, come in\nDowntown, pony, work your pitch\nDaytime, dancer, I'll come inside\nGot my teacher, now carve your niche\0";
    
    printf("\n%s\n", strg);

    sepwords(strg, ", .!?\n");

    printf("\n%s\n\n", strg);

    return 0;
}