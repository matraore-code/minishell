#include "minishell.h"

int		ft_env(char **args)
{
	t_env	*tmp;

	(void)args;
	tmp = g_env;
	while (tmp)
	{
		ft_putstr_fd(tmp->name, 1);
		ft_putstr_fd("=", 1);
		ft_putstr_fd(tmp->value, 1);
		ft_putstr_fd("\n", 1);
		tmp = tmp->next;
	}
	return (0);
}