/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abkhairi <abkhairi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 15:42:11 by abkhairi          #+#    #+#             */
/*   Updated: 2023/08/31 16:26:27 by abkhairi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	ft_remplir_bits(int signum, char *tab, int *i)
{
	if (signum == SIGUSR1)
	{
		tab[*i] = '0';
		(*i)++;
	}
	else if (signum == SIGUSR2)
	{
		tab[*i] = '1';
		(*i)++;
	}
}

static void	ft_sig_handler(int signum, siginfo_t *info, void *context)
{
	static char	tab[9];
	static int	i;
	static int	prec_pid;

	(void)context;
	if (prec_pid > 0 && prec_pid != info->si_pid)
	{
		i = 0;
		ft_bzero(tab, 8);
	}
	ft_remplir_bits(signum, tab, &i);
	if (i == 8)
	{
		tab[i] = '\0';
		ft_putchar_fd(ft_binarytochar(tab), 1);
		i = 0;
	}
	prec_pid = (int)info->si_pid;
}

int	main(void)
{
	struct sigaction	sh;

	ft_printf("Server PID: %d\n", getpid());
	sh.sa_sigaction = ft_sig_handler;
	sh.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sh, NULL);
	sigaction(SIGUSR2, &sh, NULL);
	while (1)
	{
		usleep(5000);
	}
	return (0);
}
