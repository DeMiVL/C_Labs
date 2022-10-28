#include <stdio.h>
#include <string.h>

int strlen2(char * word)
{
    int i = 0;
    while(word[i] != 0)
    {
        i++;
    }
    return i;
}

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

void sepwords(char str[], char delitel[])
{
    char word[strlen(str)];
    char newstroka[] = "";
    int len = 0;
    word[strlen(str)] = '\0';
    int i = 0;

    while(1)
    {
        if (strchr(delitel, str[len + i]) == NULL)
        {   
            word[i] = str[len + i];
            word[i + 1] = '\0';
            i++;
        }
        else
        {
            reverseword(word);
            strcat(newstroka, word);
            //printf("%d\n", *word);
            len = strlen2(newstroka);
            newstroka[len] = str[i];
            newstroka[len + 1] = 0;
            printf("\"%s\"\n", newstroka);
            len = len + 1;
            i = 0;
        }
        if(str[i] == '\0')
        {
            break;
        }
    }
    printf("\"%s\"\n", newstroka);
}

int main()
{
    char strg[] = "Night time, cavity, come in\nDowntown, pony, work your pitch\nDaytime, dancer, I'll come inside\nGot my teacher, now carve your niche";
    //char *strgnew;

    printf("%s\n", strg);

    sepwords(strg, ", \n");
    //printf("%s\n", strgnew);

    return 0;
}