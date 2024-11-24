#ifndef MINISHELL_H
#define MINISHELL_H

//LIBRARIES
# include "libft/libft.h"
# include "colors.h"
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <stdbool.h>
# include <fcntl.h>
# include <readline/readline.h>
# include <readline/history.h>

//STRUCTS

typedef struct s_token
{
    
    
}   t_token;

typedef struct	s_envp
{

}	t_envp;

typedef struct	s_minishell
{
	char	*input;
	t_envp	*envp;
	t_token	*tokens;

}   t_minish;
extern t_minish	t_minishell;

/*Functions*/
void        print_msg(void);
int			check_only_spaces(char *str);
t_token		*tokenize(void);
void		*safe_malloc(size_t size);
void        free_minishell(char* input);

#endif
