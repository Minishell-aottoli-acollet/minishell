# include "minishell.h"

t_minish msh;

static void minishell_loop(void)
{

	while (1)
	{
		msh.input = readline("minishell> ");
		if (!msh.input)
			return ; // ToDo-> ft_errors;
		if (!ft_strcmp(msh.input, "exit"))
		{
			return ;
		}
		if ((check_only_spaces(msh.input) == -1 || msh.input[0] == '\0'))
		{
			free(msh.input);
		}
		else
		{
			add_history(msh.input);
			if (tokenize(msh, &msh->cmd, msh.input) && msh.flags->quote != 0)
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
