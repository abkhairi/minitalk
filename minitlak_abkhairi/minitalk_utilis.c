/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_utilis.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abkhairi <abkhairi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 15:42:20 by abkhairi          #+#    #+#             */
/*   Updated: 2023/08/31 15:56:35 by abkhairi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

size_t	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

static int	ft_power(int a, int b)
{
	int	r;

	r = 1;
	while (b > 0)
	{
		r = r * a;
		b--;
	}
	return (r);
}

char	ft_binarytochar(char *bit)
{
	char	c;
	short	i;

	c = '\0';
	i = 7;
	while (*bit && i >= 0)
	{
		if (*bit == '1')
			c = c + (1 * (ft_power(2, i)));
		else if (*bit == '0')
			c = c + 0;
		i--;
		bit++;
	}
	return (c);
}

void	ft_bzero(void *s, size_t n)
{
	size_t	i;
	char	*p;

	i = 0;
	p = (char *)s;
	while (i < n)
	{
		p[i] = 0;
		i++;
	}
}
