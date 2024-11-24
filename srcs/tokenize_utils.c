# include "minishell.h"

void	skip_spaces(char **input)
{
	while (**input && ft_isspace(**input))
		(*input)++;
}

int	is_separator(char **c)
{
	if (c == '|' || c == '&' || c == ';' || c == '(' 
			|| c == ')' || c == '<' || c == '>')
		return (1);
	return (0);
}
