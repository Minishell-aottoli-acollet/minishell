# include "minishell.h"


t_token *tokenize(void)
{
	char	*input_tmp;
	t_token	*tokens_input;

	input_tmp = t_minishell.input;
	tokens_input = handler_tokenize(input_tmp);
	return (tokens_input);

}
