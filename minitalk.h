/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hajmoham <hajmoham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 15:27:37 by hajmoham          #+#    #+#             */
/*   Updated: 2025/01/26 18:11:26 by hajmoham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <ctype.h>
# include <limits.h>
# include <signal.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdint.h>
# include <stdio.h>
# include <stddef.h>
# include "Printf/ft_printf.h"

void    handle_signal(int sig);
void    send_char(int pid, char c);
int     ft_atoi(const char *str);
void	ft_putstr_fd(char *s, int fd);
void	ft_putchar_fd(char c, int fd);
void	ft_putnbr_fd(int n, int fd);

#endif
