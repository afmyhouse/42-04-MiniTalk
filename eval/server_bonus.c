/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoda-s <antoda-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 14:51:39 by antoda-s          #+#    #+#             */
/*   Updated: 2023/05/30 16:23:39 by antoda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	msg_rx(char *c, int *char_rx, int *cli_pid, int *bit)
{
	ft_putchar_fd(*c, 1);
	*char_rx += 1;
	if (*c == '\0')
	{
		ft_printf("\n%s%d Characters received from CLIENT PID: %d%s\n",
			GRN, *char_rx, *cli_pid, WTH);
		*char_rx = 0;
		*c = 0;
		if (kill(*cli_pid, SIGUSR1) == -1)
		{
			ft_printf("\n%sserver: unexpected error.%s\n", RED, WTH);
			exit(1);
		}
		return ;
	}
	*bit = 0;
}

void	signal_handler(int signium, siginfo_t *info, void *context)
{
	static int	cli_pid;
	static int	cur_pid;
	static int	bit;
	static char	c;
	static int	char_rx;

	(void)context;
	cur_pid = info->si_pid;
	if (!cli_pid)
		cli_pid = cur_pid;
	if (cli_pid != cur_pid)
	{
		cli_pid = cur_pid;
		bit = 0;
		c = 0;
		char_rx = 0;
	}
	c |= (signium == SIGUSR1);
	bit++;
	if (bit == 8)
		msg_rx(&c, &char_rx, &cli_pid, &bit);
	c <<= 1;
	usleep(50);
	kill(cli_pid, SIGUSR2);
}

int	main(void)
{
	pid_t				srv_pid;
	struct sigaction	sig_act;

	srv_pid = getpid();
	ft_printf("SERVER PID = %d\n", srv_pid);
	sig_act.sa_sigaction = signal_handler;
	sigemptyset(&sig_act.sa_mask);
	sig_act.sa_flags = SA_SIGINFO;
	while (1)
	{
		if (sigaction(SIGUSR1, &sig_act, NULL) == -1)
			ft_printf("Error SIGUSR1");
		if (sigaction(SIGUSR2, &sig_act, NULL) == -1)
			ft_printf("Error SIGUSR2");
		pause();
	}
	return (0);
}
