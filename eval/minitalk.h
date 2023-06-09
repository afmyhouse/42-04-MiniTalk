/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoda-s <antoda-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 14:47:54 by antoda-s          #+#    #+#             */
/*   Updated: 2023/05/31 09:20:54 by antoda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>
# include <unistd.h>
# include <sys/types.h>
# include "libft/libft.h"

# define RED "\033[0;31m"
# define GRN "\033[0;32m"
# define YLW "\033[0;33m"
# define WTH "\033[0m"
# define PPL "\033[0;35m"

/*void	msg_rx(char *c, int *received, int *client_pid, int *bit);
void	signal_handler(int signium, siginfo_t *info, void *context);
void	signal_error(void);
void	char_to_signals(unsigned char c, int pid);
void	sent_text(char *str, int pid);
void	signal_rx(int sig);*/

#endif
