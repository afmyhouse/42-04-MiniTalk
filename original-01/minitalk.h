/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoda-s <antoda-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 14:47:54 by antoda-s          #+#    #+#             */
/*   Updated: 2023/05/29 00:34:52 by antoda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>
# include <unistd.h>
# include "libft/libft.h"

# define RED "\033[0;31m"
# define GREEN "\033[0;32m"
# define YELLOW "\033[0;33m"
# define END_COLOR "\033[0m"
# define PURPLE "\033[0;35m"

/*void	msg_rx(char *c, int *received, int *client_pid, int *bit);
void	signal_handler(int signium, siginfo_t *info, void *context);
void	signal_error(void);
void	char_to_bin(unsigned char c, int pid);
void	sent_text(char *str, int pid);
void	signal_rx(int sig);*/

#endif
