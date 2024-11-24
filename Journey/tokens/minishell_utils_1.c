# include "minishell.h"

/* Safe_malloc
    
    Es una funcion general para alojar
    memoria para diferentes tipos de variables
    o estructuras.

    Retorna un puntero a un espacio en la memoria
    almacenado.

*/
void*   safe_malloc(size_t size)
{
    void* ptr = malloc(size);
    if (!ptr)
    {
        printf("error de safe malloc\n");
        exit(EXIT_FAILURE);
    }
    return (ptr);
}

void    free_minishell(t_token* tokens, char* input)
{
    int i;

    i = -1;
    if (tokens) 
    {
        while (tokens[++i].token != NULL)
            free (tokens[i].token);
        free (tokens);
    }
    if (input)
    {
        free (input);
    }
    return ;
}