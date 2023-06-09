/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoda-s <antoda-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 17:43:42 by aymoulou          #+#    #+#             */
/*   Updated: 2023/05/30 01:26:19 by antoda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	signal_error(void)
{
	ft_printf("\n%sError transmiting!.%s\n", RED, WTH);
	exit(1);
}

void	char_to_signals(unsigned char c, int pid)
{
	int	bit;

	bit = 0;
	while (bit < 8)
	{
		if (c & 128)
		{
			if (kill(pid, SIGUSR1) == -1)
				signal_error();
		}
		else
		{
			if (kill(pid, SIGUSR2) == -1)
				signal_error();
		}
		c <<= 1;
		bit++;
		pause();
		usleep(50);
	}
}

void	sent_text(char *str, int pid)
{
	while (*str)
		char_to_signals(*str++, pid);
	char_to_signals('\0', pid);
}

void	signal_rx(int sig)
{
	static int	sent;
	int			sent_chars;

	if (sig == SIGUSR1)
	{
		sent_chars = sent / 8 + 1;
		ft_printf("%s%d Characters sent to SERVER %s\n", GRN, sent_chars, WTH);
		exit(0);
	}
	if (sig == SIGUSR2)
		++sent;
}

int	main(int ac, char **av)
{
	int	server_pid;
	int	client_pid;

	client_pid = getpid();
	if (ac == 3)
	{
		ft_printf("%sCLIENT PID: %d%s\n", RED, client_pid, WTH);
		signal(SIGUSR1, signal_rx);
		signal(SIGUSR2, signal_rx);
		server_pid = ft_atoi(av[1]);
		ft_printf("%sMESSAGE : transmitting... %s\n", YLW, WTH);
		sent_text(av[2], server_pid);
	}
	else
		ft_printf("%sArguments? -> ./client server_pid \"text to send\"%s\n",
			RED, WTH);
	return (1);
}
