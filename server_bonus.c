/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoda-s <antoda-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 14:51:49 by antoda-s          #+#    #+#             */
/*   Updated: 2023/05/18 14:51:51 by antoda-s         ###   ########.fr       */
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
