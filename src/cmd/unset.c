#include "minishell.h"

int		ft_unset(char **args)
{
	t_env	*save;
	t_env	*prev;
	int		i;

	i = 1;
	save = g_env;
	while (args[i++] && !(prev = NULL))
	{
		g_env = save;
		while (g_env)
		{
			if (!ft_strcmp(g_env->name, args[i - 1]))
			{
				if (prev)
					prev->next = g_env->next;
				else
					save = g_env->next;
				free_env(g_env);
				break ;
			}
			prev = g_env;
			g_env = g_env->next;
		}
	}
	return (!(g_env = save));
}