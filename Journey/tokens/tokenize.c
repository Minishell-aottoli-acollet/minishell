# include "../includes/minishell.h"

/*Count_tokens

    Se encarga de contar cuantos tokens
    van a haber a partir del input.
    Retorna un integer con el valor

*/
int count_tokens(char* input)
{
    int i = -1;
    int count = 0;
    bool on_token = false;
    
    while (input[++i] != 0)
    {
        if (input[i] == ' ')
        {
            on_token = false;
        }
        else
        {
            if (!on_token)
            {
                count++;
                on_token = true;
            }
        }
    }
    return (count);

}

/*tokenize functin:

    va a retornar la estructura modificada
    (desde espacio en la memoria &) con los tokens
    alojados con maloc, arreglados(evitar espacios...).
    
    1. Usa safe_malloc para alojar tantos t_token como tokens 
    haya que almacenar.
    2. La funcion ft_strtok se encarga en la primera llamada
    de poner un '\0' al final de cada token. De forma que
    con un solo string, podemos identificar el principio i final
    de cada token con un ft_strtok(NULL, " ");

*/ 
t_token*    tokenize(char *input)
{
    int         token_count = 0;
    t_token*    tokens;
    int         i;
    char        *token;
    size_t      token_size;

    i = 0;
    token_size = 0;
    token_count = count_tokens(input);
    tokens = (t_token *)safe_malloc(sizeof(t_token) * token_count + 1);
    token = ft_strtok(input, " ");
    

    while (token != NULL && i < token_count)
    {
        token_size = ft_strlen(token);
        tokens[i].token = (char *)safe_malloc(token_size + 1);
        ft_strlcpy(tokens[i].token, token, token_size + 1);
        tokens[i].j = i;
        token = ft_strtok(NULL, " ");
        i++;
    }
    tokens[i].token = NULL;
    return (tokens);
}