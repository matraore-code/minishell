
#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <errno.h>
# include <dirent.h>
# include <sys/wait.h>
# include <signal.h>

typedef	struct		s_env
{
	char			*name;
	char			*value;
	struct s_env	*next;
}					t_env;

typedef struct s_list
{
    void *content;
    struct s_list *next;
}               t_list;

typedef struct s_token
{
    char *text;
    int    is_operator;
}   t_token;

extern t_env		*g_env;


void    ft_putstr(char *str);
void	ft_putchar(char c);
void	ft_putendl(char *str);
// int     get_cwd(char **cwd);


int		ft_strncmp(const char *s1, const char *s2, size_t n);

int		ft_echo(char **args);




#endif