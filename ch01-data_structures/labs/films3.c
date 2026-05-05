/*Compiled with list.c*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"
void showmovies(Item item);
char *s_gets(char *st, int n);

int main(void)
{
    List movies;
    Item temp;

    /*initialize the list*/
    InitializeList(&movies);
    if (ListIsFull(&movies))
    {
        fprintf(stderr, "No memory available!");
        exit(1);
    }

    /*capture the input and store*/
    puts("Enter first movie title:");
    while (s_gets(temp.title, TSIZE) && temp.title[0] != '\0')
    {
        puts("Enter your rating:");
        scanf("%d", &temp.rating);
        while (getchar() != '\n')
            continue;

        if (AddItem(temp, &movies) == false)
        {
            fprintf(stderr, "Problem allocating memory\n");
            break;
        }
        if (ListIsFull(&movies))
        {
            fprintf(stderr, "The list is full now.");
            break;
        }
        puts("Enter the next movie:");
    }

    /*show the list*/
    if (ListIsEmpty(&movies))
        printf("No data memorized.\n");
    else
    {
        printf("Below is the list:\n");
        Traverse(&movies, showmovies);
    }
    printf("\nYou entered %d movies.\n", ListItemCount(&movies));

    /*clean the list*/
    EmptyTheList(&movies);
    printf("Bye\n");

    return 0;
}

void showmovies(Item item)
{
    printf("Movie: %s ; Rating: %d\n", item.title, item.rating);
}

char *s_gets(char *st, int n)
{
    char *ret_val;
    char *find;
    ret_val = fgets(st, n, stdin);
    if (ret_val)
    {
        find = strchr(st, '\n');
        if (find)
            *find = '\0';
        else
            while (getchar() != '\n')
                continue;
    }

    return ret_val;
}