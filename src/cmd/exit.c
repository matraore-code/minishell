#include "minishell.h"

int		ft_exit(char **args)
{
	(void)args;
    // I have to free all environement stuffs
	ft_putstr_fd("exit\n", 1);
	exit(0);
}