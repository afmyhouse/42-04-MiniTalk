/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_server.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoda-s <antoda-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 17:43:52 by aymoulou          #+#    #+#             */
/*   Updated: 2023/05/30 01:13:52 by antoda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minitalk.h"

void	display_banner(int pid)
{
	ft_printf("\n\t%s███╗   ███╗██╗███╗   ██╗██╗ ████████╗ █████╗ ██╗     ██╗██╗%s", YELLOW, END);
	ft_printf("\n\t%s██╔████╔██║██║██╔██╗ ██║██║    ██║   ███████║██║     █████╔╝%s", YELLOW, END);
	ft_printf("\n\t%s██║╚██╔╝██║██║██║╚██╗██║██║    ██║   ██╔══██║██║     ██╔═██╗%s", YELLOW, END);
	ft_printf("\n\t%s██║ ╚═╝ ██║██║██║ ╚████║██║    ██║   ██║  ██║███████╗██║  ██╗%s", YELLOW, END);
	ft_printf("\n\t%s╚═╝     ╚═╝╚═╝╚═╝  ╚═══╝╚═╝    ╚═╝   ╚═╝  ╚═╝╚══════╝╚═╝  ╚═╝%s", YELLOW, END);
	ft_printf("\n%s\n\t\tPID: %d%s\t\t\t%sBy: aymoulou%s\n", RD, pid, END,YELLOW, END);
	ft_printf("\n\t⊱ ────────────────────── {.⋅ ✯ ⋅.} ─────────────────────── ⊰\
			\n\n");
}

void	signal_error(void)
{
	ft_printf("\n%sserver: unexpected error.%s\n", RD, END);
	exit(EXIT_FAILURE);
}

void	extended_action(char *c, int *received, int *client_pid, int *bit)
{
	ft_printf("%c", *c);
	if (*c == '\0')
	{
		ft_printf("\n%s%d signal recieved from client PID: %d%s\n",
			GREEN, *received, *client_pid, END);
		*received = 0;
		*c = 0;
		if (kill(*client_pid, SIGUSR1) == -1)
			signal_error();
		return ;
	}
	*bit = 0;
}

void	action(int signium, siginfo_t *info, void *context)
{
	static int	client_pid;
	static int	bit;
	static char	c;
	static int	received;
	static int	current_pid;

	(void)context;
	if (!client_pid)
		client_pid = info->si_pid;
	current_pid = info->si_pid;
	if (client_pid != current_pid)
	{
		client_pid = current_pid;
		bit = 0;
		c = 0;
		received = 0;
	}
	c |= (signium == SIGUSR2);
	received++;
	bit++;
	if (bit == 8)
		extended_action(&c, &received, &client_pid, &bit);
	c <<= 1;
	usleep(100);
	kill(client_pid, SIGUSR2);
}

int	main(void)
{
	int					pid;
	struct sigaction	act;

	pid = getpid();
	display_banner(pid);

	act.sa_sigaction = action;
	sigemptyset(&act.sa_mask);
	act.sa_flags = SA_SIGINFO;
	while (1)
	{
		sigaction(SIGUSR1, &act, 0);
		sigaction(SIGUSR2, &act, 0);
		pause();
	}
	return (EXIT_FAILURE);
}
