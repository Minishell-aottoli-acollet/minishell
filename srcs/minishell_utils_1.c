# include "minishell.h"

void    *safe_malloc(size_t size)
{
    void* ptr = malloc(size);
    if (!ptr)
    {
        printf("error de safe malloc\n");
        exit(EXIT_FAILURE);
    }
    return (ptr);
}

void    free_minishell(char *input)
{
    if (input)
    {
        free (input);
    }
    return ;
}