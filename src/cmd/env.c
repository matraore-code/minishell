#include "minishell.h"



int		ft_env(char **args)
{
	t_env	*tmp;

	(void)args;
	tmp = g_env;
	while (tmp)
	{
		ft_putstr(tmp->name);
		ft_putstr("=");
		ft_putstr(tmp->value);
		ft_putstr("\n");
		tmp = tmp->next;
	}
	return (0);
}