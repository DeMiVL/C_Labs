#include <stdio.h>
#include <string.h>
#include <stdlib.h>


struct node
{
    // element settings:
    int         year;
    char*       Title;
    char*       Director;
    char*       Country;
    char*       Actors;

    // list settings:
    int         number;
    struct node* next;
    struct node* prev;
};

struct node *KillHead(struct node *head);
struct node *KillbyName(struct node *head, char name[]);
void KillTail(struct node *head);
struct node *NewMovie(char title[], char director[], char country[], char actr[], int year);
void Append(struct node *head, char title[], char director[], char country[], char actr[], int year);
struct node *FreeList(struct node *head);

struct node *NewMovie(char title[], char director[], char country[], char actr[], int year)
{
    struct node *Movie1 = malloc(sizeof(struct node));
    Movie1->Actors      = actr;
    Movie1->Director    = director;
    Movie1->Country     = country;
    Movie1->Title       = title;
    Movie1->year        = year;
    Movie1->next        = NULL;
    Movie1->prev        = NULL;
    return Movie1;
}

void Append(struct node *head, char title[], char director[], char country[], char actr[], int year)
{
    struct node *Movie1 = malloc(sizeof(struct node));
    while(head->next != NULL)
    {
        head = head->next;
    }
    Movie1->Actors      = actr;
    Movie1->Director    = director;
    Movie1->Country     = country;
    Movie1->Title       = title;
    Movie1->year        = year;
    Movie1->next        = NULL;
    Movie1->prev        = head;
    head->next          = Movie1;
}

struct node *KillbyName(struct node *head, char name[])
{
    do
    {
        if (strcmp(head->Title, name) == 0)
        {
            if (head->next == NULL && head->prev ==NULL)
            {
                free(head);
                return NULL;
            }
            if (head->next == NULL)
            {
                head->prev->next = NULL;
                free(head);
            }
            if (head->prev == NULL)
            {
                return KillHead(head); 
            }

            head->prev->next = head->next;
            head = head->prev;
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
    free(head->prev);
    head->prev = NULL;
    return head;
}

void KillTail(struct node *head)
{
    while(head->next != NULL)
        head = head->next;
    //printf("%s\n", head->Actors);
    head = head->prev;
    free(head->next);
    head->next = NULL;
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
        free(head->next);
    }
    free(head);
    return NULL;
}

int main()
{
    struct node *Head = NewMovie("Django Unchained", "Quentin Tarantino", "USA", "Jamie Fox", 2012);
    Append(Head, "February", "Oz Perkins", "USA", "Emma Roberts", 2015);
    Append(Head, "Terminator 2: Judgment Day", "James Cameron", "USA", "Arnold Schwarzenegger", 1991);

    printf("%s - %s - %s\n", Head->Actors, Head->next->Actors, Head->next->next->Actors);

    /*Head =*/ KillTail(Head);
    printf("%s - %s\n", Head->Actors, Head->next->Actors);
    //KillTail(Head);

    FreeList(Head);

    return 1;
}