#include "shell.h"

void	catch_int(int sig)
{
	(void)sig;
	rl_replace_line("", 0);
	printf("\n");
	rl_on_new_line();
	rl_redisplay(); //affiche prompt
}

void	catch_quit(int sig)
{
	(void)sig;
	rl_on_new_line();
	rl_redisplay(); //affiche prompt

}

int	main(int ac, char **av)
{
	char	*cmdline;
	pid_t	id_child;
	struct	termios term;
	struct	termios init;

	(void)*av;
	if (ac == -1)
		exit(1);
	char *arg[] = {"echo", "-n", "hey", NULL};	

	signal(SIGINT, catch_int);
	signal(SIGQUIT, catch_quit);

	if (tcgetattr(0, &term) == -1)
		return (-1);
	if (tcgetattr(0, &init) == -1)
		return(-1);
	while(1)
	{
		term.c_lflag &= ~(ECHOCTL);
		if (tcsetattr(0, TCSANOW, &term) == -1)
			return (-1);
		char	*term_type = getenv("TERM");
		int		ret = tgetent(NULL, term_type);
		
		tputs(tgetstr("sc", NULL), 1, putchar);

		cmdline = readline("$ ");

		if (!cmdline)
		{
		
			if (ret == -1 || ret == 0)
				printf("NULL\n");	
			tputs(tgoto(tgetstr("rc", NULL), 1, 1), 1, putchar);	
			rl_on_new_line();
			rl_redisplay();
			printf("exit\n");
			exit(1);
		}

		if (cmdline[0] != '\0')
		{
			add_history(cmdline);
			id_child = fork();
			if (id_child == 0)
				execve("/bin/echo", arg, NULL);
			wait(NULL);
		}
		if (cmdline)
			free(cmdline);
		if(tcsetattr(0, TCSANOW, &init) == -1)
			return (-1);
	}
	rl_clear_history();
	return(0);
}
