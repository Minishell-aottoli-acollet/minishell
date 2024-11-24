# include "minishell.h"

static void minishell_loop(void)
{
	char*	input;
	t_token	*tokens;

	tokens = NULL;
	while (1)
	{
		input = readline("minishell> ");
		if (!input)
			return ;
		if (!ft_strcmp(input, "exit"))
		{
			free_minishell(tokens, input);
			return ;
		}
		if (!input_check_errors(input))
		{
			tokens = tokenize(input);
			for (int i = 0; tokens[i].token != NULL ; i++){
				printf("token %d ---> %s\n", i, tokens[i].token);
			}
				//parsing
		}
		else
			printf("minishell: %s: command not found\n", input);
		free (input);
	}
	free_minishell(tokens, input);
}

int	main(int as, char **av)
{
	(void)av;

	if (1 != as)
		return (2); //hacer mensaje de error o constante
	print_msg();
	minishell_loop();
	
	return (0);
}