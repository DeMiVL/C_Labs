#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct node Movie;

struct node
{
    int     year;
    char*   Title;
    char*   Director;
    char*   Country;
    char*   Actors;
};


int main()
{
    struct node *Movie1 = malloc(sizeof(struct node));
    Movie1->Title   = "LOLOV LOL LOLOVICH";
    Movie1->year    = 2000;
    Movie1->Actors  = "LOLOV LOL LOLOVICH";


    printf("%s\n", Movie1->Title);
    free(Movie1);
    return 1;
}