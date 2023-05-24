/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoda-s <antoda-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 14:51:39 by antoda-s          #+#    #+#             */
/*   Updated: 2023/05/18 18:04:33 by antoda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include "libft/libft.h"
#include <sys/types.h>
#include <signal.h>

void	original_handler(int signal)
{
	static int	i = 0;
	static char	c = 0;

	if (signal == SIGUSR1)
		c |= (1 << i);
	i++;
	if (i == 8)
	{
		ft_putchar_fd(c, 1);

		c = 0;
		i = 0;
	}
}

/*void	handler(int signal)
{
	static int	i = 0;
	static char	c = 0;
	static char *str;
	static char *tmp;
	static int	char_counter = 1;

	if (signal == SIGUSR1)
		c |= (1 << i);
	i++;
	if (i == 8)
	{

		i = 0;
		str = (char *)malloc(sizeof(char) * char_counter + 1);
		str[char_counter] = '\0';
		while (i <= char_counter)
		{
			str[i] = tmp[i];
			i++;
		}
		free(tmp);
		tmp = str;
		str[i] = c;
		if (c != '\n')
		{
			ft_printf("%s", str);
			free(str);
			char_counter = 0;
		}
		else
			char_counter++;
		c = 0;
		i = 0;
	}
}
*/
void	config_signals(void)
{
	struct sigaction	newDisp;
	struct sigaction	prevDisp;

	newDisp.sa_handler = &handler;
	newDisp.sa_flags = SA_SIGINFO;
	if (sigaction(SIGUSR1, &newDisp, &prevDisp) == -1)
		ft_printf("Error SIGUSR1");
	if (sigaction(SIGUSR2, &newDisp, &prevDisp) == -1)
		ft_printf("Error SIGUSR2");
}

int	main(void)
{
	pid_t	pid;

	pid = getpid();
	ft_printf("PID = %d\n", pid);
	ft_printf("SIGUSR1C = %c\n", SIGUSR1);
	ft_printf("SIGUSR2C = %c\n", SIGUSR2);

	config_signals();
	while (1)
		pause();
	return (0);
}
