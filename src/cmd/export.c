#include "minishell.h"


char	*ft_strrchr(const char *s, int c)
{
	char *str;

	str = NULL;
	while (*s)
	{
		if (*s == c)
			str = (char *)s;
		s++;
	}
	if (c == '\0')
		return ((char *)s);
	return (str);
}


int		ft_isalnum(int c)
{
	if ((c < 48 || c > 57) && (c < 65 || c > 90) && (c < 97 || c > 122))
		return (0);
	return (1);
}

int		check_name(char *name)
{
	int j;

	j = 0;
	while (name[j])
	{
		if (!ft_isalnum((int)name[j]) && name[j] != '_')
		{
			ft_putstr("Invalid variable name\n");
			return (1);
		}
		j++;
	}
	return (0);
}

int		ft_export(char **args)
{
	int		i;
	char	*name;
	char	*value;

	i = 0;
	if (!args[1] || !ft_strrchr(args[1], (int)'='))
		return (1);
	while (args[1][i] && args[1][i] != '=')
		i++;
	name = ft_substr(args[1], 0, i);
	if (check_name(name))
	{
		free(name);
		return (1);
	}
	i++;
	value = ft_strdup(args[1] + i);
	// I have to create a function that will add to env variable ft_add_env;
	free(name);
	free(value);
	return (0);
}
