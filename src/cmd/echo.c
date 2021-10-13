#include "minishell.h"

void	print_echo(char **args, int nl, int i)
{
	while (args[i])
	{
		ft_putstr(args[i]);
		if (args[++i])
			ft_putstr(" ");
	}
	if (nl)
		ft_putstr("\n");
}

int		ft_echo(char **args)
{
	int count;
	int nl;
	int i;

	count = 0;
	while (args[count])
		count++;
	if (count < 2)
	{
		ft_putstr("\n");
		return (0);
	}
	if (args[1][0] == '-' && ft_strncmp("-n", args[1], 3))
		return (1);
	nl = 1;
	i = 1;
	if (!ft_strncmp("-n", args[1], 3))
	{
		nl = 0;
		i = 2;
	}
	print_echo(args, nl, i);
	return (0);
}