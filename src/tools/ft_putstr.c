#include "../../include/minishell.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}


void ft_putstr(char *str)
{
    int i;

	i = 0;
	if (!str)
		return ;
	while (str[i])
		i++;
	write(1, str, i);
}


void	ft_putendl(char *str)
{
	int i;

	i = 0;
	if (!str)
		return ;
	while (str[i])
		i++;
	write(1, str, i);
	write(1, "\n", 1);
}