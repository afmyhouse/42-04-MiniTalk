/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_charjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoda-s <antoda-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 00:28:11 by antoda-s          #+#    #+#             */
/*   Updated: 2023/05/25 15:47:48 by antoda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "libft.h"
#include	<stdlib.h>
#include	<stdio.h>

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

/// @brief
/// @param s1
/// @param c
/// @return
char	*ft_charjoin(char const *s1, char const c)
{
	size_t	len;
	char	*dest;

	if (!s1 || !c)
		return (NULL);
	len = ft_strlen(s1)+sizeof(c)+1;
	dest = malloc(sizeof(char) * len);
	if (!dest)
		return (NULL);
	while (*s1)
	{
		*dest++ = *s1++;
	}
	*dest++ = c;
	*dest = '\0';
	dest -= (len - 1);
	return (dest);
}

int main(int ac, char** av)
{
	char*	res;

	if (ac == 3)
	{
		printf("1 - %s\n", av[1]);
		res = ft_charjoin(av[1], av[2][0]);
		printf("2 - %s\n", res);
		free (res);
	}
	else{
		printf(" Format input : executable string char");
	}
	return (0);

}
