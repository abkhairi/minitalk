/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abkhairi <abkhairi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 15:41:59 by abkhairi          #+#    #+#             */
/*   Updated: 2023/08/31 15:54:52 by abkhairi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	ft_atoi(char *str)
{
	int	i;
	int	nombre;
	int	signe;

	signe = 1;
	nombre = 0;
	i = 0;
	while ((str[i] == 32) || (str[i] >= 9 && str[i] <= 13))
		i++;
	if ((str[i] == '-' || str[i] == '+') && (str[i] != '\0'))
	{
		if (str[i] == '-')
			signe *= -1;
		i++;
	}
	while ((str[i] >= '0' && str[i] <= '9') && (str[i] != '\0'))
	{
		nombre = nombre * 10 +(str[i] - '0');
		i++;
	}
	return (nombre * signe);
}

void	ft_send_sigusr(int pid, char *c)
{
	int	i;
	int	j;

	i = 0;
	while (c[i] != '\0')
	{
		j = 7;
		while (j >= 0)
		{
			if (((c[i] >> j) & 1) == 0)
				kill(pid, SIGUSR1);
			else if (((c[i] >> j) & 1) == 1)
				kill(pid, SIGUSR2);
			j--;
			usleep(800);
		}
		i++;
	}
}

int	main(int argc, char **argv)
{
	int	pid;

	if (argc == 3)
	{
		pid = ft_atoi(argv[1]);
		if (pid > 0)
			ft_send_sigusr(pid, argv[2]);
		else
		{
			ft_printf("The server PID is not valid");
			exit(1);
		}
	}
	else 
	{
		ft_printf("les argc incomplete");
		exit(1);
	}
}
