/*linked list*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TSIZE 45
struct film
{
    char title[TSIZE];
    int rating;
    struct film *next;
};

char *s_gets(char *st, int n);

int main()
{
    struct film *head = NULL;
    struct film *prev, *current;
    char input[TSIZE];

    // Gather and store information.
    puts("Enter first movie title:");
    while (s_gets(input, TSIZE) && input[0] != '\0')
    {
        current = (struct film *)malloc(sizeof(struct film));
        if (!(current))
        {
            fprintf(stderr, "Malloc Failed");
            return 1;
        }
        if (head == NULL)
            head = current;
        else
            prev->next = current;
        current->next = NULL;

        strcpy(current->title, input); // copy the input to title
        puts("Please rating :");
        scanf("%d", &current->rating);
        while (getchar() != '\n')
            continue;

        puts("Enter next movie title (empty line to stop):");
        prev = current;
    }

    // Display the list.
    if (head == NULL)
        printf("No data entered. ");
    else
        printf("Here is the movie list:\n");
    current = head;
    while (current != NULL)
    {
        printf("Movies: %s, Rating: %d\n", current->title, current->rating);
        current = current->next;
    }

    // Release the malloced memory
    current = head;
    while (current)
    {
        head = current->next;
        free(current);
        current = head;
    }
    puts("Bye\n");

    return 0;
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