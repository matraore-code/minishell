#include "minishell.h"

int	get_cwd(char **cwd)
{
	char	buf[PATH_MAX];

	*cwd = getcwd(buf, PATH_MAX);
	return (1);
}