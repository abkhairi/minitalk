/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abkhairi <abkhairi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 15:42:33 by abkhairi          #+#    #+#             */
/*   Updated: 2023/08/31 16:26:18 by abkhairi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>
# include "../finalprintf/ft_printf.h"

void	ft_putchar_fd(char c, int fd);
size_t	ft_strlen(const char *str);
char	ft_binarytochar(char *bits);
void	ft_bzero(void *s, size_t n);

#endif