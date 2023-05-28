/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putaddr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aymoulou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 19:09:04 by aymoulou          #+#    #+#             */
/*   Updated: 2021/12/18 19:09:08 by aymoulou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	hex_len(unsigned long int n)
{
	int	i;

	i = 0;
	if (!n)
		i++;
	while (n)
	{
		n /= 16;
		i++;
	}
	return (i);
}

static int	ft_putaddr_hex(unsigned long int nbr, char Xx)
{
	unsigned long int	base_len;
	char				*base;

	base_len = 16;
	if (Xx == 'x')
		base = "0123456789abcdef";
	else
		base = "0123456789ABCDEF";
	if (nbr < base_len)
		ft_putchar(base[nbr % base_len]);
	else
	{
		ft_putaddr_hex(nbr / base_len, Xx);
		ft_putaddr_hex(nbr % base_len, Xx);
	}
	return (hex_len(nbr));
}

int	ft_putaddr(void *addr)
{
	unsigned long int	ptr;

	ptr = (unsigned long int)addr;
	ft_putstr("0x");
	return (ft_putaddr_hex(ptr, 'x') + 2);
}
