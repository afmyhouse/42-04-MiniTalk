/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_client.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoda-s <antoda-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 14:51:39 by antoda-s          #+#    #+#             */
/*   Updated: 2023/05/25 16:37:01 by antoda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	msg_rcv(int signal)
{
	static int		i = 0;
	static char		c = 0;
	static char*	msg;
	static char*	tmp;
	while (c)
	{
		if (signal == SIGUSR1)
			c |= (1 << i);
		i++;
		if (i == 8)
		{
			if (!c)
				break;
			tmp  = msg;
			msg = *ft_charjoin(msg, c);
			free (tmp);
			c = 0;
			i = 0;
		}
	}
	ft_putstr_fd(msg, 1);
	free (msg);
	return ;
}

int	main(void)
{
	pid_t	pid;

	pid = getpid();
	ft_printf("PID = %d\n", pid);
	// usar estas 2 functions dentro do while
	signal(SIGUSR1,msg_rcv);
	signal(SIGUSR2,msg_rcv);
	while (1)
		pause();
	return (0);
}
