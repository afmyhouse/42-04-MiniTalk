/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoda-s <antoda-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 14:51:49 by antoda-s          #+#    #+#             */
/*   Updated: 2023/05/25 16:38:07 by antoda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	handler_signals(int signal, siginfo_t *info, void *ucontent)
{
	static int				i = 0;
	static pid_t			client_pid = 0;
	static unsigned char	c = 0;

	(void)ucontent;
	if (!client_pid)
		client_pid = info->si_pid;
	if (signal == SIGUSR1)
		c |= 1;
	i++;
	if (i == 8)
	{
		i = 0;
		if (!c)
		{
			kill(client_pid, SIGUSR1);
			client_pid = 0;
			return ;
		}
		ft_putchar_fd(c, 1);
		c = 0;
		kill(client_pid, SIGUSR2);
	}
	else
		c = c << 1;
}

void	config_signals(void)
{
	struct sigaction	sigact;

	sigact.sa_sigaction = &handler_signals;
	sigact.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sigact, 0);
	sigaction(SIGUSR2, &sigact, 0);
	if (sigaction(SIGUSR1, &sigact, NULL) == -1)
		ft_printf("Error SIGUSR1");
	if (sigaction(SIGUSR2, &sigact, NULL) == -1)
		ft_printf("Error SIGUSR2");
}
void	msg_tx_2_pid(pid_t pid, char *msg)
{
	unsigned char	c;
	int				bit;

	while (*msg)
	{
		c = *msg;
		bit = 8;
		while (bit > 0)
		{
			if (c & 0b00000001)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			c = c >> 1;
			bit--;
			usleep(100);
		}
		msg++;
	}
}

int	main(int argc, char **argv)
{
	pid_t		pid;
	char		*msg;

	if (argc != 3)
	{
		ft_printf("invalid arguments");
		return (0);
	}
	pid = ft_atoi(argv[1]);
	msg = argv[2];
	msg_tx_2_pid(pid, msg);
	return (0);
}


int	main(void)
{
	pid_t	pid;

	pid = getpid();
	ft_printf("PID = %d\n", pid);
	config_signals();
	while (1)
		pause();
	return (0);
}
