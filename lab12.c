#include <stdio.h>
#include <string.h>
#include <stdlib.h>


struct node
{
    // element settings:
    char*        year;
    char*        Title;
    char*        Director;
    char*        Country;
    char*        Actors;

    // list settings:
    struct node* next;
    struct node* prev;
};

struct node *KillHead     (struct node *head);
struct node *KillbyName   (struct node *head, char name[]);
struct node *KillTail     (struct node *head);
void         ChecktheClaws(struct node *head);
void         ActorsMovies (struct node *head, char name[]);
struct node *SetonFire    (char title[], char director[], char country[], char actr[], char year[]);
struct node *Append       (struct node *head, char title[], char director[], char country[], char actr[], char year[]);
struct node *FreeList     (struct node *head);

struct node *SetonFire(char *title, char *director, char *country, char *actr, char *year)
{
    struct node *Movie1 = malloc(sizeof(struct node));

    Movie1->Actors      = strdup(actr);
    Movie1->Director    = strdup(director);
    Movie1->Country     = strdup(country);
    Movie1->Title       = strdup(title);
    Movie1->year        = strdup(year);

    Movie1->next        = NULL;
    Movie1->prev        = NULL;

    return Movie1;
}

struct node *Append(struct node *head, char *title, char *director, char *country, char *actr, char *year)
{   
    if(head == NULL)
    { 
        return SetonFire(title, director, country, actr, year);
    }
    struct node *Movie1 = malloc(sizeof(struct node));
    while(head->next != NULL)
    {
        head = head->next;
    }

    Movie1->Actors      = strdup(actr);
    Movie1->Director    = strdup(director);
    Movie1->Country     = strdup(country);
    Movie1->Title       = strdup(title);
    Movie1->year        = strdup(year);

    Movie1->next        = NULL;
    Movie1->prev        = head;
    head->next          = Movie1;

    while(head->prev != NULL)
    {
        head = head->prev;
    }
    return head;
}

struct node *KillbyName(struct node *head, char name[])
{
    do
    {
        if (strcmp(head->Title, name) == 0)
        {
            if (head->next == NULL && head->prev == NULL)
            {
                return FreeList(head);
            }
            if (head->next == NULL)
            {
                head->prev->next = NULL;
                free(head->Actors);
                free(head->Country);
                free(head->Director);
                free(head->year);
                free(head->Title);
                free(head);
            }
            if (head->prev == NULL)
            {
                return KillHead(head); 
            }
            head->prev->next = head->next;
            head = head->prev;
            free(head->next->prev->Actors);
            free(head->next->prev->Country);
            free(head->next->prev->Director);
            free(head->next->prev->Title);
            free(head->next->prev->year);
            free(head->next->prev);
            head->next->prev = head;
            while(head->prev != NULL)
                head = head->prev;
            return head;
        }
        head = head->next;
    }
    while(head->next != NULL);
    printf("There is no such movie in our list\n");
    while(head->prev != NULL)
        head = head->prev;
    return head;
}

struct node *KillHead(struct node *head)
{
    head = head->next;
    free(head->prev->Actors);
    free(head->prev->Country);
    free(head->prev->Director);
    free(head->prev->Title);
    free(head->prev->year);
    free(head->prev);
    head->prev = NULL;
    return head;
}

struct node *KillTail(struct node *head)
{
    if(head->next == NULL && head->prev == NULL)
    {
        return FreeList(head);
    }
    while(head->next != NULL)
        head = head->next;
    head = head->prev;
    free(head->next->Actors);
    free(head->next->Country);
    free(head->next->Director);
    free(head->next->Title);
    free(head->next->year);
    free(head->next);
    head->next = NULL;
    while(head->prev != NULL)
        head = head->prev;
    return head;
}

struct node *FreeList(struct node *head)
{
    while(head->next != NULL)
    {
        head = head->next;
    }
    while(head->prev != NULL)
    {
        head = head->prev;

        free(head->next->Actors);
        free(head->next->Country);
        free(head->next->Director);
        free(head->next->Title);
        free(head->next->year);
        free(head->next);
    }
    free(head->Actors);
    free(head->Country);
    free(head->Director);
    free(head->Title);
    free(head->year);
    free(head);
    return NULL;
}

void ChecktheClaws(struct node *head)
{
    printf("Movie:\t  %s\nYear:\t  %s\nCountry:  %s\nDirector: %s\nStars:\t  %s\n\n", head->Title, head->year, head->Country, head->Director, head->Actors);
    while(1)
    {
        if (head->next == NULL)
        {
            break;
        }
        head = head->next;
        printf("Movie:\t  %s\nYear:\t  %s\nCountry:  %s\nDirector: %s\nStars:\t  %s\n\n", head->Title, head->year, head->Country, head->Director, head->Actors);
    }
}

void ActorsMovies(struct node *head, char name[])
{
    int i = 0;
    while(1)
    {
        if(strstr(head->Actors, name) != NULL)
        {
            i++;
            printf("Movie:\t  %s\nYear:\t  %s\nCountry:  %s\nDirector: %s\nStars:\t  %s\n\n", head->Title, head->year, head->Country, head->Director, head->Actors);
        }
        if (head->next == NULL) break;
        head = head->next;
    }
    if(i == 0) printf("No such actor in our data base\n");
}

FILE *SaveBD(struct node *bd, FILE *BD)
{
    if (bd == NULL) return BD;
    if (BD == NULL)
    {
        BD = fopen("Movies_DB.txt", "w+");
    }
    fputs(bd->Title,    BD ); fputc('\n', BD);
    fputs(bd->Director, BD ); fputc('\n', BD);
    fputs(bd->Country,  BD ); fputc('\n', BD);
    fputs(bd->Actors,   BD ); fputc('\n', BD);
    fputs(bd->year,     BD ); fputc('\n', BD);

    while (bd->next != NULL)
    {
        bd  = bd->next;
        fputs(bd->Title,    BD ); fputc('\n', BD);
        fputs(bd->Director, BD ); fputc('\n', BD);
        fputs(bd->Country,  BD ); fputc('\n', BD);
        fputs(bd->Actors,   BD ); fputc('\n', BD);
        fputs(bd->year,     BD ); fputc('\n', BD);
    }
    return BD;
};

struct node *OpenDB(struct node *bd, char bd_name[])
{
    if (strcmp(bd_name, "") == 0)
    {
        return NULL;
    }

    char title   [100] = "";
    char year    [100] = "";
    char country [100] = "";
    char director[100] = "";
    char actors  [100] = "";

    FILE * DB = fopen(bd_name, "r");

    fgets(title,    1000, DB);

    if(strcmp(title, "") == 0)
    {
        fclose(DB); 
        return NULL;
    }

    rewind(DB);
    int i = 0, j = 0; 
	
    while(1)
    {
        fgets(title,    1000, DB);
        if(feof(DB) || strcmp(title, "") == 0) 
        {
            break;
        }
        while (title[i] != 10)
        {
            i++;
        }
        title[i] = 0; i = 0;
        fgets(director, 1000, DB);
        if(feof(DB) || strcmp(director, "") == 0) 
        {
            break;
        }
        while (director[i] != 10)
        {
            i++;
        }
        director[i] = 0; i = 0;
        fgets(country,  1000, DB);
        if(feof(DB) || strcmp(country, "") == 0) 
        {
            break;
        }
        while (country[i] != 10)
        {
            i++;
        }
        country[i] = 0; i = 0;
        fgets(actors,   1000, DB);
        if(feof(DB) || strcmp(actors, "") == 0) 
        {
            break;
        }
        while (actors[i] != 10)
        {
            i++;
        }
        actors[i] = 0; i = 0;
        fgets(year,     1000,    DB);
        if(feof(DB) || strcmp(year, "") == 0) 
        {
            break;
        }
        while (year[i] != 10)
        {
            i++;
        }
        year[i] = 0;
		j++;
        bd = Append(bd, title, director, country, actors, year);
    }
	if (j == 0)
    {
        return NULL;
		printf("File is incorrect\n");
    }
    fclose(DB);

    return bd;
}

int main()
{
    FILE        *BD   = NULL;

    struct node *Head = NULL;

    Head = OpenDB(Head, "Movies_DB.txt");
    BD   = fopen("Movies_DB.txt", "w+");
    if (Head == NULL)
    {
		printf("No data base file\n");
        Head = SetonFire("Django Unchained", "Quentin Tarantino", "USA", "Jamie Foxx, Christoph Waltz, Leonardo DiCaprio, Kerry Washington, Samuel L. Jackson", "2012");
        Head = Append(Head, "February", "Oz Perkins", "USA", "Emma Roberts, Kiernan Shipka, Lucy Boynton, James Remar, Lauren Holly", "2015");
        Head = Append(Head, "Terminator 2: Judgment Day", "James Cameron", "USA", "Arnold Schwarzenegger, Linda Hamilton, Edward Furlong, Robert Patrick", "1991");
        Head = Append(Head, "Terminator", "James Cameron", "USA", "Arnold Schwarzenegger, Michael Biehn, Linda Hamilton", "1984");
        Head = Append(Head, "Fate/stay night Movie: Heaven's Feel - I. Presage Flower", "Tomonori Sudou", "Japan", "Noriaki Sugiyama, Noriko Shitaya, Ayako Kawasumi, Kana Ueda", "2018");
        Head = Append(Head, "Deftones - My Own Summer (Official Music Video)", "Dean Karr", "USA", "Chino Moreno, Stephen Carpenter, Chi Cheng, Abe Cunningham", "1997");
    }
	else
	{
		printf("Worked on data base file\n");
	}

    printf("BASE\n");

    ChecktheClaws(Head);

    // getchar();

    // printf("ACTOR Arnold Schwarzenegger\n");

    // ActorsMovies(Head, "Arnold Schwarzenegger");

    // getchar();

    // printf("Tail got Killed\n");

    // Head = KillTail(Head);

    // ChecktheClaws(Head);

    // getchar();

    // printf("February got Killed\n");

    // Head = KillbyName(Head, "February");

    // ChecktheClaws(Head);

    // getchar();

    // printf("Head got Killed\n");

    // Head = KillHead(Head);
    
    // ChecktheClaws(Head);

    SaveBD(Head, BD);

    FreeList(Head);

    fclose(BD);

    return 1;
}