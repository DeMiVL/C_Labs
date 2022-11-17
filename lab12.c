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

struct node *Killer       (struct node *head);
struct node *Kill         (struct node *head);
struct node *KillHead     (struct node *head);
struct node *KillbyName   (struct node *head, char name[]);
struct node *KillTail     (struct node *head);
void         ChecktheClaws(struct node *head);
void         ActorsMovies (struct node *head);//, char name[]);
struct node *BacktoHead   (struct node *head);
struct node *SetonFire    (char title[], char director[], char country[], char actr[], char year[]);
struct node *Append       (struct node *head, char title[], char director[], char country[], char actr[], char year[]);
struct node *AppendInput  (struct node *head);
struct node *FreeList     (struct node *head);


struct node *Killer(struct node *head)
{
    free(head->Actors);
    free(head->year);
    free(head->Director);
    free(head->Title);
    free(head->Country);

    if(head->next == NULL && head->prev == NULL)
    {
        free(head);
        return NULL;
    }
    if(head->next == NULL)
    {
        head = head->prev;
        free(head->next);
        head->next = NULL;
        return BacktoHead(head);
    }
    if(head->prev == NULL)
    {
        head = head->next;
        free(head->prev);
        head->prev = NULL;
        return head;
    }

    head = head->prev;
    head->next = head->next->next;
    free(head->next->prev);
    head->next->prev = head;

    return BacktoHead(head);
}

struct node *BacktoHead(struct node *head)
{
    while(head->prev != NULL)
    {
        head = head->prev;
    }
    return head;
}

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

struct node *AppendInput  (struct node *head)
{
    char title      [100];
    char director   [100];
    char country    [100];
    char actr       [100];
    char year       [5];

    printf("Input movie title: ");
    scanf("%100[^\n\r]",    title);
                getchar();

    printf("Input director of a movie: ");
    scanf("%100[^\n\r]",    director);
                getchar();

    printf("Input country of a movie: ");
    scanf("%100[^\n\r]",    country);
                getchar();

    printf("Input actors of a movie: ");
    scanf("%100[^\n\r]",    actr);
                getchar();

    printf("Input year of a movie: ");
    scanf("%5[^\n\r]",      year);

    return Append(head, title, director, country, actr, year);

}

struct node *Kill(struct node *head)
{
    int     d = 0;
    char    note[100];
    printf("Do u want to remove first movie, last or remove movie by its title? input 1, 2 or 3 respectively, any other number means no removal at all: ");

    scanf("%d", &d);
    switch(d)
    {
        case 1:
        return KillHead(head);
        case 2:
        return KillTail(head);
        case 3:
        printf("lol\n");
        getchar();
        printf("Input movie title: ");
        scanf("%100[^\n\r]", note);
        return KillbyName(head, note);
        default:
        printf("No removal\n");
        return head;
    }
}

struct node *KillbyName(struct node *head, char name[])
{
    if(strcmp(head->Title, name) == 0)
    {
        return KillHead(head);
    }

    while(head->next != NULL)
    {
        head = head->next;
        if(strcmp(head->Title, name) == 0)
        {
            return KillHead(head);
        }
    }

    printf("No such movie in base\n");
    return BacktoHead(head);
}

struct node *KillHead(struct node *head)
{
    return Killer(head);
}

struct node *KillTail(struct node *head)
{
    if(head->next == NULL && head->prev == NULL)
    {
        return FreeList(head);
    }
    while(head->next != NULL)
        head = head->next;

    return Killer(head);
}

struct node *FreeList(struct node *head)
{
    while(head != NULL)
    {
        head = Killer(head);
    }
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

void ActorsMovies(struct node *head)//, char name[])
{
    char name[100];

    printf("Input actors name and second name: ");
    scanf("%100[^\n\r]", name);

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

    char title   [200] = "";
    char year    [200] = "";
    char country [200] = "";
    char director[200] = "";
    char actors  [200] = "";

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

    int operation     = 0;

    Head = OpenDB(Head, "Movies_DB.txt");

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

    while(operation != -1)
    {
        printf("Choose operation:\n1 - check the base\n2 - check actors movies\n3 - add new movie\n4 - remove movie\nany other char exit and save base\ninput -> ");
        scanf("%d", &operation);
        switch(operation)
        {
            case 1:
                ChecktheClaws(Head);
                break;
            case 2:
                printf("\n");
                getchar();
                ActorsMovies(Head);
                break;
            case 3:
                getchar();
                AppendInput(Head);
                break;
            case 4:
                getchar();
                Head = Kill(Head);
                break;
            default:
                operation = -1;
                break;
        }
    }

    SaveBD(Head, BD);

    FreeList(Head);

    fclose(BD);

    return 1;
}