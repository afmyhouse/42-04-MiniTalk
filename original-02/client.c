/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoda-s <antoda-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 17:43:42 by aymoulou          #+#    #+#             */
/*   Updated: 2023/05/30 00:27:55 by antoda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	char_to_signals(unsigned char c, int pid)
{
	int	bit;

	bit = 0;
	while (bit < 8)
	{
		if (c & 128)
		{
			if (kill(pid, SIGUSR1) == -1)
			{
				ft_printf("\n%sError transmiting!.%s\n", RED, WTH);
				exit(1);
			}
		}
		else
		{
			if (kill(pid, SIGUSR2) == -1)
			{
				ft_printf("\n%sError transmiting!.%s\n", RED, WTH);
				exit(1);
			}
		}
		c <<= 1;
		bit++;
		pause();
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
	if (sig == SIGUSR1)
	{
		ft_printf("%sMESSAGE : transmitted%s\n", GRN, WTH);
		exit(0);
	}
}

int	main(int ac, char **av)
{
	int	server_pid;

	if (ac == 3)
	{
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
