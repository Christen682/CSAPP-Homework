#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TSIZE 45 // size of array to store film title

typedef struct film
{
    char title[TSIZE];
    int rating;
} Film;

char *s_gets(char *st, int n);

int main()
{
    int i = 0, n = 0;
    Film *movies;
    puts("Enter the maximum number of movies u wish to enter:");
    scanf("%d", &n);
    getchar();
    movies = (Film *)malloc(n * sizeof(Film));
    if (movies == NULL)
    {
        fprintf(stderr, "Memory allocation failed.\n");
        return 1;
    }

    puts("Enter first movie title:");
    while (i < n && s_gets(movies[i].title, TSIZE) != NULL && movies[i].title[0] != '\0')
    {
        puts("Enter your rating <0-10>:");
        scanf("%d", &movies[i].rating);
        while (getchar() != '\n')
            continue;
        puts("Enter next movie title (empty line to stop):");
        i++;
    }

    if (i == 0)
        printf("No data entered.");
    else
    {
        printf("Here is the movie list:\n");
        for (int j = 0; j < i; j++)
            printf("Movies: %s and Rating: %d\n", movies[j].title, movies[j].rating);
    }
    printf("You entered %d movies.\n", i);
    free(movies);

    return 0;
}

// safe input
char *s_gets(char *st, int n)
{
    char *ret_val;
    char *find;

    ret_val = fgets(st, n, stdin);
    if (ret_val)
    {
        find = strchr(st, '\n');
        *find = '\0';
    }
    else
    {
        while (getchar() != '\n')
            continue;
    }
    return ret_val;
}