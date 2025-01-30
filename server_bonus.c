/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hajmoham <hajmoham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 18:33:19 by hajmoham          #+#    #+#             */
/*   Updated: 2025/01/28 18:03:19 by hajmoham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void handle_signal(int sig)
{
    static char current_c;
    static int bit_count;

    if (sig == SIGUSR1)
        current_c |= (1 << bit_count);
    bit_count++;
    if (bit_count == 8)
    {
        if (current_c == '\0')
            ft_printf("\n");
        else
            ft_printf("%c", current_c);
        current_c = 0;
        bit_count = 0;
    }
}

int main(int ac, char **av)
{
    int pid;

    (void)av;
    
    if (ac != 1)
	{
		write(1, "type ./server to get the pid", 28);
		return (1);
	}
    pid = getpid();
    ft_printf("Server PID: %d\n", pid);
    signal(SIGUSR1, handle_signal);
    signal(SIGUSR2, handle_signal);
    while (1)
    {
        pause();
    }
    return 0;
}

