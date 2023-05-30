/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoda-s <antoda-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 14:47:10 by antoda-s          #+#    #+#             */
/*   Updated: 2023/05/28 21:38:56 by antoda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_msg(pid_t pid, char *msg)
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
			usleep(300);
		}
		msg++;
	}
	if (!*msg)
	{
		bit = 8;
		while (bit > 0)
		{
			kill(pid, SIGUSR2);
			bit--;
			usleep(300);
		}
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
	send_msg(pid, msg);
	return (0);
}
