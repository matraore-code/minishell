#include "minishell.h"

int		ft_pwd(char **args)
{
	char *path;

	(void)args;
	path = getcwd(NULL, 0);
	if (path == NULL)
		return (1);
	ft_putendl(path);
	free(path);
	return (0);
}