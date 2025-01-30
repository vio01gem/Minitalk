/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hajmoham <hajmoham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 09:47:21 by hajmoham          #+#    #+#             */
/*   Updated: 2025/01/30 13:17:22 by hajmoham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	ft_atoi(const char *str)
{
	unsigned long long	nb;
	int					sign;
	int					i;

	sign = 1;
	nb = 0;
	i = 0;
	while (str[i] == ' ' || (str[i] >= '\t' && str[i] <= '\r'))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		nb = nb * 10 + str[i] - '0';
		if (sign == -1 && nb >= LLONG_MAX)
			return (0);
		if (nb >= LLONG_MAX)
			return (-1);
		i++;
	}
	return (sign * nb);
}

void	send_char(int pid, char c)
{
	int	bit;

	bit = 0;
	while (bit < 8)
	{
		if ((c & (1 << bit)))
		{
			if (kill(pid, SIGUSR1) == -1)
			{
				ft_printf("Invalid PID");
				exit(1);
			}
		}
		else
		{
			if (kill(pid, SIGUSR2) == -1)
			{
				ft_printf("Invalid PID");
				exit(1);
			}
		}
		usleep(200);
		bit++;
	}
}

int	main(int ac, char **av)
{
	int	i;
	int	pid;

	if (ac == 3 && av[1][0] != '\0')
	{
		pid = ft_atoi(av[1]);
		i = 0;
		while (av[2][i] != '\0')
		{
			send_char(pid, av[2][i]);
			i++;
		}
		send_char(pid, '\0');
	}
	else
		return ((void)ft_printf("Valid format: ./client <PID> <Message>\n"), 1);
	return (0);
}
