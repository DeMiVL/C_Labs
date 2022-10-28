#include <stdio.h>
#include <string.h>

char* WordSeparation(char String[])
{
    
}

char *Reverse(char word[])
{
    int i = 0;
    int j = strlen(word) - 1;
    while(i != j || j > i)
    {
        word[i] += word[j];
        word[j] =  word[i] - word[j];
        word[i] -= word[j];
        i++; j--;
        if (i == j || i > j) break;
    }
    return word;
}


int main()
{
    char str[] = "Night time, cavity, come in\nDowntown, pony, work your pitch\nDaytime, dancer, I'll come inside\nGot my teacher, now carve your niche";
    char delitel[] = ", \n";

    char *p = (strtok(str, delitel));
    printf(Reverse(p));
    while ((p = strtok(NULL, delitel)))
        printf(" %s", Reverse(p));
    printf("\n");

    return 0;
}
