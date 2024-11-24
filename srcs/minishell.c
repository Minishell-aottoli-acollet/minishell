# include "minishell.h"

t_minish t_minishell;

static void minishell_loop(void)
{

	while (1)
	{
		t_minishell.input = readline("minishell> ");
		if (!t_minishell.input)
			return ; // ToDo-> ft_errors;
		if (!ft_strcmp(t_minishell.input, "exit"))
		{
			return ;
		}
		if ((check_only_spaces(t_minishell.input) == -1 || t_minishell.input[0] == '\0'))
		{
			free(t_minishell.input);
		}
		else
		{
			add_history(t_minishell.input);
			t_minishell.tokens = tokenize();
		}	
	}
}

int	main(int as, char **av, char **envp)
{
	(void)av;
	(void)envp;

	if (1 != as)
		return (2); //hacer mensaje de error o constante
	print_msg();
	minishell_loop();
	return (0);
}
