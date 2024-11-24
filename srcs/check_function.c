# include "minishell.h"

// Fc return (-1) if string has only spaces or tabs..etc
int	check_only_spaces(char *str)
{
	int	i;
	int	x;

	i = -1;
	x = 0;
	while (str[++i])
	{
		if (str[i] == '\n' || str[i] == '\t' || str[i] == '\v' 
				|| str[i] == '\f' || str[i] == '\r' || str[i] == ' ')
			x++;
	}
	if (i == x)
		return (-1);
	return (0);
}
