/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoda-s <antoda-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 14:51:39 by antoda-s          #+#    #+#             */
/*   Updated: 2023/05/28 21:47:38 by antoda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include <stdio.h>

void	msg_rx(unsigned char c)
{
	static char	*msg;
	static char	*tmp;

	if (!c)
	{
		ft_putstr_fd(msg, 1);
		if (msg)
		{
			free (msg);
			msg = NULL;
		}
	}
	else
	{
		tmp = msg;
		msg = ft_charjoin(msg, c);
		if (tmp)
			free (tmp);
	}
}

void	handler_signals(int signal)
{
	static int		i = 0;
	static char		c = 0;

	if (signal == SIGUSR1)
		c |= (1 << i);
	i++;
	if (i == 8)
	{
		msg_rx(c);
		c = 0;
		i = 0;
	}
}

void	config_signals(void)
{
	struct sigaction	sigact;

	sigact.sa_handler = &handler_signals;
	sigact.sa_flags = SA_SIGINFO;
	if (sigaction(SIGUSR1, &sigact, NULL) == -1)
		ft_printf("Error SIGUSR1");
	if (sigaction(SIGUSR2, &sigact, NULL) == -1)
		ft_printf("Error SIGUSR2");
}

int	main(void)
{
	pid_t	pid;
	struct sigaction	sigact;

	pid = getpid();
	ft_printf("PID = %d\n", pid);

	
	config_signals();
	while (1)
		pause();
	return (0);
}
