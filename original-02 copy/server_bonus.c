/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoda-s <antoda-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 14:51:39 by antoda-s          #+#    #+#             */
/*   Updated: 2023/05/29 21:15:53 by antoda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include <stdio.h>

void	signal_error(void)
{
	ft_printf("\n%sserver: unexpected error.%s\n", RED, WTH);
	exit(1);
}

void	msg_rx(char *c, int *received, int *client_pid, int *bit)
{
	ft_putchar_fd(*c, 1);
	if (*c == '\0')
	{
		ft_printf("\n%s%d signal recieved from client PID: %d%s\n",
			GRN, *received, *client_pid, WTH);
		*received = 0;
		//*c = 0;
		if (kill(*client_pid, SIGUSR1) == -1)
			signal_error();
		return ;
	}
	*bit = 0;
}

void	signal_handler(int signium, siginfo_t *info, void *context)
{
	static int	client_pid;
	static int	bit;
	static char	c;
	static int	signal_rx;
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
		signal_rx = 0;
	}
	c |= (signium == SIGUSR2);
	signal_rx++;
	bit++;
	if (bit == 8)
		msg_rx(&c, &signal_rx, &client_pid, &bit);
	c <<= 1;
	usleep(50);
	kill(client_pid, SIGUSR2);
}

int	main(void)
{
	pid_t				pid;
	struct sigaction	sig_act;

	pid = getpid();
	ft_printf("SERVER PID = %d\n", pid);
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
