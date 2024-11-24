/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtok.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleexcolleet <marvin@42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 19:52:28 by aleexcolleet      #+#    #+#             */
/*   Updated: 2024/11/06 19:52:31 by aleexcolleet     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
# include "libft.h"

/*  this function applied to 42 is used to divide a string 
    in parts(tokens).
    Each time if finds a delimiter(" "), it cuts de string
    and returns a pointer to the start of the token which has 
    a '\0' at the end. 
    As the functions adds a '\0' to the end of each token on
    the same string, I can operate them as individuals and
    use ft_strlen and so...
*/
char *ft_strtok(char *str, const char *delim)
{
    static char *static_str;
    char *token_start;

    static_str = NULL;

    if (str != NULL)
        static_str = str;
    if (static_str == NULL)
        return NULL;
    while (*static_str && ft_strchr(delim, *static_str))
        static_str++;
    if (*static_str == '\0')
        return NULL;

    token_start = static_str;
    while (*static_str && !ft_strchr(delim, *static_str))
        static_str++;

    // Si hemos alcanzado un delimitador, lo reemplazamos por `\0` para finalizar el token
    if (*static_str != '\0')
    {
        *static_str = '\0';
        static_str++;
    }

    return (token_start);
}