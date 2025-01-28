/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hajmoham <hajmoham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 09:47:21 by hajmoham          #+#    #+#             */
/*   Updated: 2025/01/28 16:39:54 by hajmoham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void send_char(int pid, char c)
{
	int	bit;

	bit = 0;
	while (bit < 8)
	{
		if ((c & (1 << bit)))
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(100);
		bit++;
	}
}

int main(int ac, char **av)
{
    int i;
    int pid;

    if (ac == 3)
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
    return 0;
}

