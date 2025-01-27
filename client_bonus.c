/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hajmoham <hajmoham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 12:07:28 by hajmoham          #+#    #+#             */
/*   Updated: 2025/01/27 12:25:33 by hajmoham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	msg_recieve(int signal)
{
	(void)signal;
    ft_printf("The message is recieved\n");
    exit(0);
}

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
        printf("%d\n", pid);
        signal(SIGUSR1, msg_recieve);
    }
    else
        return ((void)ft_printf("Valid format: ./client <PID> <Message>\n"), 1);
    return 0;
}